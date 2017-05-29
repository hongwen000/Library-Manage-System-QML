#ifndef SEARCHBLL_H
#define SEARCHBLL_H
#include "universaltool.h"
#include <QObject>
class Searcher:public QObject  {
    Q_OBJECT
    Q_PROPERTY(QString keyword READ keyword WRITE setKeyword NOTIFY keywordChanged)
    Q_PROPERTY(int bookType READ bookType WRITE setBookType NOTIFY bookTypeChanged)
public:
    Searcher(QString _keyword = "", int _bookType = 0) : m_keyword(_keyword), m_bookType(_bookType) {}
    Searcher(const Searcher& rhs) {
        m_keyword = rhs.m_keyword;
        m_bookType = rhs.m_bookType;
    }
    Searcher& operator =(const Searcher& rhs) {
        m_keyword = rhs.m_keyword;
        m_bookType = rhs.m_bookType;
        return *this;
    }

    DEF_INVOKE_PROPERTY_IMPL(QString, keyword, Keyword)
    DEF_INVOKE_PROPERTY_IMPL(int, bookType, BookType)
signals:
    void keywordChanged();
    void bookTypeChanged();
private:
    QString m_keyword;
    int m_bookType;
};

#endif // SEARCHBLL_H
