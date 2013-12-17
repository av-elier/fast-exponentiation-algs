//============================================================================
// Name        : fast-exponention-algs-main.cpp
// Author      : Adelier
// Version     : 0.0.0
// Copyright   : 
// Description : Homework 1-st year graduate students mmcs.sfedu.ru
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>

#include "ExpAlgTests.h"

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "algorithms/adelier/RightToLeftByAdelier.h"
#include "algorithms/Alex_Gusarin/slidingwindowsign.h"


using namespace std;
using namespace NTL;

const int TESTS_COUNT = 3000;


void profile_fast_algo(int testsCount, ExpAlg* algo) {
        // before profiling starts
        // TODO: generate array of pseudo-random x and n
        ZZ_p samplex = conv<ZZ_p>(conv<ZZ>("1000000000000011"));
        ZZ samplen = conv<ZZ>("600000000000000000");

        ZZ_p res;

        // to profile
        {
                double st = GetTime();
                for (int i = 0; i < TESTS_COUNT; ++i) {
                        res = algo->exp(samplex, samplen);
                }
                cout << GetTime() - st << endl;
        }
}

void randomBigIntegerListZZ(vector<ZZ> &exponents, int length, int bitLength) {
	for (int i = 0; i < length; i++) {
		ZZ tmp = RandomBits_ZZ(bitLength);
		exponents.push_back( tmp );
	}
}
void randomBigIntegerListZZ_p(vector<ZZ_p> &bases, int length, int bitLength) {
	for (int i = 0; i < length; i++) {
		ZZ_p tmp = random_ZZ_p();
		bases.push_back( tmp );
	}
}
void profile(ExpAlg* alg, vector<ZZ_p> bases,
		vector<ZZ> exponents) {
	ZZ_p res;
	for (int i = 0; i < bases.size(); ++i) {
		for (int j = 0; j < exponents.size(); ++j) {
			res = alg->exp(bases[i], exponents[j]);
		}
	}
	cout << res << endl;
}
void completeProf(vector<ExpAlg*> &algs) {
	double bitsOnTest = 8*1024;
	int testLengths[] = {8, 64, 512, 2048, 4*1024};
	for (int i = 0; i < sizeof(testLengths) / sizeof(int); i++) {
		int bitLength = testLengths[i];
		cout << "Running bit length = " << bitLength << endl;
		ZZ p = RandomBits_ZZ(bitLength);
		ZZ_p::init(p);
		int testBasesCount = (int) floor(sqrt(bitsOnTest / bitLength));
		int testExponentsCount = (int) ceil(sqrt(bitsOnTest / bitLength));
		vector<ZZ_p> bases;
		randomBigIntegerListZZ_p(bases, testBasesCount, bitLength);
//		for (unsigned int i = 0; i < bases.size(); ++i)
//			cout << bases[i] << " "; cout << endl;
		vector<ZZ> exponents;
		randomBigIntegerListZZ(exponents, testExponentsCount, bitLength);
//		for (unsigned int i = 0; i < exponents.size(); ++i)
//			cout << exponents[i] << " "; cout << endl;
		for (unsigned int i = 0; i < algs.size(); ++i) {
			cout << "Profiling: " << i << endl;
			profile(algs[i], bases, exponents);
		}
		bases.clear();
		exponents.clear();

	}
}

int main() {
	// algorithms
	vector<ExpAlg*> expAlgs;
	expAlgs.push_back(new Adelier::RightToLeft());
	//expAlgs.push_back(new Valtonis::SlidingWindowSignExponentation());

	//Tests
	if (!MyTests::testAll(expAlgs))
		return -1; // пока не пройдёт все тесты нет смысла считать время


	ZZ p = conv<ZZ>("27712789691413846856012333153970297296163904004968269562890174449688286689257199609606535023277510515406034761982956594518529310511546197362568094872418982726657993701492763179666043542495989488079404320326261147722413208737192692418855589011153981546533455140457076112131239236203432902115682930366048558529408451428808206998758788180262272085883410424636537719739093395540455527338386935943856295506908799163300014272396102579730407670957135454497986490504948008147820336881023710843768633407741391118690537112243688304714186312631347293412881026493085011018061051821439480590001356880342976195464741900137237920847");
	//ZZ p = GenPrime_ZZ(2048, 80); // takes quite a time
	ZZ_p::init(p);

	// good profiling
	completeProf(expAlgs);

	// their profiling
//	for (unsigned int i = 0; i < expAlgs.size(); ++i)
//		profile_fast_algo(TESTS_COUNT, expAlgs[i]);



	return 0;
}
