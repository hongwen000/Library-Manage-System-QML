#ifndef LIBRARYDB_H
#define LIBRARYDB_H
#include "header/db.h"
#include <QDate>
class libraryDB : public db
{
public:
    libraryDB(shared_ptr<QSqlDatabase> _pDB);
    QVariantHash get() override;
};
#endif // LIBRARYDB_H
