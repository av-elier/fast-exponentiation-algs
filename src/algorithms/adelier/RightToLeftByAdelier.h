/*
 * RightToLeftByAdelier.h
 *
 *  Created on: 28 ���. 2013 �.
 *      Author: Adelier
 */

#ifndef RIGHTTOLEFTBYADELIER_H_
#define RIGHTTOLEFTBYADELIER_H_

#include "..\..\ExpAlgInterfaces.h"
#include "NTL\ZZ.h"
#include "NTL\ZZ_p.h"
using namespace NTL;


namespace Adelier {

class RightToLeft : public ExpAlgFastInterface {
public:
	RightToLeft();
	virtual ~RightToLeft();
	ZZ_p exp(ZZ_p x, ZZ n);
};

} /* namespace Adelier */

#endif /* RIGHTTOLEFTBYADELIER_H_ */
