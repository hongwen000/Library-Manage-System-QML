#ifndef SECURITYDB_H
#define SECURITYDB_H
#include "header/db.h"

class securityDB : public db
{
public:
    securityDB(shared_ptr<QSqlDatabase> _pDB);
    QVariantHash get() override;
};
#endif // SECURITYDB_H
