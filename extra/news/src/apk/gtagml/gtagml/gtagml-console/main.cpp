
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include "gtagml/kernel/document/gtagml-document.h"
#include "get-cmdl.h"

#include "gtagml/output/gtagml-output-latex.h"
#include "gtagml/output/gtagml-output-blocks.h"
#include "gtagml/output/gtagml-output-infoset.h"

USING_KANS(GTagML)
USING_KANS(Util)


void process_gtagml_file(QString path)
{
 qDebug() << "Processing file: " << path;

// GTagML_Document gdoc;
// gdoc.load_and_parse(path);

// GTagML_Output_Blocks gob(gdoc);
// gob.init_standard_8bit();
// gob.export_blocks(); //(path + ".");


// GTagML_Output_Latex gol(gdoc);
// gol.export_latex(path + ".tex");

 GTagML_Document* gdoc = new GTagML_Document;
 gdoc->load_and_parse(path);

 GTagML_Output_Blocks* gob = new GTagML_Output_Blocks(*gdoc);
 gob->init_standard_8bit();
 gob->export_blocks(); //(path + ".");

 GTagML_Output_Infoset* goi = new GTagML_Output_Infoset(*gdoc);
 //goi->init_standard_8bit();
 goi->export_infoset(path + ".info.txt"); // export_blocks(); //(path + ".");

 GTagML_Output_Latex* gol = new GTagML_Output_Latex(*gdoc);
 gol->export_latex(path + ".tex");

}



int main(int argc, char *argv[])
{
 QString folder;// = cmdl.size() > 2? cmdl[2]: DEFAULT_SDI_FOLDER;
 QString file;// = cmdl.size() > 3? cmdl[3]: DEFAULT_SDI_FOLDER
 QString manfolder;

 QStringList cmdl = get_cmdl(argc, argv, 2, {
   {&folder, DEFAULT_GTAGML_DIRECTORY},
   {&file, DEFAULT_GTAGML_DIRECTORY "/t1/t1.gt"},
   {&manfolder, {}}
   });

//? folder = "/home/nlevisrael/hypergr/ntxh-ngml/ar/htxn/sdi-test/t9";
//? file = "/home/nlevisrael/hypergr/ntxh-ngml/ar/htxn/sdi-test/t9/t9.ngml";

 qDebug() << "Folder: " << folder << ", File: " << file;
 qDebug() << "ManFolder: " << manfolder;

 if(manfolder.isEmpty())
 {
  if(file.isEmpty())
  {
   // process whole folder ...
//   NGML_Folder fld(folder);
//   fld.convert_to_latex();
  }
  else
    process_gtagml_file(file);
 }
 else
 {
//  NGML_Folder fld(folder, file, manfolder);
//  fld.convert_to_latex(&process_ngml_file);
 }
 return 0;
}

