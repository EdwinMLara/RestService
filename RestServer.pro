QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Request.cpp \
        Response.cpp \
        jardinsensores.cpp \
        jsonobject.cpp \
        lista.cpp \
        main.cpp \
        path.cpp \
        requestbody.cpp \
        responsebody.cpp \
        rest.cpp \
        router.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Request.h \
    Response.h \
    jardinsensores.h \
    jsonobject.h \
    lista.h \
    path.h \
    requestbody.h \
    responsebody.h \
    rest.h \
    router.h
