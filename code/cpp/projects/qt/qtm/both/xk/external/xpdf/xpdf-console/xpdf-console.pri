
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app

INCLUDEPATH += $$SRC_GROUP_DIR


DEFINES += CAON_DEBUG
DEFINES += RELAE_LABEL_NODES


CONFIG += no_keywords

SOURCES += \
  $$SRC_DIR/main.cpp \



LIBS += -L$$TARGETSDIR -lxpdf -lfreetype #-lpdf-pull -ldsmain


#?contains(CHOICE_FEATURES, "pdf-pull") \#/
#?{
#? message(DEFINE\'ing USING_PDF_PULL)
#? DEFINES += USING_PDF_PULL
#? LIBS +=-L$$TARGETSDIR -lpdf-pull  \
#?   -ldsmain -lntxh -lntxh-builder -lntxh-parser
#?}


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)

