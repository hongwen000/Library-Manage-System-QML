#ifndef LOGININBLL_H
#define LOGININBLL_H
#include <QtQuick>
#include <QString>
#include <tuple>
#include <string>
#include <list>
using dbTerm = std::tuple<std::string, std::string, int>;

class Login : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString usrname READ usrname WRITE setUsrname NOTIFY usrnameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(bool usrLogined READ usrLogined WRITE setUsrLogined NOTIFY usrLoginedChanged)
    Q_PROPERTY(bool adminLogined READ adminLogined WRITE setAdminLogined NOTIFY adminLoginedChanged)
    Q_PROPERTY(QVariantList securityDB READ securityDB WRITE setSecurityDB NOTIFY securityDBChanged)
public:

    Login(QQuickItem *parent = 0);
    QString usrname() const;
    Q_INVOKABLE void setUsrname(const QString &name);
    QString password() const;
    Q_INVOKABLE void setPassword(const QString &password);
    bool adminLogined() const;
    bool usrLogined() const;
    void setUsrLogined(bool);
    void setAdminLogined(bool);
    Q_INVOKABLE void auth();
    Q_INVOKABLE void setSecurityDB(const QVariantList&);
    QVariantList securityDB() const;
signals:
    void usrnameChanged();
    void passwordChanged();
    void usrAuthSucc();
    void adminAuthSucc();
    void authFail();
    void usrLoginedChanged();
    void adminLoginedChanged();
    void securityDBChanged();
private:
    QString m_usrname;
    QString m_password;
    bool m_adminLogined;
    bool m_usrLogined;
    QVariantList m_securityDB;
};
#endif // LOGININBLL_H
