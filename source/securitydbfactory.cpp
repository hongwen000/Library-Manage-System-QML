#include "header/securitydbfactory.h"
shared_ptr<db> securityDBFactory::createDB()
{
    //����DB��������µ�DB��������ͷ
    shared_ptr<QSqlDatabase> pDB = make_shared<QSqlDatabase>(QSqlDatabase::addDatabase("QMYSQL", "security"));
    pDB->setDatabaseName(dir + "security.db");
    if (!pDB->open()) {
        qDebug() << "Error opening library database";
        return nullptr;
    }
    QSqlQuery query(*pDB);
    query.exec("SELECT * FROM sqlite_master WHERE name ='security' and type='table'");
    if(query.size() == -1) {
        query.exec("CREATE TABLE if not exists security (id VARCHAR PRIMARY KEY,password VARCHAR, type VARCHAR)");
    }
    shared_ptr<securityDB> secDB = make_shared<securityDB>(pDB);
    return secDB;
}
