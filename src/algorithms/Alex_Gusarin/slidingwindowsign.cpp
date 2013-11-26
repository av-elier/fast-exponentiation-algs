#include "algorithms/Alex_Gusarin/slidingwindowsign.h"

using namespace Valtonis;

SlidingWindowSignExponentation::SlidingWindowSignExponentation()
{
    setAuthor(L"Alex Gusarin");
    setMethod(L"Sliding Window Sign Exponentation");
    precalcValuesWithPositiveDeg = NULL;
    precalcValuesWithNegativeDeg = NULL;
    precalcValuesSize = 0;
    k = -1;
    //ZZ_p::init(p);
}

SlidingWindowSignExponentation::~SlidingWindowSignExponentation()
{
    delete []precalcValuesWithPositiveDeg;
    delete []precalcValuesWithNegativeDeg;
}

void SlidingWindowSignExponentation::precalculate(ZZ_p x,char ws)
{
    if(ws <= 0)
    {
        throw(1);
    }
    if(ws > k)
    {
        k = ws;
        precalcValuesSize = pow(2,k) / 2;
        delete []precalcValuesWithPositiveDeg;
        delete []precalcValuesWithNegativeDeg;
        precalcValuesWithPositiveDeg = new ZZ_p[precalcValuesSize - 1];
        precalcValuesWithNegativeDeg = new ZZ_p[precalcValuesSize];
    }
    else
    {
        k = ws;
    }
    long deg = precalcValuesSize + 2;
    for(unsigned long long i = 3;i <= deg;i = i + 2)
    {
        precalcValuesWithPositiveDeg[(i - 3) / 2] = power(x,i);
    }
    for(unsigned long long i = 1;i <= deg;i = i + 2)
    {
        precalcValuesWithNegativeDeg[(i - 1) / 2] = power(x,(-1) * i);
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
    precalculate(x,3);
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
            }
            i = s - 1;
        }
    }
    return y;
}
