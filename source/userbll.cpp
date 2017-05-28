#include "header/userbll.h"
#include "header/bookbll.h"
#include <QVariant>
QString Reader::id() const
{
    return id_;
}
QString Reader::password() const
{
    return password_;
}
QVariantList Reader::record() const
{
    return record_;
}

void Reader::doSomething() const
{

}
void Reader::setId(const QString &value)
{
    if (id_ == value)
        return;
    id_ = value;
    emit idChanged();
}
void Reader::setPassword(const QString &value)
{
    if (password_ == value)
        return;
    password_ = value;
    emit passwordChanged();
}
void Reader::setRecord(const QVariantList &value)
{
    if (record_ == value)
        return;
    record_ = value;
    emit recordChanged();
}
