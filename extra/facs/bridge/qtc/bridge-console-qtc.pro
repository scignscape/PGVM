
QT += widgets core 

TEMPLATE = app

INCLUDEPATH += \
 ../.. \


HEADERS += \


SOURCES +=  \
 ../bridge-console/main.cpp \


OBJECTS_DIR = ../../dest-qtc/objects
DESTDIR = ../../dest-qtc

LIBS += -L$$DESTDIR -lbridge-qtc

message(DD: $$DESTDIR)


