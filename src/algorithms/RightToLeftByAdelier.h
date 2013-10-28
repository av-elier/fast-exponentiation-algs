/*
 * RightToLeftByAdelier.h
 *
 *  Created on: 28 ���. 2013 �.
 *      Author: Adelier
 */

#ifndef RIGHTTOLEFTBYADELIER_H_
#define RIGHTTOLEFTBYADELIER_H_
/*
 * RightToLeftByAdelier.h
 *
 *  Created on: 28 ���. 2013 �.
 *      Author: Adelier
 */

#include "ExpAlgInterfaces.h"
#include "NTL\ZZ.h"
#include "NTL\ZZ_p.h"
using namespace NTL;


namespace Adelier {

class RightToLeftByAdelier : public ExpAlgFastInterface {
public:
	RightToLeftByAdelier();
	virtual ~RightToLeftByAdelier();
	ZZ_p exp(ZZ_p x, ZZ n);
};

} /* namespace Adelier */

#endif /* RIGHTTOLEFTBYADELIER_H_ */
