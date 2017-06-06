#ifndef DB_H
#define DB_H
#include <QVariantList>
#include <QSqlDatabase>
#include <memory>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
using std::shared_ptr;
using std::make_shared;
class db
{
public:
    db(shared_ptr<QSqlDatabase> _pDB);
    virtual ~db();
    virtual QVariantHash get();
    virtual void borrowBookDCL(const QString& book, const QString& user, const QString& borrowDate, int avaiStock, int borrowedNum)
    {
        (book);
        (user);
        (borrowDate);
        (avaiStock);
        (borrowDate);
        (borrowedNum);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }

    virtual void returnBookDCL(const QString& book, const QString& user, int avaiStock, int borrowedNum)
    {
        (book);
        (user);
        (avaiStock);
        (borrowedNum);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void addUserToDb(const QString &_id, const QString &_name, const QString& _email, const QString& _type)
    {
        (_id);
        (_name);
        (_email);
        (_type);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void editUserToDb(const QString &_id, const QString &_name, const QString& _email, const QString& _type)
    {
        (_id);
        (_name);
        (_email);
        (_type);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void removeUserToDb(const QString &_id)
    {
        (_id);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void addBookDCL(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QString &_publishDate)
    {
        (_bookName);
        (_author);
        (_isbn);
        (_totalStock);
        (_publishDate);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void editBookDCL(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock)
    {
        (_bookName);
        (_author);
        (_totalStock);
        (_publishDate);
        (_avaiStock);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void removeBookDCL(const QString &_isbn)
    {
        (_isbn);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void addUserToSecurityDb(const QString &_id, const QString &_password, const QString& _type)
    {
        (_id);
        (_password);
        (_type);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void editUserToSecurityDb(const QString &_id, const QString &_password, const QString& _type)
    {
        (_id);
        (_password);
        (_type);
        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }
    virtual void removeUserToSecurityDb(const QString &_id)
    {
        (_id);

        qCritical() << "DB type error! Please make sure it's a library db or security db";
    }

protected:
    shared_ptr<QSqlDatabase> pDB;
};
#endif // DB_H
