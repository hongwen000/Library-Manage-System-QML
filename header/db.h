#ifndef DB_H
#define DB_H
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <memory>
#pragma  GCC diagnostic ignored "-Wunused-value"
using std::shared_ptr;
using std::make_shared;
class db {
public:
  db(shared_ptr<QSqlDatabase> _pDB);
  virtual ~db();
  virtual QVariantHash get();
  virtual void borrowBookDCL(const QString &book, const QString &user,
                             const QString &borrowDate, int avaiStock,
                             int borrowedNum);

  virtual void returnBookDCL(const QString &book, const QString &user,
                             int avaiStock, int borrowedNum);
  virtual void addUserToDb(const QString &_id, const QString &_name,
                           const QString &_email, const QString &_type);
  virtual void editUserToDb(const QString &_id, const QString &_name,
                            const QString &_email, const QString &_type);
  virtual void removeUserToDb(const QString &_id);
  virtual void addBookDCL(const QString &_bookName, const QString &_author,
                          const QString &_isbn, int _totalStock,
                          const QString &_publishDate);
  virtual void editBookDCL(const QString &_bookName, const QString &_author,
                           const QDate &_publishDate, int _totalStock,
                           int _avaiStock);
  virtual void removeBookDCL(const QString &_isbn);
  virtual void addUserToSecurityDb(const QString &_id, const QString &_password,
                                   const QString &_type);
  virtual void editUserToSecurityDb(const QString &_id,
                                    const QString &_password,
                                    const QString &_type);
  virtual void removeUserToSecurityDb(const QString &_id);

protected:
  shared_ptr<QSqlDatabase> pDB;
};
#endif // DB_H
