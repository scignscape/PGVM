
QT += widgets core 

TEMPLATE = app

INCLUDEPATH += \
 ./include \
 .. \


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
 ./cytolib-console/main.cpp \

# ./src/GatingSet.pb.cc
# ./src/Makevars.in
# ./src/Makevars.win


DEFINES += ARMA_DONT_USE_WRAPPER


LIBS += -L$$PROTOBUF_INSTALL/lib -lprotobuf-lite

#LIBS += /home/nlevisrael/hypergr/flowcy/protobuf/install/lib/libprotobuf-lite.a

LIBS += -L$$LIBHDF5_INSTALL/lib -lhdf5

#LIBS += -O1 -L/home/nlevisrael/hypergr/flowcy/armadillo/armadillo-9.900.2 -larmadillo

LIBS += -lstdc++fs -llapack -llapacke  -lblas  



#

OBJECTS_DIR = ../../../dest/objects/cytolib-console
DESTDIR = ../../../dest

LIBS += -L$$DESTDIR -lcytolib -lbridge




