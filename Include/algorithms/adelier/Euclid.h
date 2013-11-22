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

class Euclid : public ExpAlgFixedExponent {
public:
	Euclid();
	virtual ~Euclid();

	ZZ_p precalc(ZZ exponent);
	ZZ_p exp(ZZ_p base);
private:


};

} /* namespace Adelier */

#endif /* EUCLID_H_ */
