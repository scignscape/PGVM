
QT += widgets core 

TEMPLATE = app

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
 ./gui/view/tool/ViewTool.h \
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
 ./gui/view/gate/GateRendererPoly.cpp \
 ./gui/view/gate/GateRendererRange.cpp \
 ./gui/panes/CompensationPane.cpp \
 ./gui/panes/DatasetInfoPane.cpp \
 ./gui/panes/ViewsPane.cpp \
 ./gui/panes/GateStatsPane.cpp \
 ./gui/lengthprofile/ProfilePane.cpp \
 ./gui/lengthprofile/ProfileView.cpp \
 ./data/ExportFcsToCSV.cpp \
 ./data/ChannelInfo.cpp \
 ./gui/qt/QTutil.cpp \
 ./gui/resource/ImgResource.cpp \
 ./gui/colors/QColorCombo.cpp \
 ./gui/colors/ColorSet.cpp \
 ./transformations/TransformationStack.cpp \
 ./data/Dataset.cpp  \
 ./data/Compensation.cpp  \
 ./gui/panes/ViewsMatrix.cpp \
 ./gui/qt/QTableWidgetWithCSVcopy.cpp \
 ./gui/view/tool/ViewToolDrawEllipse.cpp \
 ./gui/view/tool/ViewToolDrawSelect.cpp \
 ./gui/view/tool/ViewToolDrawRange.cpp \
 ./gui/view/tool/ViewToolDrawRect.cpp \
 ./gui/view/tool/ViewToolDrawPoly.cpp \
 ./main.cpp \




DEFINES += DEFAULT_ICON_FOLDER=\\\"$$PWD/gui/resource\\\"

#


OBJECTS_DIR = ./build_qtc/objects
DESTDIR = ./build_qtc/dest
TARGETSDIR = ./build_qtc/targets


