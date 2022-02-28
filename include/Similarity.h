#ifndef SIMILARITY_H
#define SIMILARITY_H

#include "nr3.h"

class Similarity {
public:
	virtual Doub operator()(MatDoub_I& Im_1, MatBool_I& Im_1_Mask, MatDoub_I& Im_2) = 0;
	virtual ~Similarity() {}
};

class MoindreCarre : public Similarity {
public:
	Doub operator()(MatDoub_I& Im_1, MatBool_I& Im_1_Mask, MatDoub_I& Im_2);
};

class InformationMutuelle : public Similarity {
public:
	Doub operator()(MatDoub_I& Im_1, MatBool_I& Im_1_Mask, MatDoub_I& Im_2);
};

#endif
