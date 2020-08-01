
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
 ./include/cytolib/MemCytoFrame.hpp \


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
 ./src/GatingSet.pb.cc \
 ./src/global.cpp \
 ./src/H5CytoFrame.cpp \
 ./src/in_polygon.cpp \
 ./src/MemCytoFrame.cpp \
 ./src/nodeProperties.cpp \
 ./src/POPINDICES.cpp \
 ./src/spline.cpp \
 ./src/transformation.cpp \
 ./src/trans_group.cpp \


#DEFINES += ARMA_DONT_USE_WRAPPER

# armadillo
# SOURCES +=  \
#  ./armadillo/src/wrapper1.cpp \
#  ./armadillo/src/wrapper2.cpp \


# HDF5
SOURCES +=  \
 ./hdf5/H5AbstractDs.cpp \
 ./hdf5/H5ArrayType.cpp \
 ./hdf5/H5AtomType.cpp \
 ./hdf5/H5Attribute.cpp \
 ./hdf5/H5CommonFG.cpp \
 ./hdf5/H5CompType.cpp \
 ./hdf5/H5DaccProp.cpp \
 ./hdf5/H5DataSet.cpp \
 ./hdf5/H5DataSpace.cpp \
 ./hdf5/H5DataType.cpp \
 ./hdf5/H5DcreatProp.cpp \
 ./hdf5/H5DxferProp.cpp \
 ./hdf5/H5EnumType.cpp \
 ./hdf5/H5Exception.cpp \
 ./hdf5/H5FaccProp.cpp \
 ./hdf5/H5FcreatProp.cpp \
 ./hdf5/H5File.cpp \
 ./hdf5/H5FloatType.cpp \
 ./hdf5/H5Group.cpp \
 ./hdf5/H5IdComponent.cpp \
 ./hdf5/H5IntType.cpp \
 ./hdf5/H5LaccProp.cpp \
 ./hdf5/H5LcreatProp.cpp \
 ./hdf5/H5Library.cpp \
 ./hdf5/H5Location.cpp \
 ./hdf5/H5Object.cpp \
 ./hdf5/H5OcreatProp.cpp \
 ./hdf5/H5PredType.cpp \
 ./hdf5/H5PropList.cpp \
 ./hdf5/H5StrType.cpp \
 ./hdf5/H5VarLenType.cpp \


# ./src/GatingSet.pb.cc
# ./src/Makevars.in
# ./src/Makevars.win


LIBS += -L$$PROTOBUF_INSTALL/lib -lprotobuf-lite
LIBS += -L$$LIBHDF5_INSTALL/lib -lhdf5
LIBS += -lstdc++fs -llapack -llapacke -lblas 


#

OBJECTS_DIR = ./build/objects
DESTDIR = ./build/dest
TARGETSDIR = ./build/targets




