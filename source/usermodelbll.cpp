#include "header/usermodelbll.h"
#include "header/userbll.h"
#include "header/updatedbdcl.h"
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

User* UserModel::find(const QString &rhs)
{
    for(auto i : m_users) {
        if(i->id() == rhs)
            return i;
    }
    return 0;
}

void UserModel::addUser(const QString &_id, const QString &_name, const QString &_password, const QString& _email, const QString& _type)
{
    User* newUser = new User(_id, _password, QVariantList(), _name, _email, _type);
    QQmlEngine::setObjectOwnership(newUser, QQmlEngine::CppOwnership);
    append(newUser);
    emit userListChanged();
    addUserDCL(_id,_name,_password,_email,_type);
}

void UserModel::editUser(User *record, const QString &_name, const QString &_password, const QString &_email, const QString& _type)
{
    record->setName(_name);
    record->setPassword(_password);
    record->setEmail(_email);
    record->setType(_type);
    editUserDCL(record->id(),_name,_password,_email,_type);
}

void UserModel::removeUser(User *record)
{
    for(int i = 0; i < m_users.count(); ++i) {
        if(record == m_users[i]) {
            for(QVariant bookBorrowed : record->record())
                qvariant_cast<Book*>(bookBorrowed)->bookReturnIn(record);
            removeUserDCL(record->id());
            remove(i);
        }
    }
}

void UserModel::addBook(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QDate &_publishTime)
{
    User* pvirutalUser_AllBooks = find("virutalUser_AllBooks");
    Book* newBook = new Book(_isbn, 0, _bookName, QVariantList(), QVariantList(), _author,_publishTime, _totalStock, _totalStock, 0);
    QQmlEngine::setObjectOwnership(newBook, QQmlEngine::CppOwnership);
    addBookDCL(_bookName,_author,_isbn,_totalStock,_publishTime.toString("yyyy-MM-dd"));
    newBook->bookOutTo(pvirutalUser_AllBooks);
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
