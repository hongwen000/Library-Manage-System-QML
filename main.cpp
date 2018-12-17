#include "header/connectdbdcl.h"
#include "header/db.h"
#include "header/dbfactory.h"
#include "header/librarydb.h"
#include "header/librarydbfactory.h"
#include "header/loginbll.h"
#include "header/securitydb.h"
#include "header/securitydbfactory.h"
#include "header/universaltool.h"
#include "header/userbll.h"
#include "header/usermodelbll.h"
#include <QFont>
#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>
#include <QtQml>
#include <QtSvg>
using std::shared_ptr;
using std::make_shared;
int main(int argc, char *argv[]) {
  QCoreApplication::addLibraryPath("./");
  //生成窗体
  qputenv("QT_QPA_PLATFORM", "webgl:port=8998");
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
  uni_setFont(app, "思源宋体", 16);

  //注册C++类型到QML
  qmlRegisterType<UserModel>("Backend", 1, 0, "ReaderModel");
  qmlRegisterType<User>("User", 1, 0, "User");
  qmlRegisterType<Login>("Login", 1, 0, "Login");

  //生成QML引擎
  QQmlApplicationEngine engine;
  QPM_INIT(engine);
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  // UAL与BLL层交互的接口,集成QObject，具有自动内存管理能力，故不使用智能指针容器
  // UserModel* userModel = connectDBdemo();
  UserModel *userModel = new UserModel();
  //登录信息管理器
  Login *login = new Login();
  //防止对象被QML的js层次结构的垃圾回收机制错误回收（该语言已知有这一个BUG）
  QQmlEngine::setObjectOwnership(userModel, QQmlEngine::CppOwnership);

  try {
    //生产图书馆信息和生产用户登录信息的工厂
    shared_ptr<dbFactory> libFc = make_shared<libraryDBFactory>();
    shared_ptr<db> libDB = libFc->createDB();
    shared_ptr<dbFactory> secFc = make_shared<securityDBFactory>();
    shared_ptr<db> secDB = secFc->createDB();
    userModel->initial(libDB->get());
    login->initial(secDB->get());
  } catch (...) {
    exit(255);
  }
  //将userModel和login，以及程序当前路径导入QML引擎中
  engine.rootContext()->setContextProperty("userModel", userModel);
  engine.rootContext()->setContextProperty("login", login);
  engine.rootContext()->setContextProperty(
      "applicationDirPath",
      "file:///" + QCoreApplication::applicationDirPath());

  // QML引擎加载主窗口
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));

  return app.exec();
}
