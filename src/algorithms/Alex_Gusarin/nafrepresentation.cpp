#include "algorithms/Alex_Gusarin/nafrepresentation.h"

using namespace std;
using namespace NTL;

NAFRepresentation::NAFRepresentation()
{
    NAF = NULL;
    sign = NULL;
    size = 0;
    blockNumber = 0;
}

NAFRepresentation::~NAFRepresentation()
{
    delete []NAF;
    delete []sign;
}

void NAFRepresentation::createNAF(const ZZ& val)
{
    unsigned long long sz = NumBits(val);
    setSize(sz);
    char c[2];
    c[0] = 0;
    char n[2];
    n[0] = bit(val,0);
    for(unsigned long long i = 0;i < size - 1;i = i + 1)//вычисление несмежного знакового представления по двоичному
    {
        n[1] = bit(val,i + 1);
        c[1] = (c[0] + n[0] + n[1]) / 2;
        setBitVal(i,c[0] + n [0] - 2 * c[1]);
        c[0] = c[1];
        n[0] = n[1];
    }
    if(c[0] == 1)
    {
        setBitVal(size - 1,0);
        setBitVal(size,1);
        size = size + 1;
    }
    else
    {
        setBitVal(size - 1,1);
    }
}

long long NAFRepresentation::getValueOnInterval(unsigned long long i,unsigned long long s)
{
    const unsigned long long delta = i - s;
    long long res = getBitVal(s);
    long long temp = 2;
    for(long long g = 1;g <= delta; g = g + 1)
    {
        res = res + getBitVal(g + s) * temp;
        temp = temp * 2;
    }
    return res;
}

char NAFRepresentation::getBitVal(unsigned long long pos)
{
    if(pos >= size)
    {
        return 0;
    }
    unsigned long long shift = pos / (sizeof(unsigned char) * 8);
    unsigned long long delta = pos - shift * (sizeof(unsigned char) * 8);
    unsigned char* NAFPointer = NAF + shift;
    unsigned char k = 1;
    k = k << (sizeof(unsigned char) * 8) - delta - 1;
    unsigned char val = *NAFPointer & k;
    if(val == 0)
    {
        return 0;
    }
    else
    {
        unsigned char* SignPointer = sign + shift;
        val = *SignPointer & k;
        if(val == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

void NAFRepresentation::setSize(unsigned long long sz)
{
    if(sz < size || (sz / (sizeof(unsigned char) * 8) + 1) < blockNumber)
    {
        size = sz;
    }
    else
    {
        size = sz;
        unsigned long long oldBlockNumber = blockNumber;
        blockNumber = size / (sizeof(unsigned char) * 8) + 1;
        unsigned char* p0 =  new unsigned char[blockNumber];
        unsigned char* p1 =  new unsigned char[blockNumber];
        for(long long i = oldBlockNumber - 1;i >= 0 ;i = i - 1)
        {
            p0[i] = NAF[i];
            p1[i] = sign[i];
        }
        delete []NAF;
        delete []sign;
        NAF = p0;
        sign = p1;
    }
}

 unsigned long long NAFRepresentation::getSize()
 {
     return size;
 }

void NAFRepresentation::setBitVal(unsigned long long pos,char v)
{
    unsigned long long shift = pos / (sizeof(unsigned char) * 8);
    unsigned long long delta = pos - shift * (sizeof(unsigned char) * 8);
    unsigned char* NAFPointer = NAF + shift;
    unsigned char* SignPointer = sign + shift;
    unsigned char k = 1;
    k = k << sizeof(unsigned char) * 8 - delta - 1;
    switch (v)
    {
        case 1:
            *NAFPointer = *NAFPointer | k;
            *SignPointer = *SignPointer & (~k);
            break;
        case -1:
            *NAFPointer = *NAFPointer | k;
            *SignPointer = *SignPointer | k;
            break;
        case 0:
            *NAFPointer = *NAFPointer & (~k);
            *SignPointer = *SignPointer & (~k);
            break;
        default:
            break;
    }
}
