
// licence_cpp

#include "gh-block-standard-8bit.h"

#include "glyphdeck/gh-glyphdeck-standard-8bit.h"

GH_Block_Standard_8bit::GH_Block_Standard_8bit()
 : glyphdeck_(new GH_Block_Standard_8bit)
{

}

QString GH_Block_Standard_8bit::get_latex_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 
 
 u1 code = chars_[index];

 QString result = glyphdeck_->get_latex_representation(ch);
 return result;
}

QString GH_Block_Standard_8bit::get_xml_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QString result = glyphdeck_->get_latex_representation(code);
 return result;
}

QChar GH_Block_Standard_8bit::get_qchar_representation(u4 index, QString& alternate)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QChar result = glyphdeck_->get_latex_representation(code, alternate);
 return result;
}

QString GH_Block_Standard_8bit::get_qstring_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QString result = glyphdeck_->get_latex_representation(code);
 return result;
}


