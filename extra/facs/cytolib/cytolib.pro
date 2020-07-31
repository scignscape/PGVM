
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


DEFINES+=QT_CYTOLIB_VERSION=\\\"9.9.9\\\"


HEADERS += \


SOURCES +=  \
 ./src/calibrationTable.cpp \
 ./src/compensation.cpp \
 ./src/CytoFrame.cpp \
 ./src/CytoFrameView.cpp \
 ./src/CytoVFS.cpp \
 ./src/dummy.cpp \
 ./src/ellipse2points.cpp \
 ./src/gate.cpp \
 ./src/GatingHierarchy.cpp \
 ./src/GatingSet.cpp \
 ./src/global.cpp \
 ./src/H5CytoFrame.cpp \
 ./src/in_polygon.cpp \
 ./src/MemCytoFrame.cpp \
 ./src/nodeProperties.cpp \
 ./src/POPINDICES.cpp \
 ./src/spline.cpp \
 ./src/transformation.cpp \
 ./src/trans_group.cpp \

# ./src/GatingSet.pb.cc
# ./src/Makevars.in
# ./src/Makevars.win


LIBS += -L$$PROTOBUF_INSTALL/lib -lprotobuf-lite
LIBS += -L$$LIBHDF5_INSTALL/lib -lhdf5

#

OBJECTS_DIR = ./build/objects
DESTDIR = ./build/dest
TARGETSDIR = ./build/targets




