/*
 * RightToLeft.cpp
 *
 *  Created on: 28 ���. 2013 �.
 *      Author: Adelier
 */

#include "algorithms/adelier/RightToLeftByAdelier.h"

namespace Adelier {

RightToLeft::RightToLeft(){
		setAuthor(L"Adelier");
		setMethod(L"RightToLeft");
}
RightToLeft::~RightToLeft(){
}

ZZ_p RightToLeft::exp(ZZ_p x, ZZ exponent){
	ZZ_p y = conv<ZZ_p>(1);

	int l = NumBits(exponent);

	for(int i = 0; i < l; ++i){
		if (bit(exponent, i) == 1)
			y*=x;
		x*=x;
	}
	return y;
}

} /* namespace Adelier */
