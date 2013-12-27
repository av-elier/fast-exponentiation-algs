#ifndef MULTIEXPSIGNED_H
#define MULTIEXPSIGNED_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "ExpAlgInterfaces.h"

namespace dvork1ng
{
	struct NAF
	{
		ZZ exp;
		ZZ service;
	};

	class MultiExpSigned : public ExpAlg
	{
	public:
		MultiExpSigned();
		~MultiExpSigned();

		ZZ_p exp(ZZ_p x, ZZ exp){return conv<ZZ_p>(0);}
		void precalculate(ZZ_p x, ZZ_p x1);
		ZZ_p exp(ZZ_p x, ZZ exp, ZZ_p x1, ZZ exp1);
		ZZ ExpandMinExp(ZZ lessExp, ZZ bigExp);
		NAF ConvertToNAF(ZZ exp);

	private:
		ZZ_p x_;
		ZZ_p x1_;
		ZZ_p xx1;
		ZZ_p x_x1;
		ZZ_p xx1_;
		ZZ_p x_x1_;
	};

}
#endif 
