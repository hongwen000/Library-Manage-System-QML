#ifndef DB_H
#define DB_H
#include <QVariantList>
#include <QSqlDatabase>
#include <memory>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
using std::shared_ptr;
using std::make_shared;
class db
{
public:
    db(shared_ptr<QSqlDatabase> _pDB);
    virtual ~db();
    virtual QVariantHash get();
protected:
    shared_ptr<QSqlDatabase> pDB;
};
#endif // DB_H
