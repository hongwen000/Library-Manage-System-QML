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
    }
    ret.insert("trans",table);
    return ret;
}
