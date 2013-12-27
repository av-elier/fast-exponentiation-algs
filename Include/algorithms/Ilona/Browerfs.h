#ifndef BROWERFS_H
#define BROWERFS_H
#include <stdio.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ.h>
#include <vector>
#include <map>
#include <cmath>
#include "ExpAlgInterfaces.h"

//NTL_CLIENT


namespace Ilona
{

class BrowerSigned: public ExpAlg
{
public:
    BrowerSigned();
    ~BrowerSigned();

    void precalculate(ZZ_p x, ZZ exponent);
	

	ZZ_p sum(ZZ_p a , ZZ_p b);
	ZZ_p product(ZZ_p a , ZZ_p b);
	ZZ_p square(ZZ_p a);
	ZZ findInvr(const ZZ& a);
	long long pow2( unsigned long long P);
	long long kcount( ZZ n , int limit , int &degree );
	void dec_base( ZZ n, int base , vector<ZZ> &bin  );
	void CreateNAF(ZZ x);
	void InvNAF(ZZ n);
	void sigma( ZZ m , int k , int & s , ZZ & u );
    ZZ_p exp(ZZ_p x,ZZ exponent);

private:
    map<ZZ,ZZ_p> vecx;
	int k;
    vector<ZZ> bin;
	vector<ZZ> binN;
};

}

#endif