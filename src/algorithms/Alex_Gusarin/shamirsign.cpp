#include "algorithms/Alex_Gusarin/shamirsign.h"
#include "algorithms/Alex_Gusarin/EuclidianAlg.h"

using namespace Valtonis;


ShamirSign::ShamirSign()
{
    size = 0;
    gSize = 0;
    xWithNegativeDeg = NULL;
    NAFs = NULL;
    g = NULL;
}

ShamirSign::~ShamirSign()
{
    delete []NAFs;
    delete []g;
    delete []xWithNegativeDeg;
}

void ShamirSign::setSize(char r)
{
    if(r > size)
    {
        delete []NAFs;
        delete []g;
        delete []xWithNegativeDeg;
        NAFs = new NAFRepresentation[r];
        xWithNegativeDeg = new ZZ_p[r];
        gSize = pow(3,r);
        g = new ZZ_p[gSize];
    }
    size = r;
}

void ShamirSign::precalculation(const NTL::ZZ_p* const x,const NTL::ZZ* const n,char r)
{
    setSize(r);
    char* degSequence = new char[r];
    ZZ p = x[0].modulus();
    for(char i = 0;i < r;i = i + 1)
    {
        NAFs[i].createNAF(n[i]);
        xWithNegativeDeg[i] = conv<ZZ_p>(findInvr(conv<ZZ>(x[i]),p));
        degSequence[i] = 0;
    }
    g[0] = 1;
    degSequence[0] = 1;
    for(long long i = 1;i < gSize;i = i + 1)
    {
        g[i] = 1;
        for(char k = 0;k < r;k = k + 1)
        {
            switch(degSequence[k])
            {
                case 0:
                    break;
                case 1:
                    g[i] *= x[k];
                    break;
                case -1:
                    g[i] *= xWithNegativeDeg[k];
            }
        }
        next(degSequence,r);
    }
    delete []degSequence;
}

ZZ_p ShamirSign::exp(const NTL::ZZ_p* const x,const NTL::ZZ* const n,char r)
{
    precalculation(x,n,r);
    unsigned long long maxLen = getMaxNAFLength();
    char* degSequence = new char[size];
    ZZ_p y = conv<ZZ_p>(1);
    for(long long i = maxLen - 1;i >= 0;i = i - 1)
    {
        sqr(y,y);
        for(char k = 0;k < size;k = k + 1)
        {
            degSequence[k] = NAFs[k].getBitVal(i);
        }
        ZZ_p gi = getg(degSequence);
        long kk = conv<long>(gi);
        y *= gi;
    }
    delete []degSequence;
    return y;
}

const ZZ_p& ShamirSign::getg(char* seq)
{
    long long pos = 0;
    long long degOf3 = 1;
    for(char i = 0;i < size;i = i + 1)
    {
        switch(seq[i])
        {
            case 0:
                break;
            case 1:
                pos = pos + degOf3;
                break;
            case -1:
                pos = pos + 2 * degOf3;
        }
        degOf3 = degOf3 * 3;
    }
    return g[pos];
}

void ShamirSign::next(char* seq,char sz)
{
    bool fin;
    for(char i = 0;i < sz;i = i + 1)
    {
        fin = true;
        switch(seq[i])
        {
            case 0:
                seq[i] = 1;
                break;
            case 1:
                seq[i] = -1;
                break;
            case -1:
                seq[i] = 0;
                fin = false;
        }
        if(fin == true)
        {
            break;
        }
    }
}

unsigned long long ShamirSign::getMaxNAFLength()
{
    unsigned long long maxLen = 0;
    unsigned long long curLen;
    for(char i = 0;i < size;i = i + 1)
    {
        curLen = NAFs[i].getSize();
        if(curLen > maxLen)
        {
            maxLen = curLen;
        }
    }
    return maxLen;
}
