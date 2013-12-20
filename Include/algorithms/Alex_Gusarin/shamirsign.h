#ifndef SHAMIRSIGN_H
#define SHAMIRSIGN_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"
#include "nafrepresentation.h"
#include "ExpAlgInterfaces.h"

namespace Valtonis
{

class ShamirSign : public ExpAlg {
public:
    ShamirSign();
    virtual ~ShamirSign();
    void setSize(char r);
    void precalculation(const NTL::ZZ_p* const x,const NTL::ZZ* const n,char r);// r < 31
    NTL::ZZ_p exp(NTL::ZZ_p base, NTL::ZZ exponent);
    NTL::ZZ_p exp(const NTL::ZZ_p* const x,const NTL::ZZ* const n,char r);
    const NTL::ZZ_p& getg(char* seq);

    static void next(char* seq,char sz);
    unsigned long long getMaxNAFLength();
private:
    char size;//���������� ������������
    NAFRepresentation* NAFs;
    NTL::ZZ_p* xWithNegativeDeg;//x0^(-1),x1^(-1),...
    long long gSize;
    NTL::ZZ_p* g;
};

}// namespace Valtonis

#endif // SHAMIRSIGN_H
