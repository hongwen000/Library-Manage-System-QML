#ifndef CONNECTDBDCL_H
#define CONNECTDBDCL_H
#include "header/usermodelbll.h"
#include <QDate>
#include <QDebug>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <list>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
UserModel *connectDBdemo();
QVariantList connectSecurityDemo();

#endif // CONNECTDBDCL_H
