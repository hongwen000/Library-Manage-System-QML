﻿#ifndef USERMODELBLL_H
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
    Q_PROPERTY(QString searcher READ searcher WRITE setSearcher NOTIFY searcherChanged)
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
        connect(this,SIGNAL(searcherChanged()),this,SLOT(onSearcherChanged()));
    }

    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(User* user);
    Q_INVOKABLE void set(int row, User* user);
    Q_INVOKABLE void remove(int row);
    Q_INVOKABLE int find(const QString&);
    Q_INVOKABLE QVariant at(int n);
    //Property handlers in qml
    User *currentControlUser() const;
    void setCurrentControlUser(User *r);
    Q_INVOKABLE void setCurrentControlUser(const QString&);
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
