
// licence_cpp

#include "gh-codex-standard-8bit.h"

GH_Codex_Standard_8bit::GH_Codex_Standard_8bit()
{

}

QString GH_Codex_Standard_8bit::get_latex_representation(u4 index)
{
 QString result = codex_->get_latex_representation(index);
 return result;
}

QString GH_Codex_Standard_8bit::get_xml_representation(u4 index)
{
 QString result = codex_->get_latex_representation(index);
 return result;
}

QChar GH_Codex_Standard_8bit::get_qchar_representation(u4 index, QString& alternate)
{
 QChar result = codex_->get_latex_representation(index, alternate);
 return result;
}

QString GH_Codex_Standard_8bit::get_qstring_representation(u4 index)
{
 QString result = codex_->get_latex_representation(index);
 return result;
}


