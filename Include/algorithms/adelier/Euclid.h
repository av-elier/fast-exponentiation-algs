/*
 * Euclid.h
 *
 *  Created on: 21 нояб. 2013 г.
 *      Author: Adelier
 */

#ifndef EUCLID_H_
#define EUCLID_H_

#include "ExpAlgInterfaces.h"

namespace Adelier {

class Euclid : public ExpAlgFixedBase {
public:
	Euclid(int _radixBitCount, ExpAlg *_simpleAlg);
	virtual ~Euclid();

	void precalc(ZZ_p x);
	ZZ_p exp(ZZ n);
private:
	ExpAlg* simpleAlg;
	int radixBitCount;
	int length;
	ZZ p;
	ZZ mask;
	/**
	 * At <i>i</i> stands <i>x^(2^radixBitCount)</i> <br>
	 * At 0 stands x
	 */
	ZZ_p *xdegs;

	void setRadixBitCountAndMask(int radixBitCount);
	ZZ* toRadixRepresentation(ZZ val);

};

} /* namespace Adelier */

#endif /* EUCLID_H_ */
