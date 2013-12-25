

#include "algorithms/kamenevs/WrapHiro.h"
#include "algorithms/kamenevs/KuniHero.h"


WrapHiro::WrapHiro(Kunihero *kunihiro){
	this->kunihiro = *kunihiro;
}

WrapHiro::~WrapHiro() {
	// TODO Auto-generated destructor stub
}
void WrapHiro::precalc(ZZ exponent){
	kunihiro.precalc(exponent);
}
ZZ_p WrapHiro::exp(ZZ_p base){
	return kunihiro.exp(base);
}
ZZ_p WrapHiro::exp(ZZ_p base, ZZ exponent){
	precalc(exponent);
	return exp(base);
}
