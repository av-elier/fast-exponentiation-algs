#ifndef RIGHTTOLEFT_H_
#define RIGHTTOLEFT_H_

#include "ExpAlgInterfaces.h"
#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>
using namespace NTL;


namespace YGazaryan {

class RightToLeft : public ExpAlg {
public:
	RightToLeft();
	virtual ~RightToLeft();
	void CreateNAF(ZZ x);
    ZZ findInvr(const ZZ& a);
    ZZ_p exp(ZZ_p x, ZZ n);
private:
    vector<ZZ> bin;
};

}

#endif