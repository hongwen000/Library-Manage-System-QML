#ifndef DEMO_H
#define DEMO_H
#include <utility>
#include <tuple>
#include "header/usermodelbll.h"
#include <string>
#include <list>
#include <QDebug>
#include <QObject>
#include <QString>
//UserModel* connectDBdemo(){
//    User* virutalUser_AllBooks = new User("virutalUser_AllBooks");
//    User* user1 = new User("user1","user1",QVariantList(),"Li Xinrui","hongwen000@outlook.com","user");
//    User* user2 = new User("user2", "user2",QVariantList(),"Li Xinrui Admin","hongwen000@outlook.com","admin");
//    QQmlEngine::setObjectOwnership(user1, QQmlEngine::CppOwnership);
//    QQmlEngine::setObjectOwnership(user2, QQmlEngine::CppOwnership);
//    QQmlEngine::setObjectOwnership(virutalUser_AllBooks, QQmlEngine::CppOwnership);
//    UserModel* userModel = new UserModel();
//    userModel->append(user1);
//    userModel->append(user2);
//    userModel->append(virutalUser_AllBooks);
//    userModel->setCurrentControlUser(user1);
//    Book* book1 = new Book("9787121029097",0,"Effective C++",QVariantList(),QVariantList(),"Scott Meyers",QDate(2006,7,1),5,5,0);
//    Book* book2 = new Book("9787121155352", 0, "C++ Primer",QVariantList(),QVariantList(),"Stanley B Lippman", QDate(2013,9,1),5,5,0);
//    Book* book3 = new Book("9780132359238",1,QObject::tr("Digital Fundamentals"),QVariantList(),QVariantList(),QObject::tr("Thomas L Floyd"),QDate(2006,6,1),5,5,0);
//    Book* book4 = new Book("9787100013239",0,"GEB",QVariantList(),QVariantList(),"Douglas Richard Hofstadter",QDate(1997,5,1),5,5,0);
//    QQmlEngine::setObjectOwnership(book1, QQmlEngine::CppOwnership);
//    QQmlEngine::setObjectOwnership(book2, QQmlEngine::CppOwnership);
//    QQmlEngine::setObjectOwnership(book3, QQmlEngine::CppOwnership);
//    QQmlEngine::setObjectOwnership(book4, QQmlEngine::CppOwnership);

//    book1->bookOutTo(user1);
//    book2->bookOutTo(user1);
//    book2->bookOutTo(user2);
//    book1->bookOutTo(virutalUser_AllBooks);
//    book2->bookOutTo(virutalUser_AllBooks);
//    book3->bookOutTo(virutalUser_AllBooks);
//    book4->bookOutTo(virutalUser_AllBooks);
//    return userModel;
//}
//QVariantList connectSecurityDemo() {
//    QVariantList db;
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
////    for(QVariant i : db) {
////            qInfo() << i;
////            qInfo() << "hhhh";
////            qInfo() << i.toHash();
////            qInfo() << "wwwwww";
////            qInfo() << (i.toHash()).value("useranme");
////            qInfo() << "god yeah ........";
////            qInfo() << (i.toHash()).value("useranme").toString();
////            qInfo() << "end end end";
////    }
//    return db;

//}

#endif // DEMO_H
