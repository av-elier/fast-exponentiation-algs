/*
 * Euclid.cpp
 *
 *  Created on: 21 нояб. 2013 г.
 *      Author: Adelier
 */

#include "algorithms/adelier/Euclid.h"

NTL_CLIENT

namespace Adelier {

Euclid::Euclid(int _radixBitCount, ExpAlg *_simpleAlg) {
	setAuthor(L"Adelier");
	setMethod(L"Euclid");

	setRadixBitCountAndMask(_radixBitCount);
	simpleAlg = _simpleAlg;
}
void Euclid::setRadixBitCountAndMask(int _radixBitCount) {
	radixBitCount = _radixBitCount;
	mask = (conv<ZZ>(1) << radixBitCount) - 1;
}

Euclid::~Euclid() {
}


void Euclid::precalc(ZZ_p x){
	ZZ p = ZZ_p::modulus();
	length = (NumBits(p) - 1) / radixBitCount + 1;
	xdegs = new ZZ_p[length];

	ZZ_p y = x;
	xdegs[0] = y;
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < radixBitCount; j++)
			y *= y;
		xdegs[i] = y;
	}
}

ZZ_p Euclid::exp(ZZ n){
	if (length == 1)
		/*
		 * Слишком короткое число для этого метода, вызовется просто
		 * алгоритм для "коротких" чисел {@code simpleAlg}
		 */
		return simpleAlg->exp(xdegs[0], n);

	ZZ_p *xdegs = this->xdegs;
	ZZ *ndegs = toRadixRepresentation(n);

	while (true) {
		// найти индексы для двух максимальных 1-самый, 2-второй
		// k1
		int k1 = 0;
		for (int i = 1; i < length; i++) {
			if (ndegs[i] > ndegs[k1]) {
				k1 = i;
			}
		}
		// k2
		int k2 = k1 == 0 ? 1 : 0;
		for (int i = 0; i < length; i++) {
			if (i != k1 && ndegs[i] > ndegs[k2]) {
				k2 = i;
			}
		}

		// если второй == 0 - return x_M^nm
		if (ndegs[k2] == 0)
			return simpleAlg->exp(xdegs[k1], ndegs[k1]);
		// иначе
		// d = n_M / n_N
		ZZ d = ndegs[k1] / ndegs[k2];
		// x_N = x_M * x_N
		xdegs[k2] = xdegs[k2] * simpleAlg->exp(xdegs[k1], d);
		// n_M = n_M mod n_N
		ndegs[k1] = ndegs[k1] % ndegs[k2];
	}
	return conv<ZZ_p>(0);
}
ZZ* Euclid::toRadixRepresentation(ZZ val) {
		ZZ *radixRepr = new ZZ[length];
		int k = 0;
		while (val > 0) {
			radixRepr[k++] = val & mask;
			val = val >> radixBitCount;
		}
		while (k < length)
			radixRepr[k++] = 0;
		return radixRepr;
	}

} /* namespace Adelier */
