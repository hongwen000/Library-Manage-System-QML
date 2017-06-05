#include "header/updatedbdcl.h"
#include <QSqlError>
void borrowBookDCL(const QString &book, const QString &user, const QString &borrowDate, int avaiStock, int borrowedNum)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("insert into trans (book, user, borrowDate) values (?, ?, ?)");
    query.addBindValue(book);
    query.addBindValue(user);
    query.addBindValue(borrowDate);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when inserting new trans";
    }
    query.clear();
    query.prepare("update book set avaiStock = ?, borrowedNum = ? where isbn = ?");
    query.addBindValue(avaiStock);
    query.addBindValue(borrowedNum);
    query.addBindValue(book);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when changing book borrowed and then borrowed number";
    }
    //query.finish();
    //if(!db.commit()) qInfo() << "DataBase Commit Error";
    qInfo() << db.lastError().databaseText();
}

void returnBookDCL(const QString &book, const QString &user, int avaiStock, int borrowedNum)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("delete from trans where book = ? AND user = ?");
    query.addBindValue(book);
    query.addBindValue(user);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when deleting old trans";
    }
    query.clear();
    query.prepare("update book set avaiStock = ?, borrowedNum = ? where isbn = ?");
    query.addBindValue(avaiStock);
    query.addBindValue(borrowedNum);
    query.addBindValue(book);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when changing book borrowed and then borrowed number";
    }

}



void addUserToSecurityDb(const QString &_id, const QString &_password, const QString &_type)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return ;
    }
    QSqlQuery query;
    query.prepare("insert into security(id, password, type) values(?, ?, ?)");
    query.addBindValue(_id);
    query.addBindValue(_password);
    query.addBindValue(_type);
    if (!query.exec()) {
        qInfo() << "Error Writing Securtiy DataBase when adding new user";
    }

}



void editUserToDb(const QString &_id, const QString &_name, const QString &_email, const QString &_type)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("update user set name = ?, email = ?, type = ? where id = ?");
    query.addBindValue(_name);
    query.addBindValue(_email);
    query.addBindValue(_type);
    query.addBindValue(_id);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when editing user";
    }

}

void addUserToDb(const QString &_id, const QString &_name, const QString &_email, const QString &_type)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("insert into user(id, name, email, type) values (?, ?, ?, ?)");
    query.addBindValue(_id);
    query.addBindValue(_name);
    query.addBindValue(_email);
    query.addBindValue(_type);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when adding new user";
    }

}

void addUserDCL(const QString &_id, const QString &_name, const QString &_password, const QString &_email, const QString &_type)
{
    addUserToDb(_id,_name,_email,_type);
    addUserToSecurityDb(_id,_password,_type);
}

void editUserToSecurityDb(const QString &_id, const QString &_password, const QString &_type)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return ;
    }
    QSqlQuery query;
    if(_password != "") {
        query.prepare("update security set password = ?, type = ? where id = ?");
        query.addBindValue(_password);
    }
    else {
        query.prepare("update security set type = ? where id = ?");

    }
    query.addBindValue(_type);
    query.addBindValue(_id);
    if (!query.exec()) {
        qInfo() << "Error Writing Securtiy DataBase when editing user";
    }

}

void editUserDCL(const QString &_id, const QString &_name, const QString &_password, const QString &_email, const QString &_type)
{
    editUserToDb(_id,_name,_email,_type);
    editUserToSecurityDb(_id,_password,_type);
}

void removeUserToDb(const QString &_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("delete from user where id = ?");
    query.addBindValue(_id);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when deleting user";
    }


}

void removeUserToSecurityDb(const QString &_id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return ;
    }
    QSqlQuery query;
    query.prepare("delete from security where id = ?");
    query.addBindValue(_id);
    if (!query.exec()) {
        qInfo() << "Error Writing Securtiy DataBase when removing user";
    }


}

void removeUserDCL(const QString &_id)
{
    removeUserToDb(_id);
    removeUserToSecurityDb(_id);
}

void addBookDCL(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QString &_publishDate)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("insert into book(isbn, bookName, author, publishDate, totalStock, avaiStock, borrowedNum) values (?, ?, ?, ?, ?, ?, 0)");
    query.addBindValue(_isbn);
    query.addBindValue(_bookName);
    query.addBindValue(_author);
    query.addBindValue(_publishDate);
    query.addBindValue(_totalStock);
    query.addBindValue(_totalStock);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when adding new book";
    }


}

void removeBookDCL(const QString &_isbn)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("delete from book where isbn = ?");
    query.addBindValue(_isbn);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when deleting book";
    }


}

void editBookDCL(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("library.db");
    if (!db.open()) {
        qInfo() << "Error opening database";
        return;
    }
    QSqlQuery query;
    query.prepare("update book set bookName = ?, author = ?, publishDate = ?, totalStock = ?, avaiStock = ?, borrowedNum = ?  where id = ?");
    query.addBindValue(_bookName);
    query.addBindValue(_author);
    query.addBindValue(_publishDate);
    query.addBindValue(_totalStock);
    query.addBindValue(_avaiStock);
    query.addBindValue(_totalStock - _avaiStock);
    if (!query.exec()) {
        qInfo() << "Error Writing DataBase when editing book";
    }


}
