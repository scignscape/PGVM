
// licence_cpp

#include "gh-block-standard-8bit.h"

#include "glyphdeck/gh-glyphdeck-standard-8bit.h"

GH_Block_Standard_8bit::GH_Block_Standard_8bit()
 : glyphdeck_(new GH_Block_Standard_8bit)
{

}

QString GH_Block_Standard_8bit::get_latex_representation(u4 index)
{
 QString result = glyphdeck_->get_latex_representation(index);
 return result;
}

QString GH_Block_Standard_8bit::get_xml_representation(u4 index)
{
 QString result = glyphdeck_->get_latex_representation(index);
 return result;
}

QChar GH_Block_Standard_8bit::get_qchar_representation(u4 index, QString& alternate)
{
 QChar result = glyphdeck_->get_latex_representation(index, alternate);
 return result;
}

QString GH_Block_Standard_8bit::get_qstring_representation(u4 index)
{
 QString result = glyphdeck_->get_latex_representation(index);
 return result;
}


