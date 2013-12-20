
#ifndef MONTGOMERI_H_
#define MONTGOMERI_H_

#include "ExpAlgInterfaces.h"
#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"
using namespace NTL;


namespace Ilona {

class Montgomeri : public ExpAlg {
public:
	Montgomeri();
	virtual ~Montgomeri();
	ZZ_p exp(ZZ_p x, ZZ n);

};

} /* namespace Adelier */

#endif /* MONTGOMERI_H_ */
