#ifndef READFROMFILE_H
#define READFROMFILE_H

#include <fstream>
#include <sstream>
#include <string>
#include "nr3.h"

class ReadFromFile {
private:
  std::string filenameIm;
  std::string filenameImRef;
public:
  ReadFromFile(const std::string&, const std::string&);
	void operator()(MatDoub&, MatDoub&);
};

void operator>>(std::ifstream&, MatDoub&);

std::ostream& operator<<(std::ostream&, MatDoub_I&);

void download(MatDoub_I&);

void download(MatBool_I&);

#endif
