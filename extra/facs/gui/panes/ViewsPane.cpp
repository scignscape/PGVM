
// // license___here

#include "ViewsPane.h"

#include "ViewsMatrix.h"

#include "../resource/ImgResource.h"

#include <QHBoxLayout>

// package facsanadu.gui.panes;


// //

ViewsPane::ViewsPane(MainWindow* mw)
// :  mw_(mw)
{
 spMaxEvents_ = new QSpinBox();
 cbMaxEvents_ = new QCheckBox(tr("Show max events:"));

 matrix_ = new ViewsMatrix(mw);
 bgroup_ = new QButtonGroup(this);

 bGateSelect_ = new QPushButton(QIcon(ImgResource::gateSelect()),"");
 bGatePoly_ = new QPushButton(QIcon(ImgResource::gatePolygon()),"");
 bGateRect_ = new QPushButton(QIcon(ImgResource::gateRect()),"");
 bGateEllipse_ = new QPushButton(QIcon(ImgResource::gateEllipse()),"");
 bGateRange_ = new QPushButton(QIcon(ImgResource::gateRange()),"");
 QList<QPushButton*> tb {bGateSelect_, bGatePoly_, 
   bGateRect_, bGateEllipse_, bGateRange_};
  
 for(QPushButton* t : tb)
 {
  bgroup_->addButton(t);
 }

 for(QPushButton* t : tb)
 {
  t->setCheckable(true);
 }

 bGateSelect_->setChecked(true);
 
// for(QPushButton* t : tb)
// {
  //t.toggled.connect(this,"actionSetTool()");
// }
  
 spMaxEvents_->setMinimum(100);
 spMaxEvents_->setMaximum(10000000);
 spMaxEvents_->setValue(100000);
 cbMaxEvents_->setChecked(true);
  
 QHBoxLayout* laytop = new QHBoxLayout();
 
 for(QPushButton* t : tb)
 {
  laytop->addWidget(t);
 }

 laytop->addStretch();
 laytop->addWidget(cbMaxEvents_);
 laytop->addWidget(spMaxEvents_);
 laytop->setMargin(2);
 laytop->setSpacing(2);  
  
 scrollArea_ = new QScrollArea();
 scrollArea_->setWidgetResizable(true);
 scrollArea_->setWidget(matrix_);
 scrollArea_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
 scrollArea_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

 QVBoxLayout* lay = new QVBoxLayout();
 lay->addLayout(laytop);
 lay->addWidget(scrollArea_);
 lay->setMargin(0);
 lay->setSpacing(2);
 setLayout(lay);
  
//? spMaxEvents.valueChanged.connect(this,"valuesupdated()");
//? cbMaxEvents.stateChanged.connect(this,"valuesupdated()");
 valuesupdated();
}

void ViewsPane::test_one_view()
{
 matrix_->test_one_view();
}

void ViewsPane::updateViews()
{
 matrix_->updateViews();
}

void ViewsPane::valuesupdated()
{
 int maxevents = std::numeric_limits<int>::max();
 if(cbMaxEvents_->isChecked())
   maxevents = spMaxEvents_->value();
 matrix_->setMaxEvents(maxevents);
}

void ViewsPane::actionSetTool()
{
 if(bgroup_->checkedButton() == bGatePoly_)
   setTool(ViewToolChoice::POLY);
 else if(bgroup_->checkedButton() == bGateSelect_)
   setTool(ViewToolChoice::SELECT);
 else if(bgroup_->checkedButton() == bGateRect_)
   setTool(ViewToolChoice::RECT);
 else if(bgroup_->checkedButton() == bGateEllipse_)
   setTool(ViewToolChoice::ELLIPSE);
 else if(bgroup_->checkedButton() == bGateRange_)
   setTool(ViewToolChoice::RANGE);
}

void ViewsPane::setTool(ViewToolChoice::Enum t)
{
 if(t == ViewToolChoice::SELECT)
   bGateSelect_->setChecked(true);
 else if(t == ViewToolChoice::POLY)
   bGatePoly_->setChecked(true);
 else if(t == ViewToolChoice::RECT)
   bGateRect_->setChecked(true);
 matrix_->setTool(t);
}

 
void ViewsPane::invalidateCache()
{
 matrix_->invalidateCache();
}


