#ifndef UNIVERSALDBTOOL_H
#define UNIVERSALDBTOOL_H
#include "header/db.h"
#include "header/librarydb.h"
#include "header/librarydbfactory.h"
#include "header/securitydb.h"
#include "header/securitydbfactory.h"
#include <QSqlError>
void borrowBookDCL(const QString& book, const QString& user, const QString& borrowDate, int avaiStock, int borrowedNum);

void returnBookDCL(const QString& book, const QString& user, int avaiStock, int borrowedNum);

void addUserDCL(const QString &_id, const QString &_name, const QString &_password, const QString& _email, const QString& _type);

void editUserDCL(const QString &_id, const QString &_name, const QString &_password, const QString& _email, const QString& _type);

void removeUserDCL(const QString &_id);

void addBookDCL(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QString &_publishDate);

void editBookDCL(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock);

void removeBookDCL(const QString &_isbn);

#endif // UNIVERSALDBTOOL_H
