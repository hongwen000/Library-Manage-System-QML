#include <QFont>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlContext>
#include <QString>
#include <QObject>
#include "header/universaltool.h"
#include "header/usermodelbll.h"
#include "header/userbll.h"
#include "header/connectdbdcl.h"
#include "header/loginbll.h"
int main(int argc, char *argv[])
{
    //生成窗体
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    uni_setFont(app,"思源宋体",16);
    //注册C++类型到QML
    qmlRegisterType<UserModel>("Backend", 1, 0, "ReaderModel");
    qmlRegisterType<User>("User", 1, 0, "User");
    qmlRegisterType<Login>("Login", 1 , 0, "Login");
    qRegisterMetaType<Searcher>("Searcher");
    //生成QML引擎
    std::shared_ptr<QQmlApplicationEngine> engine = std::make_shared<QQmlApplicationEngine>();
    UserModel* userModel = connectDBdemo();
    //防止被QML的gc机制错误回收（该语言已知的BUG）
    QQmlEngine::setObjectOwnership(userModel, QQmlEngine::CppOwnership);
    Login* login = new Login();
    login->setSecurityDB(connectSecurityDemo());
    login->setProperty("usrLogined", false);
    login->setProperty("adminLogined", false);
    User* protectBookPointer = new User();
    engine->rootContext()->setContextProperty("userModel", userModel);
    engine->rootContext()->setContextProperty("login", login);
    engine->rootContext()->setContextProperty("protectBookPointer",protectBookPointer);

    engine->load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
