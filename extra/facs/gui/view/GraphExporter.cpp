
// // license___here

#include "GraphExporter.h"


// package facsanadu.gui.view;


void GraphExporter::render(File f, FacsanaduProject proj, LinkedList<Dataset> listds, LinkedList<ViewSettings> listviews, 
  boolean splitDS, boolean splitView, int onew, int oneh)
{
 String basename=f.getName();
 basename=basename.substring(0,basename.indexOf('.'));
 File basedir=new File(f.getParent());
 String ext=".png";
 if(splitView)
 {
  if(splitDS)
  {
  //All separate
   for(Dataset ds:listds)
   {
    for(ViewSettings view:listviews)
    {
     render(new File(basedir,basename+"-"+ds.getName()+"-"+view.getName()+ext),proj,Arrays.asList(ds), Arrays.asList(view), onew, oneh);
    }
   }
  }
  else
  {
   //Split by view only
   for(ViewSettings view:listviews)
   {
    render(new File(basedir,basename+"-"+view.getName()+ext),proj,listds, Arrays.asList(view), onew, oneh);
   }
  }
 }
 else
 {
  if(splitDS)
  {
   //Split by dataset only
   for(Dataset ds:listds)
   {
    render(new File(basedir,basename+"-"+ds.getName()+"-"+ext),proj,Arrays.asList(ds), listviews, onew, oneh);
   }
  }
  else
  {
   //All together
   render(f, proj, listds, listviews, onew, oneh);
  }
 }
}
 

 /**
 * Render everything to one image
 */
void GraphExporter::render(File f, FacsanaduProject proj, List<Dataset> listds, List<ViewSettings> listviews, int onew, int oneh)
{
 int spacing=20;
  
 int totw=listds.size()*(onew+spacing)+spacing;
 int toth=listviews.size()*(oneh+spacing)+spacing;
 QImage img=new QImage(totw,toth, Format.Format_RGB32);
 QPainter pm=new QPainter(img);
 pm.setBrush(new QBrush(QColor.white));
 pm.drawRect(-5, -5, totw+10, toth+10);
 
 int offsetX=30;
 
 //Draw the images
 for(int i=0;i<listds.size();i++)
 {
  for(int j=0;j<listviews.size();j++)
  {
   ViewTransform trans=new ViewTransform();
   trans.viewsettings=listviews.get(j);
   trans.setTotalWidth(onew);
   trans.setTotalHeight(oneh);
  
   pm.save();
   pm.translate((onew+spacing)*i+offsetX, (oneh+spacing)*j+offsetX);
   pm.setClipping(true);
   pm.setClipRect(0,0,onew,oneh);
  
  
   Dataset ds=listds.get(i);
   ViewSettings vs=listviews.get(j);
   ViewRenderer.renderData(vs, ds, proj.getGatingResult(ds), trans, pm,  Integer.MAX_VALUE);
   ViewRenderer.renderGates(vs, ds, proj.getGatingResult(ds), trans, pm, new  LinkedList<GateHandle>(), Integer.MAX_VALUE);
   pm.restore();
  }
 }
 
 //Draw the labels
 pm.setPen(QColor.black);
 QFont font=new QFont();
 font.setBold(true);
 pm.setFont(font);
 int texth=15;
 for(int i=0;i<listds.size();i++)
 {
  int midx=(onew+spacing)*i+offsetX+onew/2;
  String txt=listds.get(i).source.getName();
  QFontMetrics fm=pm.fontMetrics();
  pm.drawText(new QPointF(midx-fm.boundingRect(txt).width()/2, texth), txt);
 }
 pm.save();
 pm.rotate(-90);
 for(int i=0;i<listviews.size();i++)
 {
  int midy=(oneh+spacing)*i+offsetX+oneh/2;
  String txt=listviews.get(i).gate.name;
  QFontMetrics fm=pm.fontMetrics();
  pm.drawText(new QPointF(-midy-fm.boundingRect(txt).width()/2, texth), txt);
 }
 pm.restore();
 
 pm.end();
  
 new QImageWriter(f.getAbsolutePath()).write(img);
}

