#include "header/universaltool.h"
void uni_setFont(QGuiApplication &app, const QString &fontName, int fontSize)
{
    std::shared_ptr<QFont> font = std::make_shared<QFont>(fontName);
    font->setPixelSize(fontSize);
    app.setFont(*font);
}

