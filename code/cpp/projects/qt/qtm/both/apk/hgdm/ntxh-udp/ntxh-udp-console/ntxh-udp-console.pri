
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = ntxh-udp-console

include(../build-group.pri)

TEMPLATE = app

INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR


INCLUDEPATH += $$KAUVIR_PHAON_SRC_GROUP_DIR
INCLUDEPATH += $$KAUVIR_KCM_SRC_GROUP_DIR
INCLUDEPATH += $$QHYP_SRC_GROUP_DIR
INCLUDEPATH += $$KCM_RUNTIME_EVAL_SRC_GROUP_DIR
INCLUDEPATH += $$KAUVIR_RUNTIME_SRC_GROUP_DIR

INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR


CONFIG += no_keywords


DEFINES += USE_KANS

DEFINES += CONLLU_DIR=\\\"$$DATA_ROOT_DIR/conllu\\\"

INCLUDEPATH += $$SRC_GROUP_DIR/

INCLUDEPATH += $$QRING_SRC_GROUP_DIR
INCLUDEPATH += $$UDPIPE_SRC_GROUP_DIR $$UDPIPE_SRC_GROUP_DIR/udpipe

TEMPLATE = app


SOURCES += \
    $$SRC_DIR/main.cpp \


LIBS += -L$$TARGETSDIR -ludpipe -lqring \
   -lntxh -lntxh-udp -lntxh-parser

