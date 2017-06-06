#ifndef DBFACTORY_H
#define DBFACTORY_H
#include "header/db.h"
#include <memory>
#include <QDebug>
#include <QSqlQuery>

using std::shared_ptr;
using std::make_shared;
class dbFactory {
public:
    dbFactory(const QString &_dir = "");
    virtual shared_ptr<db> createDB();
    virtual ~dbFactory();
protected:
    QString dir;
};

#endif // DBFACTORY_H
