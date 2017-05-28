#ifndef BOOKBLL_H
#define BOOKBLL_H
#include <QObject>

class Record: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString bookId READ bookId WRITE setBookId NOTIFY bookIdChanged)
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
public:
    Record(const QString &bookId="",int state=0):
    bookId_(bookId),state_(state){}

    Record(const Record &r){
        bookId_ = r.bookId_;
        state_ = r.state_;
    }

    QString bookId() const;
    int state() const;
public slots:
    void setBookId(const QString &);
    void setState(int);
private:
    QString bookId_;
    int state_;
signals:
    void bookIdChanged();
    void stateChanged();
};
Q_DECLARE_METATYPE(Record)//元类型注册
#endif // BOOKBLL_H
