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

void securityDB::addUserToSecurityDb(const QString &_id, const QString &_password, const QString &_type)
{
    QSqlQuery query(*pDB);
    query.prepare("insert into security(id, password, type) values(?, ?, ?)");
    query.addBindValue(_id);
    query.addBindValue(_password);
    query.addBindValue(_type);
    if (!query.exec()) {
        qDebug() << "Error Writing Securtiy DataBase when adding new user";
    }
}

void securityDB::editUserToSecurityDb(const QString &_id, const QString &_password, const QString &_type)
{
    QSqlQuery query(*pDB);
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
        qDebug() << "Error Writing Securtiy DataBase when editing user";
    }
}

void securityDB::removeUserToSecurityDb(const QString &_id)
{
    QSqlQuery query(*pDB);
    query.prepare("delete from security where id = ?");
    query.addBindValue(_id);
    if (!query.exec()) {
        qDebug() << "Error Writing Securtiy DataBase when removing user";
    }
}
