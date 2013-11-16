/*
 * FloatingWindowUnsigned.cpp
 *
 *  Created on: 29 окт. 2013 г.
 *      Author: Adelier
 */

#include "FloatingWindowUnsigned.h"

namespace Adelier {


FloatingWindowUnsigned::FloatingWindowUnsigned() {
	setAuthor(L"Adelier");
	setMethod(L"FloatingWindowUnsigned");
	FloatingWindowUnsigned::windowSize = 3; // sqrt(bitlength(x))/10
}
FloatingWindowUnsigned::FloatingWindowUnsigned(int _windowSize) {
	setAuthor(L"Adelier");
	setMethod(L"FloatingWindowUnsigned");
	windowSize = _windowSize;
}

FloatingWindowUnsigned::~FloatingWindowUnsigned() {
	// TODO Auto-generated destructor stub
}

void FloatingWindowUnsigned::calculateOddBaseDegrees(ZZ_p x){
	ZZ_p y = ZZ_p(x);
	ZZ_p x2 = x*x;
	oddBaseDegrees.push_back(new ZZ_p(y)); // или oddBaseDegrees.push_back(ZZ_p(y));
	for (int i = 3; i < pow(2.0, windowSize); i+=2){
		y *= x2;
		oddBaseDegrees.push_back(new ZZ_p(y)); // или oddBaseDegrees.push_back(ZZ_p(y));
	}
}

ZZ_p FloatingWindowUnsigned::exp(ZZ_p x, ZZ n){

	calculateOddBaseDegrees(x);
	ZZ_p y = conv<ZZ_p>(1);

	long l = NumBits(n);

	// Вариатны:
	// 1 MakeOdd(x & ...0011100...)
	// 2 bit(i)<<0 bit(i+1)<<1 bit(i+2)<<2

	// 00011111000
	// >>>wSize<<<
	;
	// NEVER-NEVER confuse 2 and 1! Unsearchable mistake!
	ZZ windowMask = (conv<ZZ>(1) << windowSize) - 1;

	// сдвинуть на начало (слева-направо)
	windowMask = windowMask << (l - windowSize);

	long i = l - 1;
	while(i >= 0){
		long k = 0;
		while (bit(n, i) == 0 && i >= 0){
			k++;
			i--;
			y*=y;
		}
		if (i >= 0){
			if (k!=0)
				windowMask = windowMask >> k;
			ZZ u = n & windowMask;
			MakeOdd(u);
			long uLength = NumBits(u);
			for (long j = 0; j < uLength; j++)
				y*=y;
			y*= *(oddBaseDegrees[(conv<long>(u)-1)/2]);
			i = i - uLength;

			windowMask = windowMask >> uLength;
		}
	}
	cout <<endl;

//	for (int i = 0; i < oddBaseDegrees.size(); ++i)
//		oddBaseDegrees[i]->~ZZ_p();
	oddBaseDegrees.clear();

	return y;
}

} /* namespace Adelier */
