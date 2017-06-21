#include "header/connectdbdcl.h"
UserModel *connectDBdemo() {
  UserModel *userModel = new UserModel();
  QQmlEngine::setObjectOwnership(userModel, QQmlEngine::CppOwnership);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("library.db");
  if (!db.open()) {
    qDebug() << "Error opening database";
    return nullptr;
  }
  QSqlQuery query;
  query.exec("SELECT * FROM sqlite_master WHERE name ='book' and type='table'");
  if (query.size() == -1) {
    query.exec("CREATE TABLE if not exists user (id VARCHAR PRIMARY KEY,"
               "name VARCHAR,"
               "email VARCHAR,"
               "type VARCHAR)");
    query.exec("CREATE TABLE if not exists book (isbn VARCHAR PRIMARY KEY,"
               "bookName VARCHAR,"
               "author VARCHAR,"
               "publishDate VARCHAR,"
               "totalStock INTEGER,"
               "avaiStock INTEGER,"
               "borrowedNum INTEGER)");
    query.exec("CREATE TABLE if not exists trans (book VARCHAR,"
               "user VARCHAR,"
               "borrowDate VARCHAR)");
    query.exec("CREATE TABLE if not exists security (id VARCHAR PRIMARY "
               "KEY,password VARCHAR, type VARCHAR)");
  }
  std::vector<User *> tmpUserList;
  query.exec("select id, name, email, type from user");
  while (query.next()) {
    QString id = query.value(0).toString();
    QString name = query.value(1).toString();
    QString email = query.value(2).toString();
    QString type = query.value(3).toString();
    User *newUser = new User(id, "", QVariantList(), name, email, type);
    QQmlEngine::setObjectOwnership(newUser, QQmlEngine::CppOwnership);
    userModel->append(newUser);
    tmpUserList.push_back(newUser);
  }
  std::vector<Book *> tmpBookList;
  query.exec("select isbn, bookName, author, publishDate, totalStock/*, "
             "avaiStock, borrowedNum*/ from book");
  while (query.next()) {
    QString isbn = query.value(0).toString();
    QString bookName = query.value(1).toString();
    QString author = query.value(2).toString();
    QString publishDate = query.value(3).toString();
    int totalStock = query.value(4).toInt();
    //        int avaiStock = query.value(5).toInt();
    //        int borrowedNum = query.value(6).toInt();
    Book *newBook =
        new Book(isbn, 0, bookName, QVariantList(), QVariantList(), author,
                 QDate::fromString(publishDate, "yyyy-MM-dd"), totalStock,
                 totalStock, totalStock);
    QQmlEngine::setObjectOwnership(newBook, QQmlEngine::CppOwnership);
    tmpBookList.push_back(newBook);
  }
  query.exec("select book, user, borrowDate from trans");
  while (query.next()) {
    QString bookIsbn = query.value(0).toString();
    QString userId = query.value(1).toString();
    QDate borrowDate =
        QDate::fromString(query.value(2).toString(), "yyyy-MM-dd");
    for (Book *pBook : tmpBookList) {
      if (pBook->isbn() == bookIsbn) {
        for (User *pUser : tmpUserList) {
          if (pUser->id() == userId) {
            pBook->bookOutTo(pUser, borrowDate);
          }
        }
      }
    }
  }
  for (auto pUser : tmpUserList)
    if (pUser->id() == "virutalUser_AllBooks")
      userModel->setCurrentControlUser(pUser);
  return userModel;
}

QVariantList connectSecurityDemo() {
  QVariantList ret;
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("library.db");
  if (!db.open()) {
    qDebug() << "Error opening database";
    return ret;
  }
  QSqlQuery query;
  query.exec("select id, password, type from security");
  while (query.next()) {
    QVariantHash term;
    term.insert("username", query.value(0).toString());
    term.insert("password", query.value(1).toString());
    term.insert("type", query.value(2).toString());
    ret << term;
  }
  return ret;
}
//    QVariantHash a;
//    a.insert("useranme", "user1");
//    a.insert("password", "user1");
//    a.insert("type", "user");
//    db << a;
//    a.clear();
//    a.insert("useranme", "user2");
//    a.insert("password", "user2");
//    a.insert("type", "admin");
//    db << a;
