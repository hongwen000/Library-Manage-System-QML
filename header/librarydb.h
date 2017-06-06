#ifndef LIBRARYDB_H
#define LIBRARYDB_H
#include "header/db.h"
#include <QDate>

class libraryDB : public db
{
public:
    libraryDB(shared_ptr<QSqlDatabase> _pDB);
    QVariantHash get() override;
    void borrowBookDCL(const QString& book, const QString& user, const QString& borrowDate, int avaiStock, int borrowedNum) override;
    void returnBookDCL(const QString& book, const QString& user, int avaiStock, int borrowedNum) override;
    void addUserToDb(const QString &_id, const QString &_name, const QString& _email, const QString& _type) override;
    void editUserToDb(const QString &_id, const QString &_name, const QString& _email, const QString& _type) override;
    void removeUserToDb(const QString &_id) override;
    void addBookDCL(const QString &_bookName, const QString &_author, const QString &_isbn, int _totalStock, const QString &_publishDate) override;
    void editBookDCL(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock) override;
    void removeBookDCL(const QString &_isbn) override;
};
#endif // LIBRARYDB_H
