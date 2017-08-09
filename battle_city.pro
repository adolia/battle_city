TEMPLATE = app

QT += qml quick
CONFIG += c++11

HEADERS += \
    include/stageobject.h \
    include/wall.h \
    include/battlefield.h \
    include/tank.h \
    include/aitank.h \
    include/shell.h

SOURCES += src/main.cpp \
    src/stageobject.cpp \
    src/wall.cpp \
    src/battlefield.cpp \
    src/tank.cpp \
    src/aitank.cpp \
    src/shell.cpp

INCLUDEPATH += $$PWD/include
RESOURCES += qml.qrc resources.qrc

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
DEPENDPATH += /home/alex/Downloads/qt-qml-models
INCLUDEPATH += /home/alex/Downloads/qt-qml-models
LIBS += -L$$PWD/lib -lQtQmlModels
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
