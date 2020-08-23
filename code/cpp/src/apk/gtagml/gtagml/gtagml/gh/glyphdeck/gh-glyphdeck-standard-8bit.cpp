
// licence_cpp

#include "gh-glyphdeck-standard-8bit.h"

GH_Glyphdeck_Standard_8bit::GH_Glyphdeck_Standard_8bit()
{

}


QString GH_Glyphdeck_Standard_8bit::get_latex_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 
 
 u1 ch = chars_[index];
}

QString GH_Glyphdeck_Standard_8bit::get_xml_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 ch = chars_[index];
}

QChar GH_Glyphdeck_Standard_8bit::get_qchar_representation(u4 index, QString& alternate)
{
 if(index >= chars_.size())
   return {}; 

 u1 ch = chars_[index];
}

QString GH_Glyphdeck_Standard_8bit::get_qstring_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 ch = chars_[index];
}


