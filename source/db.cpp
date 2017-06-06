#include "header/db.h"

db::db(shared_ptr<QSqlDatabase> _pDB) : pDB(_pDB)
{

}

db::~db()
{

}

QVariantHash db::get()
{
    return QVariantHash();
}
