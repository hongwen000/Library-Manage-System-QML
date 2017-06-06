#include "header/securitydb.h"

securityDB::securityDB(shared_ptr<QSqlDatabase> _pDB) : db(_pDB)
{

}

QVariantHash securityDB::get()
{
    QVariantHash ret;
    QVariantList table;
    QSqlQuery query(*pDB);
    query.exec("select id, password, type from security");
    while (query.next()) {
        QVariantHash term;
        term.insert("username", query.value(0).toString());
        term.insert("password", query.value(1).toString());
        term.insert("type", query.value(2).toString());
        table << term;
    }
    ret.insert("security", table);
    return ret;
}
