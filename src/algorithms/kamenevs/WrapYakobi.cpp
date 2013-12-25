/*
 * WrapYakobi.cpp
 *
 *  Created on: 26 дек. 2013 г.
 *      Author: Adelier
 */

#include "algorithms/kamenevs/WrapYakobi.h"
#include "algorithms/kamenevs/Yakobi.h"


WrapYakobi::WrapYakobi(Yakobi *yakobi){
	this->yakobi = *yakobi;
}

WrapYakobi::~WrapYakobi() {
	// TODO Auto-generated destructor stub
}
void WrapYakobi::precalc(ZZ exponent){
	yakobi.precalc(exponent);
}
ZZ_p WrapYakobi::exp(ZZ_p base){
	return yakobi.exp(base);
}
ZZ_p WrapYakobi::exp(ZZ_p base, ZZ exponent){
	precalc(exponent);
	return exp(base);
}
