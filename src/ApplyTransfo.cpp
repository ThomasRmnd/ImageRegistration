#include <cmath>
#include "ApplyTransfo.h"

void ApplyTransfo::operator()(VecDoub_I& arg, Int x, Int y, Doub& xres, Doub& yres) {
  xres = std::cos(arg[2])*x - std::sin(arg[2])*y + arg[0];
  yres = std::sin(arg[2])*x + std::cos(arg[2])*y + arg[1];
}