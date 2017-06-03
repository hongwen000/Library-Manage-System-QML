#ifndef USERBLL_H
#define USERBLL_H
#include <QObject>
#include <QVariantList>
#include "universaltool.h"
#include <QDebug>
class Book;
class User: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QVariantList record READ record WRITE setRecord NOTIFY recordChanged)

public:
    User(const QString &_id = "", const QString &_password ="", const QVariantList& _record = QVariantList(), const QString& _name = "", const QString& _email ="",
         const QString &_type = "user")
    : m_id(_id),m_password(_password), m_record(_record), m_name(_name), m_email(_email), m_type(_type){
//        this->setProperty("id",_id);
//        this->setProperty("password",_password);
//        this->setProperty("name", _name);
//        this->setProperty("email", _email);
//        this->setProperty("type", _type);
//        this->setProperty("record",_record);
    }
    User(const User& rhs) {
        m_id       =rhs.m_id      ;
        m_password =rhs.m_password;
        m_name     =rhs.m_name    ;
        m_email    =rhs.m_email   ;
        m_type    =rhs.m_type   ;
        m_record   =rhs.m_record  ;
    }

    ~User(){
        qDebug() << "I am desturcted, help";
    }
    DEF_PROPERTY_IMPL(QString, id, Id)
    DEF_PROPERTY_IMPL(QString, password,Password)
    DEF_PROPERTY_IMPL(QString, name, Name)
    DEF_PROPERTY_IMPL(QString, email, Email)
    DEF_PROPERTY_IMPL(QString, type, Type)
    DEF_PROPERTY_IMPL(QVariantList, record, Record)
    Q_INVOKABLE void borrowBook(Book* _book);
    Q_INVOKABLE void returnBook(Book* _book);

signals:
    void idChanged();
    void passwordChanged();
    void recordChanged();
    void nameChanged();
    void emailChanged();
    void typeChanged();
private:
    QString m_id;
    QString m_password;
    QString m_name;
    QString m_email;
    QString m_type;
    QVariantList m_record;


};
Q_DECLARE_METATYPE(User)
#endif // USERBLL_H
