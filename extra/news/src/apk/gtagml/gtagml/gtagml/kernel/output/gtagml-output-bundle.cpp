
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-output-bundle.h"

#include "kans.h"
USING_KANS(GTagML)

GTagML_Output_Bundle GTagML_Output_Bundle::with(QTextStream& new_qts) const
{
 return {new_qts, index, node, connection_descriptor, cb};
}

GTagML_Output_Bundle GTagML_Output_Bundle::with(GTagML_Connection_Descriptor descriptor) const
{
 return {qts, index, node, descriptor, cb};
}

GTagML_Output_Bundle GTagML_Output_Bundle::with(caon_ptr<tNode> n, GTagML_Connection_Descriptor descriptor) const
{
 return {qts, index, n, descriptor, cb};
}

GTagML_Output_Bundle GTagML_Output_Bundle::with_node(caon_ptr<tNode> n) const
{
 return {qts, index, n, connection_descriptor, cb};
}

GTagML_Output_Bundle GTagML_Output_Bundle::with_callback(caon_ptr<GTagML_Tag_Command_Callback> c) const
{
 return {qts, index, node, connection_descriptor, c};
}



