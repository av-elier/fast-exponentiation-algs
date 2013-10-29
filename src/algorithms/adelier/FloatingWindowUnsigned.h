/*
 * FloatingWindowUnsigned.h
 *
 *  Created on: 29 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef FLOATINGWINDOWUNSIGNED_H_
#define FLOATINGWINDOWUNSIGNED_H_

#include "..\..\ExpAlgInterfaces.h"
#include "NTL\ZZ.h"
#include "NTL\ZZ_p.h"
#include <vector>
#include <math.h>

using namespace NTL;

namespace Adelier {

class FloatingWindowUnsigned : public ExpAlgFastInterface {
public:
	FloatingWindowUnsigned();
	FloatingWindowUnsigned(int windowSize);
	virtual ~FloatingWindowUnsigned();
	ZZ_p exp(ZZ_p x, ZZ n);
private:
	int windowSize;

	// x^odd = oddBaseDegrees[(odd+1)/2]
	vector<ZZ_p*> oddBaseDegrees;

	void calculateOddBaseDegrees(ZZ_p x);
};

} /* namespace Adelier */

#endif /* FLOATINGWINDOWUNSIGNED_H_ */
