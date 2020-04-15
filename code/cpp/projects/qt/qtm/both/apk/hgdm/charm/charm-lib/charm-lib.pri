
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = charm-lib

include(../build-group.pri)


INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR $$SRC_ROOT_DIR


INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR
INCLUDEPATH += $$PHAON_GRAPH_SRC_GROUP_DIR/relae-phaon


CONFIG += no_keywords

DEFINES += USE_KANS


HEADERS += \
  $$SRC_DIR/hive-structure.h \
  $$SRC_DIR/_each-holders.h \
  $$SRC_DIR/_vec1d.h \
  $$SRC_DIR/vec1d.h \
  $$SRC_DIR/arr1d.h \
  $$SRC_DIR/stk1d.h \
  $$SRC_DIR/que1d.h \
  $$SRC_DIR/deq1d.h \
  $$SRC_DIR/desk1d.h \

SOURCES += \
  $$SRC_DIR/hive-structure.cpp \


#?LIBS += -L$$TARGETSDIR -lrelae-phaon


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

