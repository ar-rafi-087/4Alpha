QT       += core gui sql printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Puzzle15.cpp \
    bird.cpp \
    chess.cpp \
    homepage.cpp \
    main.cpp \
    login.cpp \
    mainwindow.cpp \
    registration.cpp \
    tictactoe.cpp

HEADERS += \
    Puzzle15.h \
    bird.h \
    chess.h \
    homepage.h \
    login.h \
    mainwindow.h \
    registration.h \
    tictactoe.h

FORMS += \
    Puzzle15.ui \
    bird.ui \
    chess.ui \
    homepage.ui \
    login.ui \
    mainwindow.ui \
    registration.ui \
    tictactoe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc


