#include "header/loginbll.h"
void Login::setUsrname(const QString &usrname) {
  m_usrname = usrname;
  emit usrnameChanged();
}

QString Login::password() const { return m_password; }

void Login::setPassword(const QString &password) {
  m_password = password;
  emit passwordChanged();
}

bool Login::adminLogined() const { return m_adminLogined; }

bool Login::usrLogined() const { return m_usrLogined; }

void Login::setAdminLogined(bool deter) {
  m_adminLogined = deter;
  emit adminLoginedChanged();
}

void Login::setUsrLogined(bool deter) {
  m_usrLogined = deter;
  emit usrLoginedChanged();
}

void Login::auth() {
  for (auto i : m_securityDB) {
    QString rightUsername = (i.toHash()).value("username").toString();
    QString rightPassword = (i.toHash()).value("password").toString();
    QString rightType = (i.toHash()).value("type").toString();
    QByteArray byteArray;
    byteArray.append(m_password);
    QByteArray hash = QCryptographicHash::hash(byteArray, QCryptographicHash::Md5);
    QString MD5_password = hash.toHex();
    if (rightUsername == m_usrname) {
      if (rightPassword == MD5_password) {
        if (rightType == "user") {
          emit usrAuthSucc();
          return;
        } else {
          emit adminAuthSucc();
          return;
        }
      }
    }
  }
  emit authFail();
}

void Login::setSecurityDB(const QVariantList &rhs) { m_securityDB = rhs; }

QVariantList Login::securityDB() const { return m_securityDB; }

void Login::initial(const QVariantHash &secDB) {
  setProperty("usrLogined", false);
  setProperty("adminLogined", false);
  QVariant table = secDB.value("security");
  setSecurityDB(table.value<QVariantList>());
}

Login::Login(QQuickItem *parent) { (parent); }

QString Login::usrname() const { return m_usrname; }
