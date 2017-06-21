#include "header/securitydbfactory.h"
#include <QCoreApplication>
#include <fstream>
shared_ptr<db> securityDBFactory::createDB() {
  //生产DB，如果是新的DB，产生表头
  shared_ptr<QSqlDatabase> pDB = make_shared<QSqlDatabase>(
      QSqlDatabase::addDatabase("QSQLITE", "security"));

  pDB->setDatabaseName(dir == ""
                           ? QCoreApplication::applicationDirPath() + "/db/" +
                                 "/security.db"
                           : dir);
  // pDB->setDatabaseName("security.db");
  if (!pDB->open()) {
    qDebug() << "Error opening library database";
    std::ofstream log;
    log.open("error.log");
    log << "Error opening library database";
    log.close();
    throw std::domain_error("Error opening library database");
    return nullptr;
  }
  QSqlQuery query(*pDB);
  query.exec("CREATE TABLE if not exists security (id VARCHAR PRIMARY "
             "KEY,password VARCHAR, type VARCHAR)");
  shared_ptr<securityDB> secDB = make_shared<securityDB>(pDB);
  return secDB;
}
