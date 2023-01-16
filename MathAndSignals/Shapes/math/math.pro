TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../LinearAlgebra.cpp \
        ../Matrix.cpp \
        main.cpp

HEADERS += \
    ../LinearAlgebra.h \
    ../Matrix.h
