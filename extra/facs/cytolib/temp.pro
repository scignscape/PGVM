
QT += widgets core 

TEMPLATE=lib

INCLUDEPATH += \
 ./include \

INCLUDEPATH += \
  $$PROTOBUF_INSTALL/include

INCLUDEPATH += \
 ./armadillo \

INCLUDEPATH += \
  $$LIBHDF5_INSTALL/include

INCLUDEPATH += \
 ./hdf5 \
 ./hdf5src \


DEFINES+=QT_CYTOLIB_VERSION=\\\"9.9.9\\\"


HEADERS += \


SOURCES +=  \
 ./src-temp/temp.cpp \

# ./src/GatingSet.pb.cc
# ./src/Makevars.in
# ./src/Makevars.win


#LIBS += -L$$PROTOBUF_INSTALL/lib -lprotobuf-lite
#LIBS += -L$$LIBHDF5_INSTALL/lib -lhdf5

#

OBJECTS_DIR = ../build/objects
DESTDIR = ../build/dest
TARGETSDIR = ../build/targets




