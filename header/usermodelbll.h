#ifndef USERMODELBLL_H
#define USERMODELBLL_H
#include <QModelIndex>
#include <QAbstractListModel>
#include <QJsonValueRef>
#include <QDebug>
#include <QVariant>
#include "userbll.h"
#include "bookbll.h"

class ReaderModel :  public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(Reader* me READ me WRITE setMe NOTIFY meChanged)
    Q_PROPERTY(QString keyword READ keyword WRITE setKeyword NOTIFY keywordChanged)
    Q_PROPERTY(QList<Reader> users READ users WRITE setUsers NOTIFY usersChanged)
public:
    enum ReaderRole {
        IdRole = Qt::DisplayRole, //0
        PasswordRole = Qt::UserRole,
        RecordRole
    };
    Q_ENUM(ReaderRole)

    ReaderModel(QObject *parent = nullptr){
        Q_UNUSED(parent);
        connect(this,SIGNAL(keywordChanged()),this,SLOT(onKeywordChanged()));
    }

    int rowCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(const QString &id,
                            const QString &password);
    //Q_INVOKABLE void append(const Reader&);
    Q_INVOKABLE void set(int row, const QString &id,
                         const QString &password);
    Q_INVOKABLE void remove(int row);

    Q_INVOKABLE Reader *me() const;
    Q_INVOKABLE void setMe(Reader *r);

    QString keyword() const {
        return m_keyword;
    }

    void setKeyword(const QString & _kw) {
        m_keyword = _kw;
        emit keywordChanged();
    }

signals:
    void meChanged();
    void keywordChanged();

public slots:
    void onKeywordChanged() {
    qInfo() << m_keyword;
    Record *i = new Record(m_keyword,0);
    (me_->record_) << QVariant::fromValue(i);
    me_->recordChanged();
    }

private:
    QList<Reader> m_readers;
    Reader *me_;
    QString m_keyword;
};
#endif // USERMODELBLL_H
