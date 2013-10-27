//============================================================================
// Name        : fast-exponention-algs-main.cpp
// Author      : Adelier
// Version     : 0.0.0
// Copyright   : 
// Description : Homework 1-st year graduate students mmcs.sfedu.ru
//============================================================================

#include <iostream>

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

using namespace std;
using namespace NTL;


int main() {
	ZZ primeornot = conv<ZZ>(123);
	primeornot = primeornot*primeornot;

	cout << primeornot << endl; // prints Hello World
	return 0;
}
