#ifndef SLIDINGWINDOWSIGN_H
#define SLIDINGWINDOWSIGN_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "ExpAlgInterfaces.h"
#include "algorithms/Alex_Gusarin/nafrepresentation.h"

namespace Valtonis
{

class SlidingWindowSignExponentation : public ExpAlg
{
public:
    SlidingWindowSignExponentation(char ws = 4);
    ~SlidingWindowSignExponentation();

    void precalculate(const ZZ_p &x);//ws - размер окна
    ZZ_p exp(ZZ_p x,ZZ exponent);

    ZZ_p getValueWithDegree(long long d);//возвращает x^d
private:
    char ws;
    char k;//k < <= 63
    unsigned long long precalcValuesSize;
    ZZ_p* precalcValuesWithPositiveDeg;//предварительно вычисляемые степени x^3,x^5,...,x^(2^k-1)
    ZZ_p* precalcValuesWithNegativeDeg;//тоже самое, только степени отрицательные
};

}
#endif // SLIDINGWINDOWSIGN_H
