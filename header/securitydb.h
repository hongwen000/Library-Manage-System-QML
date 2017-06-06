#ifndef SECURITYDB_H
#define SECURITYDB_H
#include "header/db.h"

class securityDB : public db
{
public:
    securityDB(shared_ptr<QSqlDatabase> _pDB);
    QVariantHash get() override;
    void addUserToSecurityDb(const QString &_id, const QString &_password, const QString& _type);
    void editUserToSecurityDb(const QString &_id, const QString &_password, const QString& _type);
    void removeUserToSecurityDb(const QString &_id);
};
#endif // SECURITYDB_H
