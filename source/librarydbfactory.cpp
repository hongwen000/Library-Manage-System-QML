#include "header/librarydbfactory.h"

shared_ptr<db> libraryDBFactory::createDB()
{
    //生产DB，如果是新的DB，产生表头
    shared_ptr<QSqlDatabase> pDB = make_shared<QSqlDatabase>(QSqlDatabase::addDatabase("QMYSQL", "librarydb"));
    pDB->setDatabaseName(dir + "library.db");
    if (!pDB->open()) {
        qDebug() << "Error opening library database";
        return nullptr;
    }
    QSqlQuery query(*pDB);
    query.exec("SELECT * FROM sqlite_master WHERE name ='book' and type='table'");
    if(query.size() == -1) {
        query.exec("CREATE TABLE if not exists user (id VARCHAR PRIMARY KEY,"
                   "name VARCHAR,"
                   "email VARCHAR,"
                   "type VARCHAR)");
        query.exec("CREATE TABLE if not exists book (isbn VARCHAR PRIMARY KEY,"
                   "bookName VARCHAR,"
                   "author VARCHAR,"
                   "publishDate VARCHAR,"
                   "totalStock INTEGER,"
                   "avaiStock INTEGER,"
                   "borrowedNum INTEGER)");
        query.exec("CREATE TABLE if not exists trans (book VARCHAR,"
                   "user VARCHAR,"
                   "borrowDate VARCHAR)");
    }
    shared_ptr<libraryDB> libDB = make_shared<libraryDB>(pDB);
    return libDB;
}
