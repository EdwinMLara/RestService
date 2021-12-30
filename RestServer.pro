QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/Request.cpp \
        src/Response.cpp \
        src/jardinsensores.cpp \
        src/jsonobject.cpp \
        src/lista.cpp \
        main.cpp \
        src/path.cpp \
        src/requestbody.cpp \
        src/responsebody.cpp \
        rest.cpp \
        src/router.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/Request.h \
    src/Response.h \
    src/jardinsensores.h \
    src/jsonobject.h \
    src/lista.h \
    src/path.h \
    src/requestbody.h \
    src/responsebody.h \
    rest.h \
    src/router.h
