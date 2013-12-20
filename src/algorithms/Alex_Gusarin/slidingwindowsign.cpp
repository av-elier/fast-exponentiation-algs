#include "algorithms/Alex_Gusarin/slidingwindowsign.h"
#include "algorithms/Alex_Gusarin/EuclidianAlg.h"

#include <sstream>

using namespace Valtonis;

SlidingWindowSignExponentation::SlidingWindowSignExponentation(char ws)
{
	this->ws = ws;
    setAuthor(L"Alex Gusarin");
    std::wostringstream meth;
    meth << L"Sliding Window Sign Exponentation ws=" << (int)ws;
    setMethod(meth.str().c_str());
    precalcValuesWithPositiveDeg = NULL;
    precalcValuesWithNegativeDeg = NULL;
    precalcValuesSize = 0;
    k = -1;
}

SlidingWindowSignExponentation::~SlidingWindowSignExponentation()
{
    delete []precalcValuesWithPositiveDeg;
    delete []precalcValuesWithNegativeDeg;
}

void SlidingWindowSignExponentation::precalculate(const ZZ_p& x)
{
    if(ws <= 0)
    {
        throw(1);
    }
    if(ws > k)
    {
        k = ws;
        precalcValuesSize = 1 << k;
        delete []precalcValuesWithPositiveDeg;
        delete []precalcValuesWithNegativeDeg;
        precalcValuesWithPositiveDeg = new ZZ_p[precalcValuesSize - 1];
        precalcValuesWithNegativeDeg = new ZZ_p[precalcValuesSize];
    }
    else
    {
        k = ws;
    }

    ZZ_p factor = sqr(x);
    precalcValuesWithPositiveDeg[0] = x * factor;
    for(long long i = 1; i < precalcValuesSize - 1; i++)
    {
        precalcValuesWithPositiveDeg[i] = precalcValuesWithPositiveDeg[i-1] * factor;
    }
    ZZ p = x.modulus();
    precalcValuesWithNegativeDeg[0] = conv<ZZ_p>(findInvr(conv<ZZ>(x),p));
    factor = sqr(precalcValuesWithNegativeDeg[0]);
    for(long long i = 1; i < precalcValuesSize; i++)
    {
        precalcValuesWithNegativeDeg[i] = precalcValuesWithNegativeDeg[i-1] * factor;
    }
}

ZZ_p SlidingWindowSignExponentation::getValueWithDegree(long long d)
{
    long long pos;
    if(d < 0)
    {
        pos = (-1) * d;
    }
    else
    {
        pos = d;
    }
    if(pos % 2 == 0)//элементов с чётными степенями нет
    {
        throw(1);
    }
    pos = pos / 2;
    if(d < 0)
    {
        return precalcValuesWithNegativeDeg[pos];
    }
    else
    {
        return precalcValuesWithPositiveDeg[pos - 1];
    }
}

ZZ_p SlidingWindowSignExponentation::exp(ZZ_p x,ZZ exponent)
{
    precalculate(x);
    NAFRepresentation naf;
    naf.createNAF(exponent);
    long i = naf.getSize() - 1;
    ZZ_p y;
    y = 1;
    long s;
    long long u;
    while(i >= 0)
    {
        if(naf.getBitVal(i) == 0)
        {
            sqr(y,y);
            i = i - 1;
        }
        else
        {
            s = max(i - k + 1,0);
            while(naf.getBitVal(s) == 0)
            {
                s = s + 1;
            }
            for(long h = 1;h <= i - s + 1;h = h + 1)
            {
                sqr(y,y);
            }
            u = naf.getValueOnInterval(i,s);
            if(u == 1)
            {
                y = y * x;
            }
            else
            {
                y *= getValueWithDegree(u);
            	if (y == 0)
            		throw (1); // никогда умножения не приводят к нулю
            }
            i = s - 1;
        }
    }
    return y;
}
