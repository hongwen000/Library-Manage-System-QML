#include "header/bookbll.h"
QString Record::bookId() const
{
    return bookId_;
}
int Record::state() const
{
    return state_;
}
void Record::setBookId(const QString &value)
{
    if(bookId_ == value)
        return;
    bookId_ = value;
    emit bookIdChanged();
}
void Record::setState(int value)
{
    if(state_ == value)
        return;
    state_ = value;
    emit stateChanged();
}
