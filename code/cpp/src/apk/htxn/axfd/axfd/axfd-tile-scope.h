
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef AXFD_TILE_SCOPE__H
#define AXFD_TILE_SCOPE__H

#include "accessors.h"

#include "global-types.h"

#include "flags.h"

#include "kans.h"

#include <QString>
#include <QList>
#include <QDate>

#include <functional>

#include "global-types.h"


class QTextStream;

KANS_(AXFD)

class Glyph_Layer_8b;

struct AXFD_Tile
{
 u4 enter;
 u4 leave;
}; 

class AXFD_Tile_Scope
{ 
 union Scope_Element {
   AXFD_Tile tile;
   AXFD_Tile_Scope* scope;
 };

 QVector<Scope_Element> elements_;

 AXFD_Tile_Scope();
};

_KANS(HTXN)

#endif // AXFD_TILE_SCOPE__H


