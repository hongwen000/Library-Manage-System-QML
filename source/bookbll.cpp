#include "header/bookbll.h"
#include "header/updatedbdcl.h"
#include <QDebug>

void Book::bookOutTo(User *_borrower)
{
    //Todo : limit it that only borrow one book
    m_borrower << QVariant::fromValue(_borrower);
    qInfo() << "It's me, book" << bookName() << "been borrowed";
    //m_borrower.append(_borrower);
    m_avaiStock--;
    m_borrowedNum++;
    QDate tmp = QDate::currentDate().addMonths(1);
    m_borrowDate << QVariant::fromValue(tmp);
    _borrower->borrowBook(this);
    borrowBookDCL(this->isbn(), _borrower->id(), tmp.toString("yyyy-MM-dd"), m_avaiStock, m_borrowedNum);
}

void Book::bookOutTo(User *_borrower, QDate _borrowDate)
{
    //Todo : limit it that only borrow one book
    m_borrower << QVariant::fromValue(_borrower);
    qInfo() << "It's me, book" << bookName() << "been borrowed at" << _borrowDate.toString("yyyy-MM-dd");
    //m_borrower.append(_borrower);
    m_avaiStock--;
    m_borrowedNum++;
    m_borrowDate << QVariant::fromValue(_borrowDate);
    _borrower->borrowBook(this);

}

void Book::bookReturnIn(User *_borrower)
{
    if(m_borrower.contains(QVariant::fromValue(_borrower)))
    {
        int index = m_borrower.indexOf(QVariant::fromValue(_borrower));
        qInfo() << "It's me, book" << bookName() << "been returned";
        m_borrower.erase(m_borrower.begin() + index);
        m_borrowDate.erase(m_borrowDate.begin() + index);
        _borrower->returnBook(this);
        m_avaiStock++;
        m_borrowedNum--;
        returnBookDCL(this->isbn(),_borrower->id(), m_avaiStock, m_borrowedNum);
    }
}

bool Book::alreadyBorrowed(User *_borrower)
{
    return m_borrower.contains(QVariant::fromValue(_borrower));
}

int Book::findBorrowerIndex(User *_borrower)
{
    return m_borrower.indexOf(QVariant::fromValue(_borrower));
}

void Book::deconstruct() {
    removeBookDCL(this->isbn());
    this->~Book();
}

void Book::edit(const QString &_bookName, const QString &_author, const QDate &_publishDate, int _totalStock, int _avaiStock)
{
    this->setBookName(_bookName);
    this->setAuthor(_author);
    this->setPublishDate(_publishDate);
    this->setTotalStock(_totalStock);
    this->setAvaiStock(_avaiStock);
    this->setBorrowedNum(_totalStock - _avaiStock);
    editBookDCL(_bookName,_author,_publishDate,_totalStock,_avaiStock);
}
