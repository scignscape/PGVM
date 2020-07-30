
QT += widgets core 

INCLUDEPATH += \
 ./gui \


HEADERS += \
 ./gui/MainWindow.h  \
 ./gui/DatasetListWidget.h  \
 ./gui/GatesListWidget.h \
 ./gates/gate-info.h \
 ./gates/measure/GateMeasure.h \
 ./gates/measure/GateMeasureMean.h \
 ./gui/view/ViewWidget.h \
 ./gui/view/tool/ViewToolDrawEllipse.h \
 ./gui/view/tool/ViewToolDrawSelect.h \
 ./gui/view/tool/ViewToolDrawRange.h \
 ./gui/view/tool/ViewToolDrawRect.h \
 ./gui/view/tool/ViewToolDrawPoly.h \






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
 ./data/ExportFcsToCSV.cpp \
 ./data/ChannelInfo.cpp \
 ./gui/qt/QTutil.cpp \
 ./gui/resource/ImgResource.cpp \
 ./gui/colors/QColorCombo.cpp \


DEFINES += DEFAULT_ICON_FOLDER=\\\"$$PWD/gui/resource\\\"

#


OBJECTS_DIR = ./build/objects
DESTDIR = ./build/dest
TARGETSDIR = ./build/targets


