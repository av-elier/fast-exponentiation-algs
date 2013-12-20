/*
 * FloatingWindowUnsigned.cpp
 *
 *  Created on: 29 окт. 2013 г.
 *      Author: Adelier
 */

#include "algorithms/adelier/FloatingWindowUnsigned.h"

namespace Adelier {


FloatingWindowUnsigned::FloatingWindowUnsigned() {
	setAuthor(L"Adelier");
	setWindowSize(3);
	setMethod(L"FloatingWindowUnsigned");
}
FloatingWindowUnsigned::FloatingWindowUnsigned(int _windowSize) {
	setAuthor(L"Adelier");
	setWindowSize(_windowSize);
	setMethod(L"FloatingWindowUnsigned");
}

FloatingWindowUnsigned::~FloatingWindowUnsigned() {
	// TODO Auto-generated destructor stub
}
void FloatingWindowUnsigned::setWindowSize(int _windowSize){
	windowSize = _windowSize;
	windowMask = (1 << windowSize) - 1;
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

	int l = NumBits(n);

	// bit(i)<<0 bit(i+1)<<1 bit(i+2)<<2

	// индекс1 на начало
	//цикл
	// пропустить нули возводя в квадраты, на первую 1 поставить индекс1
	// сформировать содержимое окна после индекс1
	//   пропускаю с конца нули, на 1 ставлю iend
	//   с неё собираю window, не забыва=я катить лавину
	// сократить окно на нули, индекс2 на конец окна
	// и ^ winsize и1-и2, *wincont
	int i = l-1;
	int ibegin, iend;
	while (i >= 0) {
		while (i >= 0 && (bit(n, i) == 0)) {
			i--;
			y*=y;
		}
		if (i < 0)
			break;
		ibegin = i;
		iend = ibegin - windowSize + 1;
		while (bit(n, iend) == 0){
			iend++;
		}
		long window = 0;
		for (int j = ibegin; j >= iend; j--){
			window = (window << 1) ^ bit(n, j);
			y*=y;
		}
		y *= *oddBaseDegrees[(window - 1) / 2];
		i = iend - 1;
	}

	oddBaseDegrees.clear();
	return y;
}

} /* namespace Adelier */
