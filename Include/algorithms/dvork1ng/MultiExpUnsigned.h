#ifndef MULTIEXP_H
#define MULTIEXP_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "ExpAlgInterfaces.h"

namespace dvork1ng
{

	class MultiExpUnsigned : public ExpAlg
	{
	public:
		MultiExpUnsigned();
		~MultiExpUnsigned();

		ZZ_p exp(ZZ_p x, ZZ exp){return conv<ZZ_p>(0);}
		void precalculate(ZZ_p x, ZZ_p x1);
		ZZ_p exp(ZZ_p x, ZZ exp, ZZ_p x1, ZZ exp1);
		ZZ ExpandMinExp(ZZ lessExp, ZZ bigExp);

	private:
		ZZ_p xx1;
	};

}
#endif 
