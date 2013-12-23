#ifndef CONVTONAF_H
#define CONVTONAF_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"
NTL_CLIENT

class ConvToNAF
{
public:
    ConvToNAF();
    ~ConvToNAF();

	void CreateNAF(ZZ x);
	void VectInvert(ZZ* v, long long sz);

private:
    ZZ* NAF;
	long long size;
};

#endif // CONVTONAF_H
