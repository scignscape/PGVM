
QT += widgets core 

TEMPLATE = app

INCLUDEPATH += \
 ../.. \


HEADERS += \


SOURCES +=  \
 ./main.cpp \


OBJECTS_DIR = ../../../dest/objects
DESTDIR = ../../../dest

LIBS += -L$$DESTDIR -lbridge



