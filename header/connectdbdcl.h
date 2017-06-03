#ifndef CONNECTDBDCL_H
#define CONNECTDBDCL_H
#include <utility>
#include <tuple>
#include "header/usermodelbll.h"
#include <string>
#include <list>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDate>
#include <vector>
UserModel* connectDBdemo();
QVariantList connectSecurityDemo();

#endif // CONNECTDBDCL_H
