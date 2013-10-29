/*
 * RightToLeft.cpp
 *
 *  Created on: 28 ���. 2013 �.
 *      Author: Adelier
 */

#include "algorithms/RightToLeftByAdelier.h"

namespace Adelier {

RightToLeft::RightToLeft() {
	// TODO Auto-generated constructor stub

}

RightToLeft::~RightToLeft() {
	// TODO Auto-generated destructor stub
}

ZZ_p RightToLeft::exp(ZZ_p x, ZZ exponent){
	ZZ_p y = conv<ZZ_p>(1);

	long l = NumBits(exponent);

	for(int i = 0; i < l; ++i){
		if (bit(exponent, i) == 1)
			y*=x;
		x*=x;
	}
	return y;
}

} /* namespace Adelier */
