/*
 * Pure.cpp
 *
 *  Created on: 19 нояб. 2013 г.
 *      Author: Adelier
 */

#include "algorithms/Pure.h"

namespace Adelier {

Pure::Pure() {
	setAuthor(L"Pure");
	setMethod(L"Pure");
}

Pure::~Pure() {
	// TODO Auto-generated destructor stub
}

ZZ_p Pure::exp(ZZ_p x, ZZ n){
	ZZ_p res;
	res = 1;
	for (ZZ i = conv<ZZ>(1); i <= n; i++)
		res *= x;
	return res;
}

} /* namespace Adelier */
