#ifndef LIBRARYDBFACTORY_H
#define LIBRARYDBFACTORY_H
#include "header/dbfactory.h"
#include "header/librarydb.h"
#include <QSqlDatabase>
class libraryDBFactory : public dbFactory {
public:
  libraryDBFactory() {}
  shared_ptr<db> createDB() override;
};
#endif // LIBRARYDBFACTORY_H
