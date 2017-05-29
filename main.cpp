#include <QFont>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlContext>
#include <QString>
#include <QObject>
#include "header/usermodelbll.h"
#include "header/userbll.h"
#include "header/demo.h"
#include "header/loginbll.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<UserModel>("Backend", 1, 0, "ReaderModel");
    qmlRegisterType<User>("User", 1, 0, "User");
    qmlRegisterType<Login>("Login", 1 , 0, "Login");
    QQmlApplicationEngine* engine = new QQmlApplicationEngine();
    UserModel* userModel = connectDBdemo();
    Login* login = new Login();
    login->setSecurityDB(connectSecurityDemo());
    login->setProperty("usrLogined", false);
    login->setProperty("adminLogined", false);
    engine->rootContext()->setContextProperty("userModel", userModel);
    engine->rootContext()->setContextProperty("login", login);

    engine->load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
