//============================================================================
// Name        : fast-exponention-algs-main.cpp
// Author      : Adelier
// Version     : 0.0.0
// Copyright   : 
// Description : Homework by 1-st year graduate students (mmcs.sfedu.ru)
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>
//#include <omp.h>

#include "ExpAlgTests.h"

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "algorithms/Pure.h"
#include "algorithms/NtlExpAlg.h"
#include "algorithms/adelier/RightToLeftByAdelier.h"
#include "algorithms/adelier/FloatingWindowUnsigned.h"
#include "algorithms/adelier/Euclid.h"
#include "algorithms/Alex_Gusarin/slidingwindowsign.h"
#include "algorithms/veremeenko.h"


using namespace std;
using namespace NTL;

void randomZZVector(vector<ZZ> &exponents, int length, int bitLength) {
	for (int i = 0; i < length; i++) {
		ZZ tmp = RandomBits_ZZ(bitLength);
		exponents.push_back( tmp );
	}
}
void randomZZ_pVector(vector<ZZ_p> &bases, int length, int bitLength) {
	for (int i = 0; i < length; i++) {
		ZZ_p tmp = random_ZZ_p();
		bases.push_back( tmp );
	}
}
void launchOnFixedBasesExponents(ExpAlg* alg, vector<ZZ_p> bases, vector<ZZ> exponents) {
	ZZ_p res;
	for (int i = 0; i < bases.size(); ++i) {
		for (int j = 0; j < exponents.size(); ++j) {
			res = alg->exp(bases[i], exponents[j]);
		}
	}
}
void launchAlgorithms(vector<ExpAlg*> &algs) {
	double st = GetTime();
	double bitsOnTest = 16*1024;
	int testLengths[] = {8, 64, 512, 2048};
	for (int i = 0; i < sizeof(testLengths) / sizeof(int); i++) {
		int bitLength = testLengths[i];
		cout << "Running bit length = " << bitLength << endl;
		ZZ p = GenPrime_ZZ(bitLength, 80);//RandomBits_ZZ(bitLength);//
		cout << "\tprime generated " << endl;
		ZZ_p::init(p);

		int testBasesCount = (int) floor(sqrt(bitsOnTest / bitLength));
		int testExponentsCount = (int) ceil(sqrt(bitsOnTest / bitLength));

		vector<ZZ_p> bases;
		randomZZ_pVector(bases, testBasesCount, bitLength);

		vector<ZZ> exponents;
		randomZZVector(exponents, testExponentsCount, bitLength);

		for (unsigned int i = 0; i < algs.size(); ++i) {
			launchOnFixedBasesExponents(algs[i], bases, exponents);
		}

		bases.clear();
		exponents.clear();
	}
	cout << GetTime() - st << endl;
}

int main() {
	// algorithms
	vector<ExpAlg*> expAlgs;

	expAlgs.push_back(new Adelier::NtlExpAlg());
	expAlgs.push_back(new Adelier::RightToLeft());
	expAlgs.push_back(new Adelier::FloatingWindowUnsigned(8));
	expAlgs.push_back(new Adelier::Euclid(250, new Adelier::NtlExpAlg()));
	expAlgs.push_back(new Valtonis::SlidingWindowSignExponentation()); // Zp - field only

	//Tests
	if (!ExpAlgTests::testAll(expAlgs))
		return -1; // пока не пройдёт все тесты нет смысла идти дальше

	// smart profiling
	launchAlgorithms(expAlgs);


	for (auto it = expAlgs.begin(); it != expAlgs.end(); ++it) {
		delete *it;
	}

	return 0;
}
