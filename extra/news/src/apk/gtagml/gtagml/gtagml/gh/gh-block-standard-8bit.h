
// licence_h

#ifndef GH_BLOCK_STANDARD_8BIT__H
#define GH_BLOCK_STANDARD_8BIT__H

#include "gh-block-base.h"

#include "global-types.h"

#include <QVector>

class GH_Glyphdeck_Standard_8bit;
class GH_Block_Parse_Mode;

class GH_Block_Standard_8bit : public GH_Block_Base
{
 QVector<u1> chars_;

 u4 current_index_;

 GH_Glyphdeck_Standard_8bit* glyphdeck_;

 GH_Block_Parse_Mode* parse_mode_;


public:

 GH_Block_Standard_8bit();

 void write(QString text, QPair<u4, u4>& result) Q_DECL_OVERRIDE;
 void write(QByteArray& text, QPair<u4, u4>& result);

 QString get_latex_out(const QPair<u4, u4>& indices) Q_DECL_OVERRIDE;

 QString get_latex_representation(u4 index) Q_DECL_OVERRIDE;
 QString get_xml_representation(u4 index) Q_DECL_OVERRIDE;
 QChar get_qchar_representation(u4 index, QString& alternate) Q_DECL_OVERRIDE;
 QString get_qstring_representation(u4 index) Q_DECL_OVERRIDE;


};


#endif // GH_BLOCK_STANDARD_8BIT__H


