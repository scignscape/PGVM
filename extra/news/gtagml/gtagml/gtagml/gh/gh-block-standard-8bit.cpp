
// licence_cpp

#include "gh-block-standard-8bit.h"

#include "gh-block-parse-mode.h"

#include "glyphdeck/gh-glyphdeck-standard-8bit.h"

#include <QTextStream>

GH_Block_Standard_8bit::GH_Block_Standard_8bit()
 :  current_index_(1), glyphdeck_(new GH_Glyphdeck_Standard_8bit)
    //parse_mode_(new GH_Block_Parse_Mode(247))
{
 parse_mode_ = new GH_Block_Parse_Mode(glyphdeck_->get_default_null());
 chars_.push_back(glyphdeck_->get_default_void_separator());
 chars_.push_back(glyphdeck_->get_default_void_separator());
}

u8 GH_Block_Standard_8bit::get_glyph_point_at_index(u4 i)
{
 if(i > chars_.size())
   return chars_.value(0, glyphdeck_->get_default_null());
 return chars_.at(i);
}

GH_Block_Base::SDI_Interpretation_Codes GH_Block_Standard_8bit::get_sdi_interpretation_code_at_index(u4 i)
{
 u8 u = get_glyph_point_at_index(i);
 return glyphdeck_->get_sdi_interpretation_code((u1) u);
}

void GH_Block_Standard_8bit::write(QString text, QPair<u4, u4>& result)
{
 QByteArray qba = text.toLatin1();
 write(qba, result);
}

QPair<u4, u4> GH_Block_Standard_8bit::get_effective_start_and_end_indices()
{
 return {2, chars_.size() - 1};
}

QString GH_Block_Standard_8bit::get_latex_out(const QPair<u4, u4>& indices)
{
 QString result;
 QTextStream qts(&result);
 for(u4 u = indices.first; u <= indices.second; ++u)
   qts << get_latex_representation(u);
 return result;
}

void GH_Block_Standard_8bit::write(QByteArray& text, QPair<u4, u4>& result)
{

 if(text.isEmpty())
 {
  result.first = current_index_;
  result.second = current_index_ - 1;
  return;
 }
 result.first = current_index_ + 1;
 for(u1 u : text)
 {
  u1 check = parse_mode_->check_hold(u);
  if(check)
  {
   // // todo fewer raw numbers ...
   if(check == 200)
     continue;
   if(check > 200)
   {
    check -= 200;
    for(u1 uu = 0; uu < check; ++uu)
    {
     ++current_index_;
     chars_.push_back((u1) parse_mode_->release_glyph_point());
    }
   }
   if(check > 100)
   {
    check -= 100;
    for(u1 uu = 0; uu < check; ++uu)
    {
     ++current_index_;
     QPair<u1, u1> pr;
     parse_mode_->release_cancel_or_alt_char(pr);
     chars_.push_back(glyphdeck_->encode_alt_pair(pr));
    }
   }
   continue;
  }
//  parse_mode_->

  //  switch(parse_mode_)
//  {

//  }
  ++current_index_;
  u1 uu = glyphdeck_->encode_latin1(u);
  chars_.push_back(uu);
 }
 result.second = current_index_;
}

QString GH_Block_Standard_8bit::get_latex_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 
 
 u1 code = chars_[index];

 QString result = glyphdeck_->get_latex_representation(code);
 return result;
}

QString GH_Block_Standard_8bit::get_xml_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QString result;// = glyphdeck_->get_xml_representation(code);
 return result;
}

QChar GH_Block_Standard_8bit::get_qchar_representation(u4 index, QString& alternate)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QChar result;// = glyphdeck_->get_latex_representation(code);//, alternate);
 return result;
}

QString GH_Block_Standard_8bit::get_qstring_representation(u4 index)
{
 if(index >= chars_.size())
   return {}; 

 u1 code = chars_[index];

 QString result;// = glyphdeck_->get_latex_representation(code);
 return result;
}


