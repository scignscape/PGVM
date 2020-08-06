
QT += widgets core 

TEMPLATE = app

INCLUDEPATH += \
 ./gui \

INCLUDEPATH += \
 . \
 ./cytolib/include \
 ./cytolib/armadillo \


INCLUDEPATH += \
  $$PROTOBUF_INSTALL/include


INCLUDEPATH += \
  $$LIBHDF5_INSTALL/include

INCLUDEPATH += \
  ./cytolib/hdf5/



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


OBJECTS_DIR = ../dest/objects/facs
DESTDIR = ../dest


message($$PROTOBUF_INSTALL)

#LIBS += -L$$PROTOBUF_INSTALL/lib -lprotobuf-lite

LIBS += /home/nlevisrael/hypergr/flowcy/protobuf/install/lib/libprotobuf-lite.a


LIBS += -L$$LIBHDF5_INSTALL/lib -lhdf5
LIBS += -lstdc++fs -llapack -llapacke -lblas 


LIBS += -L$$DESTDIR -lcytolib -lbridge



