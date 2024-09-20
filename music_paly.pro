QT       += core gui  multimedia

INCLUDEPATH += $$PWD/lib/ffmpeg/include
LIBS += -L$$PWD/lib/ffmpeg/lib -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lpostproc -lswresample -lswscale

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addlib.cpp \
    list.cpp \
    lrcshow.cpp \
    main.cpp \
    mainwindow.cpp \
    music.cpp \
    qpixmapshow.cpp \
    seit.cpp \
    table.cpp

HEADERS += \
    addlib.h \
    hard.h \
    list.h \
    lrcshow.h \
    mainwindow.h \
    music.h \
    qpixmapshow.h \
    seit.h \
    table.h

FORMS += \
    list.ui \
    lrcshow.ui \
    mainwindow.ui \
    qpixmapshow.ui \
    seit.ui \
    table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = exe.ico

HEADERS += \
    addlib.h \
    hard.h \
    mainwindow.h

RESOURCES += \
    ui/ui.qrc

QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"
