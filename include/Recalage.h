#ifndef RECALAGE_H
#define RECALAGE_H

#include "FonctionCout.h"
#include "Similarity.h"
#include "nr3.h"
#include "amoeba.h"

class Recalage {
private:
	Amoeba* methodeOpti;
	FonctionCout* methodeCout;
public:
	Recalage(Amoeba*, FonctionCout*);
	VecDoub operator()(VecDoub_I& start, Doub del) const;
};	

#endif
