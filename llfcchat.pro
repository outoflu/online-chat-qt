QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

LIBS += -L$$PWD/spdlog/bin -lspdlog

DESTDIR=./bin
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HttpMgr.cpp \
    clickedlabel.cpp \
    global.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    resetdialog.cpp \
    timebtn.cpp

HEADERS += \
    HttpMgr.h \
    Singleton.h \
    clickedlabel.h \
    global.h \
    login.h \
    mainwindow.h \
    register.h \
    resetdialog.h \
    timebtn.h

FORMS += \
    login.ui \
    mainwindow.ui \
    register.ui \
    resetdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.ini \
    resource/icon.ico \
    style/stylesheet.qss

RESOURCES += \
    rc.qrc

DISTFILES += \
    config.ini

win32:CONFIG(debug, debug | release)
{
    #指定要拷贝的文件目录为工程目录下release目录下的所有dll、lib文件，例如工程目录在D:\QT\Test
    #PWD就为D:/QT/Test，DllFile = D:/QT/Test/release/*.dll
    TargetConfig = $${PWD}/config.ini
    #将输入目录中的"/"替换为"\"
    TargetConfig = $$replace(TargetConfig, /, \\)
    #将输出目录中的"/"替换为"\"
    OutputDir =  $${OUT_PWD}/$${DESTDIR}
    OutputDir = $$replace(OutputDir, /, \\)
    //执行copy命令
    QMAKE_POST_LINK += copy /Y \"$$TargetConfig\" \"$$OutputDir\"
}

