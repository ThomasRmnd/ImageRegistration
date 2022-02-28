#include "DeformeImage.h"

DeformeImage::DeformeImage(Interpolation* _methodeInter_, ApplyTransfo* _methodeTrans_) {
  methodeInter = _methodeInter_;
  methodeTrans = _methodeTrans_;
}

void DeformeImage::operator()(MatDoub_I& Im, MatDoub& ImRes, MatBool& ImMask, VecDoub_I& arg) const {
  int row = Im.nrows(), col = Im.ncols();
  for (int i=0; i<row;i++){
    for (int j=0;j<col;j++) {
      Doub x,y;
      Bool OK;
      methodeTrans->operator()(arg,i,j,x,y);
      ImRes[i][j] = methodeInter->operator()(Im,x,y,OK);
      ImMask[i][j] = OK;
    }
  }
}
