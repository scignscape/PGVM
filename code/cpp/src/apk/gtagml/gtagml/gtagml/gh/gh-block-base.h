
// licence_h

#ifndef GH_BLOCK_BASE__H
#define GH_BLOCK_BASE__H

#include "global-types.h"

#include <QChar>
#include <QString>
 

class GH_Block_Base
{
public:

 GH_Block_Base();

 virtual QString get_latex_representation(u4 index) = 0;
 virtual QString get_xml_representation(u4 index) = 0;
 virtual QChar get_qchar_representation(u4 index, QString& alternate) = 0;
 virtual QString get_qstring_representation(u4 index) = 0;

};


#endif // GH_BLOCK_BASE__H


