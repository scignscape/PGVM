
#include <QDebug>

#include "cytolib/MemCytoFrame.hpp"

//#include "src-temp/temp.cpp"

//extern void temp_test_cyto();

int main(int argc, char* argv[])
{
 cytolib::FCS_READ_HEADER_PARAM hp;
 cytolib::FCS_READ_DATA_PARAM dp;
 cytolib::FCS_READ_PARAM rp;


// test_cyto();

 //
 QString file_name = "/home/nlevisrael/hypergr/pgvm/ar/extra/facs/Live_cells.fcs";

 cytolib::MemCytoFrame mcf(file_name.toStdString(), rp);

 mcf.read_fcs();
 
 qDebug() << "OK ...";

 return 0;
}


