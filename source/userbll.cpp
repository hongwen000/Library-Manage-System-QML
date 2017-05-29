#include "header/userbll.h"
#include "header/bookbll.h"
#include <QVariant>


void User::borrowBook(Book *_book)
{
    m_record << QVariant::fromValue(_book);
}

void User::returnBook(Book *_book)
{
    if(m_record.contains(QVariant::fromValue(_book))) {
        m_record.erase(m_record.begin() + m_record.indexOf(QVariant::fromValue(_book)));
    }
}
