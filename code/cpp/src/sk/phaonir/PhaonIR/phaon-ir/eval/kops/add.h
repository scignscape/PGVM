
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef ADD__H
#define ADD__H

#include <QVector>

#include "eval/kop-base.h"

#include "kans.h"

KANS_(Phaon)


struct PHR_KOP_Add : PHR_KOP_Base<qint32>
{

public:

 PHR_KOP_Add();

 void run_eval(QPair<qint32, qint32>& args, qint32& result);
 void run_eval(QVector<qint32>& args, qint32& result);

};

_KANS(Phaon)

#endif // ADD__H
