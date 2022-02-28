#ifndef DEFORMEIMAGE_H
#define DEFORMEIMAGE_H

#include "Interpolation.h"
#include "ApplyTransfo.h"
#include "nr3.h"

class DeformeImage {
private:
	Interpolation* methodeInter;
	ApplyTransfo* methodeTrans;
public:
	DeformeImage(Interpolation*, ApplyTransfo*);
	void operator()(MatDoub_I& Im, MatDoub& ImRes, MatBool& ImMask, VecDoub_I& arg) const;
};

#endif
