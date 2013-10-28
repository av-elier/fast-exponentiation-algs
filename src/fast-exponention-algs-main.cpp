//============================================================================
// Name        : fast-exponention-algs-main.cpp
// Author      : Adelier
// Version     : 0.0.0
// Copyright   : 
// Description : Homework 1-st year graduate students mmcs.sfedu.ru
//============================================================================

#include <iostream>

#include "nonUnitTests/MyTests.h"

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "RightToLeftByAdelier.h"

using namespace std;
using namespace NTL;
using namespace Adelier;


int main() {
	MyTests::run();
	ZZ p = GenPrime_ZZ(2048, 80);
	ZZ_p::init(p);
	cout << "GF(p): prime is " << p << endl;

	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>("11"));
	ZZ samplen = conv<ZZ>("6");

	ZZ_p res;
	for (int i = 0; i < 1000; ++i) {
		ExpAlgFastInterface* algRLAdelier = new RightToLeftByAdelier();
		res = algRLAdelier->exp(samplex, samplen);
	}

	cout << samplex << "^" << samplen << " = " << res << endl;

	ZZ primeornot = conv<ZZ>(123);
	primeornot = primeornot*primeornot;


	cout << "Hello" << endl;

	return 0;
}
