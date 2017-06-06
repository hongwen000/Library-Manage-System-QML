
QT += qml quick
QT += sql
CONFIG += c++11

SOURCES += main.cpp \
    source/userbll.cpp \
    source/bookbll.cpp \
    source/usermodelbll.cpp \
    source/loginbll.cpp \
    source/connectdbdcl.cpp \
    source/db.cpp \
    source/dbfactory.cpp \
    source/librarydb.cpp \
    source/librarydbfactory.cpp \
    source/securitydb.cpp \
    source/securitydbfactory.cpp \
    source/universaltool.cpp \
    source/universaldbtool.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    header/usermodelbll.h \
    header/userbll.h \
    header/bookbll.h \
    header/searchbll.h \
    header/universaltool.h \
    header/loginbll.h \
    header/demo.h \
    header/connectdbdcl.h \
    header/databasedcl.h \
    header/dbfactory.h \
    header/db.h \
    header/librarydb.h \
    header/securitydb.h \
    header/librarydbfactory.h \
    header/securitydbfactory.h \
    header/universaldbtool.h
