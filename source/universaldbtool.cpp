#include "header/universaldbtool.h"

void borrowBookDCL(const QString &book, const QString &user,
                   const QString &borrowDate, int avaiStock, int borrowedNum) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  libDB->borrowBookDCL(book, user, borrowDate, avaiStock, borrowedNum);
}

void returnBookDCL(const QString &book, const QString &user, int avaiStock,
                   int borrowedNum) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  libDB->returnBookDCL(book, user, avaiStock, borrowedNum);
}

void addUserDCL(const QString &_id, const QString &_name,
                const QString &_password, const QString &_email,
                const QString &_type) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  shared_ptr<dbFactory> secFc = make_shared<securityDBFactory>();
  shared_ptr<db> secDB = secFc->createDB();
  libDB->addUserToDb(_id, _name, _email, _type);
  secDB->addUserToSecurityDb(_id, _password, _type);
}

void editUserDCL(const QString &_id, const QString &_name,
                 const QString &_password, const QString &_email,
                 const QString &_type) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  shared_ptr<dbFactory> secFc = make_shared<securityDBFactory>();
  shared_ptr<db> secDB = secFc->createDB();
  libDB->editUserToDb(_id, _name, _email, _type);
  secDB->editUserToSecurityDb(_id, _password, _type);
}

void removeUserDCL(const QString &_id) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  shared_ptr<dbFactory> secFc = make_shared<securityDBFactory>();
  shared_ptr<db> secDB = secFc->createDB();
  libDB->removeUserToDb(_id);
  secDB->removeUserToSecurityDb(_id);
}

void addBookDCL(const QString &_bookName, const QString &_author,
                const QString &_isbn, int _totalStock,
                const QString &_publishDate) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  libDB->addBookDCL(_bookName, _author, _isbn, _totalStock, _publishDate);
}

void editBookDCL(const QString &_bookName, const QString &_author,
                 const QDate &_publishDate, int _totalStock, int _avaiStock) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  libDB->editBookDCL(_bookName, _author, _publishDate, _totalStock, _avaiStock);
}

void removeBookDCL(const QString &_isbn) {
  shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
  shared_ptr<db> libDB = libFc->createDB();
  libDB->removeBookDCL(_isbn);
}
