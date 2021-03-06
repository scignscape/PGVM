

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

TEMPLATE = app

QT += widgets

INCLUDEPATH += $$SRC_DIR

#INCLUDEPATH += $$SRC_GROUP_DIR


FORMS  += \
  $$SRC_DIR/mainwindow.ui\
  $$SRC_DIR/options.ui\
  $$SRC_DIR/listtool.ui


HEADERS += \
  $$SRC_DIR/mainwindow.h\
  $$SRC_DIR/displayimage.h\
  $$SRC_DIR/projectwizard.h\
  $$SRC_DIR/options.h\
  $$SRC_DIR/listtool.h


SOURCES += \
  $$SRC_DIR/main.cpp\
  $$SRC_DIR/mainwindow.cpp\
  $$SRC_DIR/displayimage.cpp\
  $$SRC_DIR/projectwizard.cpp\
  $$SRC_DIR/options.cpp\
  $$SRC_DIR/listtool.cpp


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
