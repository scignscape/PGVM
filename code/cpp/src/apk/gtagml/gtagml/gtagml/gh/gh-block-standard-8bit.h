
// licence_h

#ifndef GH_BLOCK_STANDARD_8BIT__H
#define GH_BLOCK_STANDARD_8BIT__H

#include "gh-block-base.h"

#include "global-types.h"

#include <QVector>

class GH_Block_Standard_8bit : GH_Block_Base 
{
 QVector<u1> chars_;

public:

 GH_Block_Standard_8bit();

};


#endif // GH_BLOCK_STANDARD_8BIT__H


