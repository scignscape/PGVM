
// licence_h

#ifndef GH_BLOCK_BASE__H
#define GH_BLOCK_BASE__H

#include "global-types.h"

#include <QPair>
#include <QMap>
#include <QString>
 

class GH_Block_Base
{
protected:

 QMap<QString, QPair<u4, u4>>* cache_;

public:

 GH_Block_Base();

 virtual void check_cached(QString key, QPair<u4, u4>& result);
 virtual void write(QString text, QPair<u4, u4>& result) = 0;

 virtual void activate_cache();

 virtual QString get_latex_out(const QPair<u4, u4>& indices) = 0;

 virtual QString get_latex_representation(u4 index) = 0;
 virtual QString get_xml_representation(u4 index) = 0;
 virtual QChar get_qchar_representation(u4 index, QString& alternate) = 0;
 virtual QString get_qstring_representation(u4 index) = 0;

};


#endif // GH_BLOCK_BASE__H


