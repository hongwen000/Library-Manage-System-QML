#include "header/usermodelbll.h"
#include "header/userbll.h"
#include <QDebug>
int UserModel::rowCount(const QModelIndex & /*parent*/) const
{
   return m_users.count();
}

QVariant UserModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < rowCount())
        switch(role){
        case UserListRole: return QVariant::fromValue(m_users);
        case CurrentUserRole: return QVariant::fromValue(*currentControlUser());
        case RecordRole: return m_users.at(index.row())->record();
        default: return QVariant();
        }
    return QVariant();
}

QHash<int, QByteArray> UserModel::roleNames() const
{
    static const QHash<int, QByteArray> roles{
        {UserListRole, "userList"},
        {CurrentUserRole, "currentUser"},
        {RecordRole, "record"}
    };
    return roles;
}

QVariantMap UserModel::get(int row) const
{
    const User* user = m_users.value(row);
    return { {"user", QVariant::fromValue(*user)},
            {"record", user->record()}};
}

void UserModel::append(User* user)
{
    int row = m_users.count();
    beginInsertRows(QModelIndex(), row, row);
    m_users.append(user);
    endInsertRows();
}

void UserModel::set(int row, User* user)
{
    if (row < 0 || row >= m_users.count())
        return;

    m_users.replace(row, user);
    dataChanged(index(row, 0), index(row, 0), {UserListRole, CurrentUserRole, RecordRole});
}

void UserModel::remove(int row)
{
    if (row < 0 || row >= m_users.count())
        return;

    beginRemoveRows(QModelIndex(), row, row);
    m_users.removeAt(row);
    endRemoveRows();
}

int UserModel::find(const QString &rhs)
{
    for(auto it = m_users.begin(); it != m_users.end(); ++it) {
        if((*it)->id() == rhs)
            return it - m_users.begin();
    }
    return -1;
}

 QVariant UserModel::at(int n)
{
    return QVariant::fromValue(m_users[n]);
}

User* UserModel::currentControlUser() const
{
    return m_currentControlUser;
}

void UserModel::setCurrentControlUser(User *r)
{
    qInfo() <<"Now it's me" << r->id();
    m_currentControlUser = r;
    emit currentControlUserChanged();
}

void UserModel::setCurrentControlUser(const QString &rhs)
{
    for(auto i : m_users) {
        if(i->id() == rhs) {
            setCurrentControlUser(i);
        }
    }
}

QString UserModel::searcher() const
{
    return m_searcher;
}

void UserModel::setSearcher(const QString & r)
{
    m_searcher = r;
}

void UserModel::onSearcherChanged()
{
    qDebug() << "Searcher changed slot is trigged";
    if(m_searcher == "") {
        if(searcherBackup != nullptr){
            qDebug() << "Searcher changed slot setCurrentControlUser to " << searcherBackup;
            setCurrentControlUser(searcherBackup);
            searcherBackup = nullptr;
            emit currentControlUserChanged();
        }
    }
    else {
        if(searcherBackup == nullptr) {
            searcherBackup = m_currentControlUser;
        }
        User* tmpusr = new User();
        QVariantList tmpRecord;
        for(auto i: m_currentControlUser->record())
        {
            if((qvariant_cast<Book*>(i))->bookName().contains(m_searcher,Qt::CaseInsensitive)){
                tmpRecord << i;
            }
        }
        tmpusr->setRecord(tmpRecord);
        m_currentControlUser = tmpusr;
        emit currentControlUserChanged();
    }
}
