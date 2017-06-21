#ifndef UNIVERSALTOOL_H
#define UNIVERSALTOOL_H
#include <QFont>
#include <QGuiApplication>
#include <QString>
#include <memory>
#define DEF_PROPERTY_IMPL(type, propertyName, PropertyName)                    \
  type propertyName() const { return m_##propertyName; }                       \
  void set##PropertyName(const type &_##propertyName) {                        \
    m_##propertyName = _##propertyName;                                        \
    emit propertyName##Changed();                                              \
  }

#define DEF_INVOKE_PROPERTY_IMPL(type, propertyName, PropertyName)             \
  Q_INVOKABLE type propertyName() const { return m_##propertyName; }           \
  Q_INVOKABLE void set##PropertyName(const type &_##propertyName) {            \
    m_##propertyName = _##propertyName;                                        \
    emit propertyName##Changed();                                              \
  }

#define REGESTER_TYPE(...) qmlRegisterType<##__VA_ARGS__>("User", 1, 0, "User");

void uni_setFont(QGuiApplication &app, const QString &fontName, int fontSize);
#endif // UNIVERSALTOOL_H
