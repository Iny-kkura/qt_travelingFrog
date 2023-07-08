QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+=resouces_big
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allanimation.cpp \
    card.cpp \
    card_newline.cpp \
    clovers_pro.cpp \
    cloverwindow.cpp \
    collectiondlg.cpp \
    frog.cpp \
    item.cpp \
    logindlg.cpp \
    lotter.cpp \
    lottery_newline.cpp \
    lotterydialog_01.cpp \
    lotterydialog_02.cpp \
    lotterywindow.cpp \
    mailwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    newraffle.cpp \
    store.cpp \
    tableblg.cpp \
    yard.cpp

HEADERS += \
    allanimation.h \
    card.h \
    card_newline.h \
    clovers_pro.h \
    cloverwindow.h \
    collectiondlg.h \
    frog.h \
    item.h \
    logindlg.h \
    lotter.h \
    lottery_newline.h \
    lotterydialog_01.h \
    lotterydialog_02.h \
    lotterywindow.h \
    mailwindow.h \
    mainwindow.h \
    map.h \
    newraffle.h \
    store.h \
    tableblg.h \
    yard.h

FORMS += \
    card.ui \
    card_newline.ui \
    cloverwindow.ui \
    collectiondlg.ui \
    logindlg.ui \
    lottery_newline.ui \
    lotterydialog_01.ui \
    lotterydialog_02.ui \
    lotterywindow.ui \
    mailwindow.ui \
    mainwindow.ui \
    newraffle.ui \
    store.ui \
    tableblg.ui \
    yard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MyPicture.qrc \
    music.qrc

DISTFILES += \
    pictures/icon/possession.png
