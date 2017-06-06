#include "header/librarydb.h"

libraryDB::libraryDB(shared_ptr<QSqlDatabase> _pDB) : db(_pDB)
{

}

QVariantHash libraryDB::get()
{
    QVariantHash ret;
    QVariantList table;
    QSqlQuery query(*pDB);
    query.exec("select id, name, email, type from user");
    while(query.next()) {
        QVariantHash term;
        term.insert("id", query.value(0).toString());
        term.insert("name", query.value(1).toString());
        term.insert("email", query.value(2).toString());
        term.insert("type", query.value(3).toString());
        table << term;
    }
    ret.insert("user", table);
    table.clear();
    query.exec("select isbn, bookName, author, publishDate, totalStock from book");
    while (query.next()) {
        QVariantHash term;
        term.insert("isbn", query.value(0).toString());
        term.insert("bookName",query.value(1).toString());
        term.insert("author",query.value(2).toString());
        term.insert("publishDate",query.value(3).toString());
        term.insert("totalStock", query.value(4).toInt());
        table << term;
    }
    ret.insert("book",table);
    table.clear();
    query.exec("select book, user, borrowDate from trans");
    while (query.next()) {
        QVariantHash term;
        term.insert("bookIsbn", query.value(0).toString());
        term.insert("userId", query.value(1).toString());
        term.insert("borrowDate", QDate::fromString(query.value(2).toString(),"yyyy-MM-dd"));
        table << term;
    }
    ret.insert("trans",table);
    return ret;
}

void libraryDB::borrowBookDCL(const QString &book, const QString &user, const QString &borrowDate, int avaiStock, int borrowedNum)
{
    QSqlQuery query(*pDB);
    query.prepare("insert into trans (book, user, borrowDate) values (?, ?, ?)");
    query.addBindValue(book);
    query.addBindValue(user);
    query.addBindValue(borrowDate);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when inserting new trans";
    }
    query.clear();
    query.prepare("update book set avaiStock = ?, borrowedNum = ? where isbn = ?");
    query.addBindValue(avaiStock);
    query.addBindValue(borrowedNum);
    query.addBindValue(book);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when changing book borrowed and then borrowed number";
    }
    qDebug() << pDB->lastError().databaseText();
}

void libraryDB::returnBookDCL(const QString &book, const QString &user, int avaiStock, int borrowedNum)
{
    QSqlQuery query(*pDB);
    query.prepare("delete from trans where book = ? AND user = ?");
    query.addBindValue(book);
    query.addBindValue(user);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when deleting old trans";
    }
    query.clear();
    query.prepare("update book set avaiStock = ?, borrowedNum = ? where isbn = ?");
    query.addBindValue(avaiStock);
    query.addBindValue(borrowedNum);
    query.addBindValue(book);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when changing book borrowed and then borrowed number";
    }
}

void libraryDB::addUserToDb(const QString &_id, const QString &_name, const QString &_email, const QString &_type)
{
    QSqlQuery query(*pDB);
    query.prepare("insert into user(id, name, email, type) values (?, ?, ?, ?)");
    query.addBindValue(_id);
    query.addBindValue(_name);
    query.addBindValue(_email);
    query.addBindValue(_type);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when adding new user";
    }
}

void libraryDB::editUserToDb(const QString &_id, const QString &_name, const QString &_email, const QString &_type)
{
    QSqlQuery query(*pDB);
    query.prepare("update user set name = ?, email = ?, type = ? where id = ?");
    query.addBindValue(_name);
    query.addBindValue(_email);
    query.addBindValue(_type);
    query.addBindValue(_id);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when editing user";
    }
}

void libraryDB::removeUserToDb(const QString &_id)
{
    QSqlQuery query(*pDB);
    query.prepare("delete from user where id = ?");
    query.addBindValue(_id);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when deleting user";
    }
}

void libraryDB::addBookDCL(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QString &_publishDate)
{
    QSqlQuery query(*pDB);
    query.prepare("insert into book(isbn, bookName, author, publishDate, totalStock, avaiStock, borrowedNum) values (?, ?, ?, ?, ?, ?, 0)");
    query.addBindValue(_isbn);
    query.addBindValue(_bookName);
    query.addBindValue(_author);
    query.addBindValue(_publishDate);
    query.addBindValue(_totalStock);
    query.addBindValue(_totalStock);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when adding new book";
    }
}

void libraryDB::editBookDCL(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock)
{
    QSqlQuery query(*pDB);
    query.prepare("update book set bookName = ?, author = ?, publishDate = ?, totalStock = ?, avaiStock = ?, borrowedNum = ?  where id = ?");
    query.addBindValue(_bookName);
    query.addBindValue(_author);
    query.addBindValue(_publishDate);
    query.addBindValue(_totalStock);
    query.addBindValue(_avaiStock);
    query.addBindValue(_totalStock - _avaiStock);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when editing book";
    }
}

void libraryDB::removeBookDCL(const QString &_isbn)
{
    QSqlQuery query(*pDB);
    query.prepare("delete from book where isbn = ?");
    query.addBindValue(_isbn);
    if (!query.exec()) {
        qDebug() << "Error Writing DataBase when deleting book";
    }
}

