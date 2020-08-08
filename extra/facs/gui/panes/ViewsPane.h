
// // license___here_h


#ifndef ViewsPane__H
#define ViewsPane__H

#include "view/tool/ViewToolChoice.h"


#include <QWidget>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QButtonGroup>
#include <QList>
#include <QScrollArea>

#include <QWidget>

// package facsanadu.gui.panes;

class ViewsMatrix;
class ViewToolChoice;

class MainWindow;


// //
class ViewsPane : public QWidget
{
 QSpinBox* spMaxEvents_; // =new QSpinBox();
 QCheckBox* cbMaxEvents_; // =new QCheckBox(tr("Show max events:"));

 ViewsMatrix* matrix_;

 QScrollArea* scrollArea_;

 QButtonGroup* bgroup_; //  =new QButtonGroup(this);

 QPushButton* bGateSelect_; // =new QPushButton(new QIcon(ImgResource.gateSelect),"");
 QPushButton* bGatePoly_; // =new QPushButton(new QIcon(ImgResource.gatePolygon),"");
 QPushButton* bGateRect_; // =new QPushButton(new QIcon(ImgResource.gateRect),"");
 QPushButton* bGateEllipse_; // =new QPushButton(new QIcon(ImgResource.gateEllipse),"");
 QPushButton* bGateRange_; // =new QPushButton(new QIcon(ImgResource.gateRange),"");
 
 QList<QPushButton*> tb_; // =new QPushButton[]{bGateSelect, bGatePoly, bGateRect, bGateEllipse, bGateRange};
 



public: 

 ViewsPane(MainWindow* mw);

 void test_one_view();

 void updateViews();
 void valuesupdated();
 void actionSetTool();
 void setTool(ViewToolChoice::Enum t);
 void invalidateCache();
};

#endif // __H

