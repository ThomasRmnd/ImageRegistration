#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "nr3.h"

class Interpolation {
public:
	virtual Doub operator()(MatDoub_I& Im, Doub x, Doub y, Bool& OK) = 0;
	virtual ~Interpolation() {}
};

class Bilineaire: public Interpolation {
public:
	Doub operator()(MatDoub_I& Im, Doub x, Doub y, Bool& OK);
};

class PlusProcheVoisin : public Interpolation {
public:
	Doub operator()(MatDoub_I& Im, Doub x, Doub y, Bool& OK);
};

#endif
