/*
 * NtlExpAlg.h
 *
 *  Created on: 19 дек. 2013 г.
 *      Author: Adelier
 */

#ifndef NTLEXPALG_H_
#define NTLEXPALG_H_

#include "ExpAlgInterfaces.h"
#include "NTL\ZZ.h"
#include "NTL\ZZ_p.h"
namespace Adelier {

class NtlExpAlg : public ExpAlg  {
public:
	NtlExpAlg();
	virtual ~NtlExpAlg();
	ZZ_p exp(ZZ_p x, ZZ n);
};

} /* namespace Adelier */

#endif /* NTLEXPALG_H_ */
