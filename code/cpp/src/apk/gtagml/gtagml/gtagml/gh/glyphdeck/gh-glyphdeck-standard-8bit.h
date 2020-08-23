
// licence_h

#ifndef GH_GLYPHDECK_STANDARD_8BIT__H
#define GH_GLYPHDECK_STANDARD_8BIT__H

#include "gh-block-base.h"

class GH_Glyphdeck_Standard_8bit // : GH_Block_Base 
{
public:

 GH_Glyphdeck_Standard_8bit();

 u1 get_basic_char(u1 gp);
 u1 get_char_with_diacritic(u1 gp);
 u1 get_non_alphanumeric_char(u1 gp);

 QString get_latex_representation(u1 gp);
 QString get_xml_representation(u1 gp);
 QChar get_qchar_representation(u1 gp, QString& alternate);
 QString get_qstring_representation(u1 gp);


};


#endif // GH_GLYPHDECK_STANDARD_8BIT__H


