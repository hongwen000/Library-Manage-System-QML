#include "header/bookbll.h"
#include <QDebug>

void Book::bookOutTo(User *_borrower)
{
    //Todo : limit it that only borrow one book
    m_borrower << QVariant::fromValue(_borrower);
    qInfo() << "It's me, book" << bookName() << "been borrowed";
    //m_borrower.append(_borrower);
    m_avaiStock--;
    m_borrowedNum++;
    m_borrowDate << QVariant::fromValue(QDate::currentDate().addMonths(1));
    _borrower->borrowBook(this);

}

void Book::bookReturnIn(User *_borrower)
{
    if(m_borrower.contains(QVariant::fromValue(_borrower)))
    {
        int index = m_borrower.indexOf(QVariant::fromValue(_borrower));
        m_borrower.erase(m_borrower.begin() + index);
        m_borrowDate.erase(m_borrowDate.begin() + index);
        _borrower->returnBook(this);
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
