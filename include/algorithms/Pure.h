/*
 * Pure.h
 *
 *  Created on: 19 нояб. 2013 г.
 *      Author: Adelier
 */

#ifndef PURE_H_
#define PURE_H_

#include "ExpAlgInterfaces.h"
#include "NTL\ZZ.h"
#include "NTL\ZZ_p.h"
using namespace NTL;

namespace Adelier {

class Pure : public ExpAlg  {
public:
	Pure();
	virtual ~Pure();
	ZZ_p exp(ZZ_p x, ZZ n);
};

} /* namespace Adelier */

#endif /* PURE_H_ */
