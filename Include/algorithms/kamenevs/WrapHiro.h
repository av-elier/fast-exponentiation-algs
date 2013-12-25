/*
 * WrapHiro.h
 *
 *  Created on: 26 дек. 2013 г.
 *      Author: Adelier
 */

#ifndef WRAPHIRO_H_
#define WRAPHIRO_H_

#include "DicitonaryAlg.h"
#include "KuniHero.h"

class WrapHiro : public ExpAlg {
private:
	Kunihero kunihiro;
public:
	WrapHiro(Kunihero *kunihiro);
	virtual ~WrapHiro();
	void precalc(ZZ exponent){
		kunihiro.precalc(exponent);
	}
	ZZ_p exp(ZZ_p base){
		return kunihiro.exp(base);
	}
	ZZ_p exp(ZZ_p base, ZZ exponent){
		precalc(exponent);
		return exp(base);
	}
};


#endif /* WRAPHIRO_H_ */
