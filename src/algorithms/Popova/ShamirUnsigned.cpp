#include "algorithms/Popova/ShamirUnsigned.h"

using namespace Popova;
using namespace std;

ShamirUnsigned::ShamirUnsigned()
{
    setAuthor(L"Svetlana Popova");
    setMethod(L"ShamirUnsigned");
    gseq = NULL;
	nseq = NULL;
	xseq = NULL;
	gsize = 0;
	r = 0;
}

ShamirUnsigned::~ShamirUnsigned()
{
    delete []gseq;
	delete []nseq;
	delete []xseq;
}

void ShamirUnsigned::precalculate(ZZ_p x, ZZ exponent)
{
	ZZ base = conv<ZZ>(64);

	r = FromDecToAny(exponent, base);
	gseqCalc(x, base, r);
}

long ShamirUnsigned::getLen(long size)
{
	long len=0;
	long templ=0;
	for (long i = 0; i < size; i++)
	{
		if (nseq[i] == 0)
			templ = 0;
		else
			templ = NumBits(nseq[i]);
		if (templ >= len)
			len = templ;
	}
	return len;
}

void ShamirUnsigned::xseqCalc(ZZ_p x, ZZ base, long size)
{
	delete []xseq;
	xseq = new ZZ_p[size];
	xseq[0] = x;

	if (size > 1)
	{
		for (long i = 1; i < size; i++)
			xseq[i] = xInDegBase(x, power(base,i));
	}
}

void ShamirUnsigned::gseqCalc(ZZ_p x, ZZ base, long size)
{
	xseqCalc(x, base, size);

	gsize = pow(2.0,size);
	long* iseq = new long[gsize];
	gseq = new ZZ_p[gsize];

	for (long i = 0; i < gsize; i++)
		iseq[i]=i;

	int deg = 0;
	for (long i = 0; i < gsize; i++)
	{
		gseq[i] = 1;
		for (long j = 0; j < size; j++)
		{
			deg = bit(iseq[i],j);
			gseq[i] *= power(xseq[j], deg);
		}
	}
}

ZZ_p ShamirUnsigned::xInDegBase(ZZ_p x, ZZ base)
{
	ZZ_p y = conv<ZZ_p>(1);
	int l = NumBits(base);

	for(int i = 0; i < l; ++i)
	{
		if (bit(base, i) == 1)
			y *= x;
		x *= x;
	}

	return y;
}

ZZ_p ShamirUnsigned::exp(ZZ_p x,ZZ exponent)
{
	long l;
	l = getLen(r);
	ZZ_p y = conv<ZZ_p>(1);
	long i = 0;

	for (long k = l-1; k >=0; k--)
	{
		sqr(y,y);

		for (long j = 0; j < r; j++)
			i += bit(nseq[r-1-j], k) * pow(2.0, j);

		y *= gseq[i];
		i = 0;
	}

	return y;
}

long ShamirUnsigned::FromDecToAny(ZZ exponent, ZZ base)
{
	ZZ newExp = exponent;
	ZZ temp;
	long r_ = 1;

	if (newExp < base)
	{
		nseq = new ZZ[r_];
		nseq[0] = newExp;
	}
	else
	{
		while (newExp > base)
		{
			temp = newExp % base;
			r_++;
			newExp = newExp/base;
		}

		nseqCalc(exponent, base, r_);
	}

	return r_;
}

void ShamirUnsigned::VectInvert(ZZ* v, long size)
{
	nseq = new ZZ[size];

	for(long i = 0; i < size; i++)
		nseq[i]=v[size-1-i];
}

void ShamirUnsigned::nseqCalc(ZZ exponent, ZZ base, long r_)
{
	ZZ* tempn = new ZZ[r_];
	ZZ newExp = exponent;
	ZZ temp;

	for (long i = 0; i < r_; i++)
	{
		temp = newExp % base;
		tempn[i]=temp;
		newExp = newExp/base;
	}

	VectInvert(tempn, r_);
}

