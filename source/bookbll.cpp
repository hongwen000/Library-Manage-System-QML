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
    _borrower->borrowBook(this);

}

void Book::bookOutTo(QVariant _borrower)
{
    bookReturnIn(qvariant_cast<User*>(_borrower));
}

void Book::bookReturnIn(User *_borrower)
{
    if(m_borrower.contains(QVariant::fromValue(_borrower)))
    {
        m_borrower.erase(m_borrower.begin() + m_borrower.indexOf(QVariant::fromValue(_borrower)));
        _borrower->returnBook(this);
    }
}

bool Book::alreadyBorrowed(User *_borrower)
{
    return m_borrower.contains(QVariant::fromValue(_borrower));
}
