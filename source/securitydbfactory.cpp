#include "header/securitydbfactory.h"
#include <QCoreApplication>

shared_ptr<db> securityDBFactory::createDB()
{
    //����DB��������µ�DB��������ͷ
    shared_ptr<QSqlDatabase> pDB = make_shared<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE", "security"));

    pDB->setDatabaseName(dir == "" ? QCoreApplication::applicationDirPath() + "/security.db" : dir);
    //pDB->setDatabaseName("security.db");
    if (!pDB->open()) {
        qDebug() << "Error opening library database";
        QCoreApplication::quit();
        return nullptr;
    }
    QSqlQuery query(*pDB);
    query.exec("CREATE TABLE if not exists security (id VARCHAR PRIMARY KEY,password VARCHAR, type VARCHAR)");
    shared_ptr<securityDB> secDB = make_shared<securityDB>(pDB);
    return secDB;
}
