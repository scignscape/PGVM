
QT += widgets core 

INCLUDEPATH += \
 ./gui \


HEADERS += \
 ./gui/MainWindow.h  \


SOURCES +=  \
 ./stubs.cpp \
 ./gui/MainWindow.cpp  \
 ./gui/ViewsListWidget.cpp  \
 ./gui/QtProgramInfo.cpp  \
 ./gui/ProfileChannelWidget.cpp  \
 ./gui/GraphExportWindow.cpp  \
 ./gui/GatesListWidget.cpp \   # skip calc thread ...
 ./gui/FacsanaduProject.cpp \
 ./gui/DialogAbout.cpp \
 ./gui/DatasetListWidget.cpp \
 ./gui/AddMeasureDialog.cpp \
 ./gui/view/ViewWidget.cpp \
 ./gui/view/tool/ViewToolChoice.cpp \
 ./gui/view/ViewTransform.cpp \
 ./gui/view/ViewSettings.cpp \
 ./gui/view/ViewRenderer.cpp \
 ./gui/view/Histogram.cpp \   # skip graph exporter ...
 ./gui/view/gate/GateRendererManager.cpp \
 ./gui/view/gate/GateRendererRoot.cpp \
 ./gui/view/gate/GateRendererRect.cpp \
 ./gui/view/gate/GateRendererEllipse.cpp \
 ./gui/panes/CompensationPane.cpp \
 ./gui/panes/DatasetInfoPane.cpp \
 ./gui/panes/ViewsPane.cpp \
 ./gui/panes/GateStatsPane.cpp \
 ./gui/lengthprofile/ProfilePane.cpp \


#


OBJECTS_DIR = ./build/objects
DESTDIR = ./build/dest
TARGETSDIR = ./build/targets


