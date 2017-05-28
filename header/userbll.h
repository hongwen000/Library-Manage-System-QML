#ifndef USERBLL_H
#define USERBLL_H
#include <QObject>
#include <QVariantList>
class Reader: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QVariantList record READ record WRITE setRecord NOTIFY recordChanged)
public:
    Reader(const QString &id = "",
           const QString &password = "")
    : id_(id),password_(password){
        this->setProperty("id",id);
        this->setProperty("password",password);
    }

    Reader(const Reader &r):
        id_(r.id_),
        password_(r.password_),
        record_(r.record_){}

    Reader operator =(const Reader &r){
        id_ = r.id_;
        password_ = r.password_;
        record_ = r.record_;
        return *this;
    }

    QString id() const;       //id
    QString password() const; //密码
    QVariantList record() const; //记录
    Q_INVOKABLE void doSomething()const;

public slots:
    void setId(const QString &);
    void setPassword(const QString &);
    void setRecord(const QVariantList &);

public:
    QString id_;
    QString password_;
    QVariantList record_;//借书记录

signals:
    void idChanged();
    void passwordChanged();
    void recordChanged();
};
#endif // USERBLL_H
