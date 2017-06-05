#include <QFont>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlContext>
#include <QString>
#include <QObject>
#include "header/usermodelbll.h"
#include "header/userbll.h"
#include "header/connectdbdcl.h"
#include "header/loginbll.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QFont font;
    font.setPointSize(12);
    font.setFamily("思源宋体");
    app.setFont(font);
    qmlRegisterType<UserModel>("Backend", 1, 0, "ReaderModel");
    qmlRegisterType<User>("User", 1, 0, "User");
    qmlRegisterType<Login>("Login", 1 , 0, "Login");
    qRegisterMetaType<Searcher>("Searcher");
    QQmlApplicationEngine* engine = new QQmlApplicationEngine();
    UserModel* userModel = connectDBdemo();
    Login* login = new Login();
    login->setSecurityDB(connectSecurityDemo());
    login->setProperty("usrLogined", false);
    login->setProperty("adminLogined", false);
    User* protectBookPointer = new User();
    engine->rootContext()->setContextProperty("userModel", userModel);
    QQmlEngine::setObjectOwnership(userModel, QQmlEngine::CppOwnership);
    engine->rootContext()->setContextProperty("login", login);
    engine->rootContext()->setContextProperty("protectBookPointer",protectBookPointer);

    engine->load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
