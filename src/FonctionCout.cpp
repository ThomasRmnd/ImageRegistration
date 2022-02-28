#include "FonctionCout.h"

FonctionCout::FonctionCout(Similarity* _methodeSim_, DeformeImage* _methodeDeforme_, ReadFromFile* _methodeRead_) {
  methodeSim = _methodeSim_;
  methodeDeforme = _methodeDeforme_;
  methodeRead = _methodeRead_;
  methodeRead->operator()(Im,ImRef);
}

Doub FonctionCout::operator()(VecDoub_I& arg) const {
  int row = Im.nrows(), col = Im.ncols();
  MatDoub ImRes(row,col,0.);
  
  MatBool ImMask(row,col,false);
  methodeDeforme->operator()(Im,ImRes,ImMask,arg);
  Doub result = methodeSim->operator()(ImRes,ImMask,ImRef);
  
  // Affichage des résulats intermédiaires
  // std::cout << "tx = " << arg[0] << " " << "ty = " << arg[1] << " " << "theta = " << arg[2] << std::endl;
  // std::cout << result << std::endl;
  
  return result;
}
