
// nc_license

#include <QDebug>

#include "cytolib/MemCytoFrame.hpp"

#include "bridge/qvector-matrix-r8.h"

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

 QVector_Matrix_R8* qvm = mcf.data_to_qvmatrix(); 

 r8 test = (*qvm)[2][3];

 qDebug() << "R: " << qvm->n_rows();
 qDebug() << "C: " << qvm->n_cols();

 qDebug() << "T: " << test;

 qvm->save_to_file(file_name + ".txt");
 
 qDebug() << "OK ...";

 

 return 0;
}


