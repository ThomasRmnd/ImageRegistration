#include <cmath>
#include "Similarity.h"

Doub MoindreCarre::operator()(MatDoub_I& Im, MatBool_I& ImMask, MatDoub_I& ImRef) {
  int row = Im.nrows(), col = Im.ncols();
  int N = 0;
  Doub sum = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (ImMask[i][j]) {
        sum += std::pow(ImRef[i][j] - Im[i][j],2.);
        N++;
      }
    }
  }
  sum /= N;
  return sum;
}

Doub InformationMutuelle::operator()(MatDoub_I& Im_1, MatBool_I& Im_1_Mask, MatDoub_I& Im_2) {
	
  MatDoub Im_1_copy(Im_1);
  MatDoub Im_2_copy(Im_2);
  
  VecInt pI1(16,1),pI2(16,1);
  MatInt pI1I2(16,16,1);
  Doub N = 0;
  
  for (int i = 0; i < Im_1.nrows(); i++) {
	  for (int j = 0; j < Im_1.ncols(); j++) {
		  if (Im_1_Mask[i][j]) {
			Im_1_copy[i][j] = std::floor(Im_1_copy[i][j]/16);
			Im_2_copy[i][j] = std::floor(Im_2_copy[i][j]/16);
			pI1[(int)Im_1_copy[i][j]]++;
			pI2[(int)Im_2_copy[i][j]]++;
			pI1I2[(int)Im_1_copy[i][j]][(int)Im_2_copy[i][j]]++;
			std::cin.get();
			N++;
		  }
	  }
  }
  
  Doub sum = 0;
  
  for (int i = 0; i < 16; i++) {
	  for (int j = 0; j < 16; j++) {
		  sum += (pI1I2[i][j]/N)*std::log((pI1I2[i][j]/N)/((pI1[i]/N)*(pI2[j]/N)));
      }
  }
  std::cout << N << " " <<sum << " " << 1/sum << std::endl;
  return 1/sum;
}
