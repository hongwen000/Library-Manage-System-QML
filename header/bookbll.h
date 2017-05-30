#ifndef BOOKBLL_H
#define BOOKBLL_H
#include <QObject>
#include <QDate>
#include "userbll.h"
#include "universaltool.h"
#include "userbll.h"
class Book: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString isbn READ isbn WRITE setIsbn NOTIFY isbnChanged)
    Q_PROPERTY(QString bookName READ bookName WRITE setBookName NOTIFY bookNameChanged)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(QDate publishDate READ publishDate WRITE setPublishDate NOTIFY publishDateChanged)
    Q_PROPERTY(int totalStock READ totalStock WRITE setTotalStock NOTIFY totalStockChanged)
    Q_PROPERTY(int avaiStock READ avaiStock WRITE setAvaiStock NOTIFY avaiStockChanged)
    Q_PROPERTY(int borrowedNum READ borrowedNum WRITE setBorrowedNum NOTIFY borrowedNumChanged)
    Q_PROPERTY(QVariantList borrower READ borrower WRITE setBorrower NOTIFY borrowerChanged)
    Q_PROPERTY(QVariantList borrowDate READ borrowDate WRITE setBorrowDate NOTIFY borrowDateChanged)
public:
    Book(const QString& _isbn = "", int _type = 0,  const QString &_bookName="",const QVariantList& _borrower = QVariantList(), const QVariantList& _borrowDate = QVariantList(),QString _author = "",
         const QDate& _publishDate = QDate::currentDate(), int _totalStock = 0, int _avaiStock = 0, int _borrowedNum = 0):
    m_isbn(_isbn), m_type(_type), m_bookName(_bookName),m_borrower(_borrower), m_borrowDate(_borrowDate), m_author(_author), m_publishDate(_publishDate), m_totalStock(_totalStock), m_avaiStock(_avaiStock), m_borrowedNum(_borrowedNum){}
    Book(const Book& rhs) {
        m_isbn         =rhs.m_isbn       ;
        m_bookName     =rhs.m_bookName   ;
        m_type         =rhs.m_type       ;
        m_author       =rhs.m_author     ;
        m_publishDate  =rhs.m_publishDate;
        m_totalStock   =rhs.m_totalStock ;
        m_avaiStock    =rhs.m_avaiStock  ;
        m_borrowedNum  =rhs.m_borrowedNum;
        m_borrower     =rhs.m_borrower   ;
        m_borrowDate   =rhs.m_borrowDate ;
    }

    DEF_PROPERTY_IMPL(QString,isbn,Isbn)
    DEF_PROPERTY_IMPL(QString,bookName,BookName)
    DEF_PROPERTY_IMPL(int,type,Type)
    DEF_PROPERTY_IMPL(QString,author,Author)
    DEF_PROPERTY_IMPL(QDate,publishDate,PublishDate)
    DEF_PROPERTY_IMPL(int,totalStock, TotalStock)
    DEF_PROPERTY_IMPL(int,avaiStock,AvaiStock)
    DEF_PROPERTY_IMPL(int,borrowedNum,BorrowedNum)
    DEF_PROPERTY_IMPL(QVariantList,borrower,Borrower)
    DEF_PROPERTY_IMPL(QVariantList,borrowDate,BorrowDate)

    Q_INVOKABLE void bookOutTo(User* _borrower);
    Q_INVOKABLE void bookOutTo(QVariant _borrower);
    //Q_INVOKABLE void bookOutTo(const QString& _borrower, );
    Q_INVOKABLE void bookReturnIn(User* _borrower);
    Q_INVOKABLE bool alreadyBorrowed(User* _borrower);
public slots:


private:
    QString m_isbn;
    int m_type;
    QString m_bookName;
    QString m_author;
    QDate m_publishDate;
    int m_totalStock;
    int m_avaiStock;
    int m_borrowedNum;
    QVariantList m_borrower;
    QVariantList m_borrowDate;

signals:
    void isbnChanged();
    void bookNameChanged();
    void authorChanged();
    void publishDateChanged();
    void totalStockChanged();
    void avaiStockChanged();
    void borrowedNumChanged();
    void borrowerChanged();
    void borrowDateChanged();
    void typeChanged();

};
Q_DECLARE_METATYPE(Book)//元类型注册
#endif // BOOKBLL_H
