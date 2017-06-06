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
#include <QQmlEngine>
#include <memory>
#include <vector>
#include "userbll.h"
#include "bookbll.h"
#include "searchbll.h"
class UserModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(User* currentControlUser READ currentControlUser WRITE setCurrentControlUser NOTIFY currentControlUserChanged)
    Q_PROPERTY(QString searcher READ searcher WRITE setSearcher NOTIFY searcherChanged)
    Q_PROPERTY(QQmlListProperty<User> userList READ userList NOTIFY userListChanged)
public:
    void initial(const QVariantHash &libDB);
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
        connect(this,SIGNAL(searcherChanged()),this,SLOT(onSearcherChanged()));
    }
    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(User* user);
    Q_INVOKABLE void set(int row, User* user);
    Q_INVOKABLE void remove(int row);
    //Interface about User for qml
    Q_INVOKABLE User* findUser(const QString&);
    Q_INVOKABLE void addUser(const QString &_id = "",  const QString& _name = "", const QString &_password ="", const QString& _email ="", const QString& _type = "user");
    Q_INVOKABLE void editUser(User* record,  const QString& _name = "", const QString &_password ="", const QString& _email ="", const QString& _type = "user");
    Q_INVOKABLE void setCurrentControlUser(const QString&);
    Q_INVOKABLE void removeUser(User* record);
    //Interface about Book for qml
    Q_INVOKABLE void addBook(const QString& _bookName, const QString& _author, const QString& _isbn, int _totalStock, const QDate& _publishTime);
    Q_INVOKABLE void bookOutTo(Book* book, User* user);
    Q_INVOKABLE void bookReturnIn(Book* book, User* user);
    Q_INVOKABLE bool alreadyBorrowed(Book* book, User* user);
    Q_INVOKABLE int findBorrowerIndex(Book* book, User* user);
    Q_INVOKABLE void deleteBook(Book* book);
    Q_INVOKABLE void editBook(Book* book, const QString& _bookName, const QString& _author, const QDate& _publishDate, int _totalStock, int _avaiStock);
    //Properties available in qml
    User *currentControlUser() const;
    void setCurrentControlUser(User *r);
    QString searcher() const;
    void setSearcher(const QString&);
    QQmlListProperty<User> userList() {
        return QQmlListProperty<User>(this, m_users);
    }


signals:
    void currentControlUserChanged();
    Q_INVOKABLE void searcherChanged();
    void userListChanged();
public slots:
    void onSearcherChanged();

private:
    QList<User*> m_users;
    User *m_currentControlUser;
    QString m_searcher;
    User *searcherBackup = nullptr;
};
#endif // USERMODELBLL_H
