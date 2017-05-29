#ifndef DEMO_H
#define DEMO_H
#include <utility>
#include <tuple>
#include "header/usermodelbll.h"
#include <string>
#include <list>
#include <QDebug>
UserModel* connectDBdemo(){
    User* virutalUser_AllBooks = new User("virutalUser_AllBooks");
    User* user1 = new User("user1","user1");
    User* user2 = new User("User2", "User2");
    UserModel* userModel = new UserModel();
    userModel->append(user1);
    userModel->append(user2);
    userModel->append(virutalUser_AllBooks);
    userModel->setCurrentControlUser(user1);
    Book* book1 = new Book("1234567890",0,"Effective C++");
    Book* book2 = new Book("9876543210", 0, "C++ Primer");
    Book* book3 = new Book("6666666666",1,"Digital Fundenmental");
    book1->bookOutTo(user1);
    book2->bookOutTo(user1);
    book2->bookOutTo(user2);
    book1->bookOutTo(virutalUser_AllBooks);
    book2->bookOutTo(virutalUser_AllBooks);
    book3->bookOutTo(virutalUser_AllBooks);
    return userModel;
}
QVariantList connectSecurityDemo() {
    QVariantList db;
    QVariantHash a;
    a.insert("useranme", "user1");
    a.insert("password", "user1");
    a.insert("type", "user");
    db << a;
    a.clear();
    a.insert("useranme", "user2");
    a.insert("password", "user2");
    a.insert("type", "admin");
    db << a;
//    for(QVariant i : db) {
//            qInfo() << i;
//            qInfo() << "hhhh";
//            qInfo() << i.toHash();
//            qInfo() << "wwwwww";
//            qInfo() << (i.toHash()).value("useranme");
//            qInfo() << "god yeah ........";
//            qInfo() << (i.toHash()).value("useranme").toString();
//            qInfo() << "end end end";
//    }
    return db;

}

#endif // DEMO_H
