#include "Recalage.h"

Recalage::Recalage(Amoeba* _methodeOpti_, FonctionCout* _methodeCout_) {
  methodeOpti = _methodeOpti_;
  methodeCout = _methodeCout_;
}

VecDoub Recalage::operator()(VecDoub_I& start, Doub del) const {
  return methodeOpti->minimize(start, del, *methodeCout);
}
