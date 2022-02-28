#include "ReadFromFile.h"

ReadFromFile::ReadFromFile(const std::string& _filenameIm_, const std::string& _filenameImRef_) {
  filenameIm = _filenameIm_;
  filenameImRef = _filenameImRef_;
}

void ReadFromFile::operator()(MatDoub& Im, MatDoub& ImRef) {
	std::ifstream fluxIm(filenameIm);
  std::ifstream fluxImRef(filenameImRef);
	if (!fluxIm.fail() && !fluxImRef.fail()) {
		fluxIm >> Im;
		fluxImRef >> ImRef;
  }
  fluxIm.close();
  fluxImRef.close();
}

void operator>>(std::ifstream& flux, MatDoub& im) {
	int row, col;
	int param;
	std::string line;
	std::getline(flux,line);
	std::istringstream ss(line);
	ss >> line >> col >> row >> param;
	im.resize(row,col);
	int i = 0, j = 0;
	while (std::getline(flux,line)) {
		std::istringstream ss(line);
		double value;
		while (ss >> value) {
			if (j == col) {
				j = 0;
				i++;
			}
			im[i][j] = value;
			j++;
		}
	}
}

std::ostream& operator<<(std::ostream& os, MatDoub_I& im) {
  int row = im.nrows(), col = im.ncols();
  os << row << " " << col << std::endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      os << im[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}

void download(MatDoub_I& Im) {
  std::string filename("../data/test.pgm");
  std::ofstream flux(filename);
  if (!flux.fail()) {
    int col = Im.ncols(), row = Im.nrows();
    flux << "P2" << " " << col << " " << row << " " << 255 << std::endl;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        flux << Im[i][j] << " ";
      }
      flux << std::endl;
    }
  }
  flux.close();
}

void download(MatBool_I& Im) {
  std::string filename("../data/test.pgm");
  std::ofstream flux(filename);
  if (!flux.fail()) {
    int col = Im.ncols(), row = Im.nrows();
    flux << "P2" << " " << col << " " << row << " " << 255 << std::endl;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        flux << Im[i][j]*255 << " ";
      }
      flux << std::endl;
    }
  }
  flux.close();
}
