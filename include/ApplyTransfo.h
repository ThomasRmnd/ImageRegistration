#ifndef APPLYTRANSFO_H
#define APPLYTRANSFO_H

#include "nr3.h"

class ApplyTransfo {
public:
	void operator()(VecDoub_I& arg, Int x, Int y, Doub& xres, Doub& yres);
};

#endif
