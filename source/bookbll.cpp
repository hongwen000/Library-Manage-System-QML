#include "header/bookbll.h"


void Book::bookOutTo(User *_borrower)
{
    //Todo : limit it that only borrow one book
    m_borrower << QVariant::fromValue(_borrower);
    //m_borrower.append(_borrower);
    _borrower->borrowBook(this);

}

void Book::bookReturnIn(User *_borrower)
{
    if(m_borrower.contains(QVariant::fromValue(_borrower)))
    {
        m_borrower.erase(m_borrower.begin() + m_borrower.indexOf(QVariant::fromValue(_borrower)));
        _borrower->returnBook(this);
    }
}
