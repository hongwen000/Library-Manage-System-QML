#include "header/dbfactory.h"

dbFactory::dbFactory(const QString &_dir) : dir(_dir) {}

shared_ptr<db> dbFactory::createDB() { return nullptr; }

dbFactory::~dbFactory() {}
