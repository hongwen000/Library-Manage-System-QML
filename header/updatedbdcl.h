#ifndef UPDATEDBDCL_H
#define UPDATEDBDCL_H
#include <utility>
#include <tuple>
#include "header/usermodelbll.h"
#include <string>
#include <list>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <vector>
void borrowBookDCL(const QString& book, const QString& user, const QString& borrowDate, int avaiStock, int borrowedNum);

void returnBookDCL(const QString& book, const QString& user, int avaiStock, int borrowedNum);


void addUserToDb(const QString &_id, const QString &_name, const QString& _email, const QString& _type);

void addUserToSecurityDb(const QString &_id, const QString &_password, const QString& _type);

void addUserDCL(const QString &_id, const QString &_name, const QString &_password, const QString& _email, const QString& _type);

void editUserToDb(const QString &_id, const QString &_name, const QString& _email, const QString& _type);

void editUserToSecurityDb(const QString &_id, const QString &_password, const QString& _type);

void editUserDCL(const QString &_id, const QString &_name, const QString &_password, const QString& _email, const QString& _type);

void removeUserToDb(const QString &_id);

void removeUserToSecurityDb(const QString &_id);

void removeUserDCL(const QString &_id);

void addBookDCL(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QString &_publishDate);

void editBookDCL(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock);

void removeBookDCL(const QString &_isbn);

#endif // UPDATEDBDCL_H
