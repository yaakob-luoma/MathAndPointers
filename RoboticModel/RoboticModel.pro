TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    LinkageArm.cpp \
    Matrix.cpp \
    SEVisionWorkhead.cpp \
    WorkheadSolver.cpp \
    Point.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    LinkageArm.h \
    Matrix.h \
    SEVisionWorkhead.h \
    WorkheadSolver.h \
    Point.h
