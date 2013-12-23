#include "ConvToNAF.h"

using namespace NTL;
using namespace std;

ConvToNAF::ConvToNAF()
{
    NAF = NULL;
	size = 0;
}

ConvToNAF::~ConvToNAF()
{
    delete []NAF;
}

void ConvToNAF::CreateNAF(ZZ x)
{
	long long sz = NumBits(x);
	long long size = sz + 1;

	ZZ c[2];
	c[0] = 0;
	ZZ* tempNAF = new ZZ[size];
	ZZ n[2];
	n[0] = bit(x,0);

	for (long long i = 0; i < size; i++)
	{
		n[1] = bit(x, i + 1);
		c[1] = (c[0] + n[0] + n[1]) / 2;
		tempNAF[i] = c[0] + n[0] - 2 * c[1];
		c[0] = c[1];
		n[0] = n[1];
	}

	VectInvert(tempNAF, size);
	/*for(long long i = 0; i < size; i++)
		cout<<NAF[i];
	cout<<endl;*/
}

void ConvToNAF::VectInvert(ZZ* v, long long sz)
{
	NAF = new ZZ[sz];

	for(long i = 0; i < sz; i++)
		NAF[i]=v[sz-1-i];
}
