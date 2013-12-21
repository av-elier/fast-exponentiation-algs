#ifndef SAMIRUNSIGNED_H
#define SAMIRUNSIGNED_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "ExpAlgInterfaces.h"

namespace Popova
{

class ShamirUnsigned: public ExpAlg
{
public:
    ShamirUnsigned();
    ~ShamirUnsigned();

    void precalculate(ZZ_p x, ZZ exponent);
	long FromDecToAny(ZZ exponent, ZZ base);
	void VectInvert(ZZ* v, long size);
	ZZ_p xInDegBase(ZZ_p x, ZZ base);
	void xseqCalc(ZZ_p x, ZZ base, long size);
	void gseqCalc(ZZ_p x, ZZ base, long size);
	void nseqCalc(ZZ exponent, ZZ base, long r_);
	long getLen(long size);
    ZZ_p exp(ZZ_p x,ZZ exponent);

private:
    long gsize;
	long r;
    ZZ_p* gseq;
	ZZ_p* xseq;
	ZZ* nseq;
};

}
#endif // SAMIRUNSIGNED_H
