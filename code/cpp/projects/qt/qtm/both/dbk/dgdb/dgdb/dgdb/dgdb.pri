
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = dgdb

include(../build-group.pri)


DEFINES += DEFAULT_DEV_DGDB_FOLDER=\\\"$$ROOT_DIR/dev/data/dgdb\\\"



INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR


DEFINES += USE_RZNS
DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES

INCLUDEPATH += $$HGDM_SRC_GROUP_DIR

INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR

INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$NTXH_SRC_GROUP_DIR

INCLUDEPATH += $$NTXH_SRC_GROUP_DIR/ntxh

CONFIG += no_keywords

DEFINES += USE_KANS


HEADERS += \
  $$SRC_DIR/dgdb.h \
  $$SRC_DIR/dgdb-instance.h \
  $$SRC_DIR/wg-stage-value.h \
  $$SRC_DIR/wdb-manager.h \
  $$SRC_DIR/wdb-instance.h \
  $$SRC_DIR/dgenvironment.h \
  $$SRC_DIR/graph/dgdb-node.h \
  $$SRC_DIR/graph/dgdb-frame.h \
  $$SRC_DIR/types/dgdb-type.h \
  $$SRC_DIR/types/dgdb-type-builder.h \
  $$SRC_DIR/_whitedb/_whitedb.h \


SOURCES += \
  $$SRC_DIR/dgdb.cpp \
  $$SRC_DIR/dgdb-instance.cpp \
  $$SRC_DIR/dgenvironment.cpp \
  $$SRC_DIR/wg-stage-value.cpp \
  $$SRC_DIR/wdb-manager.cpp \
  $$SRC_DIR/wdb-instance.cpp \
  $$SRC_DIR/graph/dgdb-node.cpp \
  $$SRC_DIR/graph/dgdb-frame.cpp \
  $$SRC_DIR/types/dgdb-type.cpp \
  $$SRC_DIR/types/dgdb-type-builder.cpp \
  $$SRC_DIR/_whitedb/_whitedb.c \


LIBS += -L$$TARGETSDIR -lntxh 


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)


