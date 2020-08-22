
// licence_cpp

#include "gh-block-standard-8bit.h"

#include "codex/gh-codex-standard-8bit.h"

GH_Block_Standard_8bit::GH_Block_Standard_8bit()
 : codex_(new GH_Codex_Standard_8bit)
{

}

QString GH_Block_Standard_8bit::get_latex_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 
 
 u1 ch = chars_[index];
}

QString GH_Block_Standard_8bit::get_xml_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 ch = chars_[index];
}

QChar GH_Block_Standard_8bit::get_qchar_representation(u4 index, QString& alternate)
{
 if(index >= chars_.size())
   return {}; 

 u1 ch = chars_[index];
}

QString GH_Block_Standard_8bit::get_qstring_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 ch = chars_[index];
}


