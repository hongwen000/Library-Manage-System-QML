#ifndef LIBRARYDBFACTORY_H
#define LIBRARYDBFACTORY_H
#include "header/dbfactory.h"
#include <QSqlDatabase>
#include "header/librarydb.h"
class libraryDBFactory :public dbFactory
{
public:
    libraryDBFactory () {}
    shared_ptr<db> createDB() override;
};
#endif // LIBRARYDBFACTORY_H
