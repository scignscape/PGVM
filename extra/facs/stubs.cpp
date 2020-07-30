

// // license___here_h


#include "gui/panes/ViewsPane.h"
#include "gui/panes/GateStatsPane.h"
#include "gui/lengthprofile/ProfilePane.h"
#include "gui/panes/CompensationPane.h"
#include "resource/ImgResource.h"

#include "gui/view/GraphExporter.h"

#include "data/Dataset.h"
#include "data/ProfChannel.h"

#include "gates/GateSet.h"
#include "gates/gate-info.h"
#include "gates/measure/GateMeasure.h"


#include <QList>

class QFile; 
class FacsanaduProject;
class Dataset; 
class ViewSettings;


QList<Gate*> Gate::children() const
{
 return {};
}

void Gate::attachChild(Gate* g)
{
 Q_UNUSED(g)
}

void Gate::setUpdated() {}
void Gate::detachParent() {}

void GateMeasure::detachFromGate() {}
void Gate::attachMeasure(GateMeasure*) {}

void Dataset::computeProfChannel(FacsanaduProject*, ProfChannel*)
{
}

QString Dataset::get_file_source_name()
{
 return {};
}


QSet<QString> GateSet::getGateNames()
{
 return {};
}

QString GateSet::getFreeName()
{
 return {};
}


QList<ChannelInfo*> Dataset::getChannelInfo()
{
 return {};
}

QString ProfChannel::getName()
{
 return "?";
}


QString Dataset::getName()
{
 return "?";
}

//void ImgResource::setWindowIcon(QWidget*){}

void GraphExporter::render(QFile&, FacsanaduProject*, QList<Dataset*>,
  QList<ViewSettings*>, bool, bool, int, int){}

//void ViewsPane::updateViews(){}

//void GateStatsPane::updateStats() {}

//void ProfilePane::updateViews(){}

//void CompensationPane::updateForm(){}

// void ViewsPane::invalidateCache(){}

//?int GateCalcThread::getNumCores(){ return 1; }
//?void GateCalcThread::setNumCores(int){ }









