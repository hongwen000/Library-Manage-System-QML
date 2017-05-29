#ifndef USERMODELBLL_H
#define USERMODELBLL_H
#include <QModelIndex>
#include <QAbstractListModel>
#include <QJsonValueRef>
#include <QDebug>
#include <QVariant>
#include <QQmlListProperty>
#include <qqml.h>
#include <QObject>
#include "userbll.h"
#include "bookbll.h"
#include "searchbll.h"
class UserModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(User* currentControlUser READ currentControlUser WRITE setCurrentControlUser NOTIFY currentControlUserChanged)
    Q_PROPERTY(Searcher searcher READ searcher WRITE setSearcher NOTIFY searcherChanged)
    Q_PROPERTY(QQmlListProperty<User> userList READ userList NOTIFY userListChanged)
public:
    //Model Role Property
    enum UserModelRole {
        UserListRole,
        CurrentUserRole,
        RecordRole
    };
    Q_ENUM(UserModelRole)

    //Overload Virtual Functions in QAbstractListModel
    UserModel(QObject *parent = nullptr){
        Q_UNUSED(parent);
    }

    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(User* user);
    Q_INVOKABLE void set(int row, User* user);
    Q_INVOKABLE void remove(int row);

    //Property handlers in qml
    User *currentControlUser() const;
    void setCurrentControlUser(User *r);

    Searcher searcher() const;
    void setSearcher(const Searcher&);

    QQmlListProperty<User> userList() {
        return QQmlListProperty<User>(this, m_users);
    }

signals:
    void currentControlUserChanged();
    void searcherChanged();
    void userListChanged();
public slots:


private:
    QList<User*> m_users;
    User *m_currentControlUser;
    Searcher m_searcher;
};
#endif // USERMODELBLL_H
