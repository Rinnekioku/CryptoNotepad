QT       += core gui \
    widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets
CONFIG += c++11
TARGET = CryptoNotepad
TEMPLATE = app



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/cryptobase.cpp \
    core/decryptor.cpp \
    core/encryptor.cpp \
    main.cpp \
    gui/widget.cpp \

HEADERS += \
    core/cryptobase.h \
    core/decryptor.h \
    core/encryptor.h \
    gui/widget.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
