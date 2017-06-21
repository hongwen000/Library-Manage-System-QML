#include "header/db.h"

db::db(shared_ptr<QSqlDatabase> _pDB) : pDB(_pDB) {}

db::~db() {}

QVariantHash db::get() { return QVariantHash(); }

void db::borrowBookDCL(const QString &book, const QString &user, const QString &borrowDate, int avaiStock, int borrowedNum) {
    (book);
    (user);
    (borrowDate);
    (avaiStock);
    (borrowDate);
    (borrowedNum);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::returnBookDCL(const QString &book, const QString &user, int avaiStock, int borrowedNum) {
    (book);
    (user);
    (avaiStock);
    (borrowedNum);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::addUserToDb(const QString &_id, const QString &_name, const QString &_email, const QString &_type) {
    (_id);
    (_name);
    (_email);
    (_type);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::editUserToDb(const QString &_id, const QString &_name, const QString &_email, const QString &_type) {
    (_id);
    (_name);
    (_email);
    (_type);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::removeUserToDb(const QString &_id) {
    (_id);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::addBookDCL(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QString &_publishDate) {
    (_bookName);
    (_author);
    (_isbn);
    (_totalStock);
    (_publishDate);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::editBookDCL(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock) {
    (_bookName);
    (_author);
    (_totalStock);
    (_publishDate);
    (_avaiStock);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::removeBookDCL(const QString &_isbn) {
    (_isbn);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::addUserToSecurityDb(const QString &_id, const QString &_password, const QString &_type) {
    (_id);
    (_password);
    (_type);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::editUserToSecurityDb(const QString &_id, const QString &_password, const QString &_type) {
    (_id);
    (_password);
    (_type);
    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}

void db::removeUserToSecurityDb(const QString &_id) {
    (_id);

    qCritical()
            << "DB type error! Please make sure it's a library db or security db";
}
