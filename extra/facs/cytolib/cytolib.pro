
QT += widgets core 

TEMPLATE = app

INCLUDEPATH += \
 ./include \

INCLUDEPATH += \
  $$PROTOBUF_INSTALL/include

INCLUDEPATH += \
 ./armadillo \



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


DEFINES += DEFAULT_ICON_FOLDER=\\\"$$PWD/gui/resource\\\"

#


OBJECTS_DIR = ./build/objects
DESTDIR = ./build/dest
TARGETSDIR = ./build/targets


