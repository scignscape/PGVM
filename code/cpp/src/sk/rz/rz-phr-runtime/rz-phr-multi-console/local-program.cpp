
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "phaon-ir/phaon-ir.h"

#include "phaon-ir/phr-code-model.h"
#include "phaon-ir/scopes/phr-runtime-scope.h"

#include "phr-direct-eval/phr-direct-eval.h"
#include "phaon-ir/table/phr-symbol-scope.h"
#include "phaon-ir/table/phr-channel-group-table.h"

#include "basic-functions.h"

#include "phr-fn-doc/phr-fn-doc.h"
#include "phr-fn-doc/phr-fn-doc-multi.h"

#include "phr-env/phr-env.h"

#include <QDebug>


USING_KANS(Phaon)


extern void* insert_envv(void* kind, void* test);

extern void init_basic_functions(PhaonIR& phr, PHR_Code_Model& pcm,
  PHR_Channel_Group_Table& table, PHR_Symbol_Scope& pss);

void local_program(PhaonIR& phr, QString phrf)
{
 phr.init_type_system();
 phr.init_type("fbase", DEFAULT_PTR_BYTE_CODE);
 phr.init_type("u4", 4);
 phr.init_type("u8", 8);
 phr.init_type("argvec", 9);
 phr.init_type("pcv", DEFAULT_PTR_BYTE_CODE);
 phr.init_type("str", DEFAULT_PTR_BYTE_CODE);

 qRegisterMetaType<PHR_Fn_Doc>();
 qRegisterMetaType<PHR_Fn_Doc*>();

 qRegisterMetaType<PHR_Fn_Doc_Multi>();
 qRegisterMetaType<PHR_Fn_Doc_Multi*>();

 // //  setup
 phr.init_code_model();

 PHR_Code_Model& pcm = *phr.code_model();
 pcm.set_type_system(phr.type_system());

 phr.create_channel_semantic_protocol("lambda");
 phr.create_channel_semantic_protocol("result");
 phr.create_channel_semantic_protocol("sigma");

 pcm.set_direct_eval_fn(&phr_direct_eval);

 pcm.create_and_register_type_object("PHR_Fn_Doc*");
 pcm.create_and_register_type_object("PHR_Fn_Doc_Multi*");

 PHR_Env* penv = new PHR_Env(&pcm);
 QString penv_typename = "PHR_Env*";
 insert_envv(&penv_typename, penv);

 pcm.create_and_register_type_object("PHR_Env*");

 penv->set_report_channel_group_fn([](PHR_Code_Model* pcm, PHR_Channel_Group* pcg)
  {
   QString qs;
   QTextStream qts(&qs);

   pcm->report_channel_group(qts, *pcg, pcm->detailed_report_synax(),
     PHR_Code_Model::Code_Environments::Statement);

   qDebug() << qs;
  });

 PHR_Runtime_Scope prs(nullptr);

 PHR_Symbol_Scope pss(&prs);

 phr.init_table();

 init_basic_functions(phr, pcm, *phr.table(), pss);

 phr.hold_symbol_scope(&pss);
 phr.read_local_program(phrf);

}

void local_program(PhaonIR& phr, QStringList& progs, QString topl)
{
 phr.init_type_system();
 phr.init_type("fbase", DEFAULT_PTR_BYTE_CODE);
 phr.init_type("u4", 4);
 phr.init_type("u8", 8);
 phr.init_type("argvec", 9);
 phr.init_type("pcv", DEFAULT_PTR_BYTE_CODE);
 phr.init_type("str", DEFAULT_PTR_BYTE_CODE);

 qRegisterMetaType<PHR_Fn_Doc>();
 qRegisterMetaType<PHR_Fn_Doc*>();

 // //  setup
 phr.init_code_model();

 PHR_Code_Model& pcm = *phr.code_model();
 pcm.set_type_system(phr.type_system());

 phr.create_channel_semantic_protocol("lambda");
 phr.create_channel_semantic_protocol("result");
 phr.create_channel_semantic_protocol("sigma");

 pcm.set_direct_eval_fn(&phr_direct_eval);

 pcm.create_and_register_type_object("PHR_Fn_Doc*");

 PHR_Env* penv = new PHR_Env(&pcm);
 QString penv_typename = "PHR_Env*";
 insert_envv(&penv_typename, penv);

 pcm.create_and_register_type_object("PHR_Env*");

 penv->set_report_channel_group_fn([](PHR_Code_Model* pcm, PHR_Channel_Group* pcg)
 {
  QString qs;
  QTextStream qts(&qs);

  pcm->report_channel_group(qts, *pcg, pcm->detailed_report_synax(),
                            PHR_Code_Model::Code_Environments::Statement);

  qDebug() << qs;
 });

 PHR_Runtime_Scope prs(nullptr);

 PHR_Symbol_Scope pss(&prs);

 phr.init_table();

 init_basic_functions(phr, pcm, *phr.table(), pss);

 phr.hold_symbol_scope(&pss);

 // //  setup

 for(QString prog : progs)
 {
  qDebug() << "\nReading " << prog;
  phr.read_local_program(prog);

  phr.reset();
 }

}

