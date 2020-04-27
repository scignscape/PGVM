
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
INCLUDEPATH += $$PHAONLIB_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR


CONFIG += no_keywords

DEFINES += USE_KANS


HEADERS += \
  $$SRC_DIR/dgdb.h \
  $$SRC_DIR/dgdb-instance.h \
  $$SRC_DIR/dgenvironment.h \


SOURCES += \
  $$SRC_DIR/dgdb.cpp \
  $$SRC_DIR/dgdb-instance.cpp \
  $$SRC_DIR/dgenvironment.cpp \


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

