
// licence_h

#ifndef GH_CODEX_STANDARD_8BIT__H
#define GH_CODEX_STANDARD_8BIT__H

#include "gh-block-base.h"

class GH_Codex_Standard_8bit // : GH_Block_Base 
{
public:

 GH_Codex_Standard_8bit();

 QString get_latex_representation(u4 index);
 QString get_xml_representation(u4 index);
 QChar get_qchar_representation(u4 index, QString& alternate);
 QString get_qstring_representation(u4 index);


};


#endif // GH_CODEX_STANDARD_8BIT__H


