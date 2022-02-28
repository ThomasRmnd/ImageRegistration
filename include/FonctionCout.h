#ifndef FONCTIONCOUT_H
#define FONCTIONCOUT_H

#include "ReadFromFile.h"
#include "Similarity.h"
#include "DeformeImage.h"
#include "nr3.h"

class FonctionCout {
private:
	Similarity* methodeSim;
	DeformeImage* methodeDeforme;
  ReadFromFile* methodeRead;
	MatDoub Im, ImRef;
public:
	FonctionCout(Similarity*, DeformeImage*, ReadFromFile*);
	Doub operator()(VecDoub_I& arg) const;
};

#endif
