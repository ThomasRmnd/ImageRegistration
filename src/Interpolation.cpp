#include <cmath>
#include <algorithm>
#include "Interpolation.h"

Doub Bilineaire::operator()(MatDoub_I& Im, Doub x, Doub y, Bool& OK) {
  int H = Im.nrows(), L = Im.ncols();
  if ((x<0) || (x>H-1) || (y<0) || y>L-1) {
    OK = false;
    return 0;
  }
  else {
    OK = true;
    int i1,i2,j1,j2;
    double dx,dy,dfx,dfy,dfxy,res;

    i1 = std::floor(x);
    j1 = std::floor(y);
    if (i1 == H-1)
      i1--;
    if (j1 == L-1)
      j1--;
    i2 = i1+1;
    j2 = j1+1;
    dx = x-i1;
    dy = y-j1;
    dfx = Im[i2][j1] - Im[i1][j1];
    dfy = Im[i1][j2] - Im[i1][j1];
    dfxy = Im[i1][j1] + Im[i2][j2] - Im[i2][j1] - Im[i1][j2];
    res = Im[i1][j1] + dfx * dx + dfy * dy + dx*dy*dfxy;
    return std::min(255,(int)std::round(res));
  }
}

Doub PlusProcheVoisin::operator()(MatDoub_I& Im, Doub x, Doub y, Bool& OK) {
  int H = Im.nrows(), L = Im.ncols();
  if ((x<0) || (x>H-1) || (y<0) || y>L-1) {
    OK = false;
    return 0;
  }
  else {
    OK = true;
    return Im[(int)std::round(x)][(int)std::round(y)];
  }
}
