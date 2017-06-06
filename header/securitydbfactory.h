#ifndef SECURITYDBFACTORY_H
#define SECURITYDBFACTORY_H
#include "header/dbfactory.h"
#include "header/securitydb.h"

class securityDBFactory : public dbFactory
{
public:
    securityDBFactory() {}
    shared_ptr<db> createDB() override;
};
#endif // SECURITYDBFACTORY_H
