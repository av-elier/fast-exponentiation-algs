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


// Обычные
#include "algorithms/Pure.h"
#include "algorithms/NtlExpAlg.h"
#include "algorithms/adelier/RightToLeftByAdelier.h"
#include "algorithms/adelier/FloatingWindowUnsigned.h"
#include "algorithms/adelier/Euclid.h"
#include "algorithms/veremeenko.h"
#include "algorithms/Alex_Gusarin/slidingwindowsign.h"
#include "algorithms/Ilona/Montgomeri.h"
#include "algorithms/Ilona/Browerfs.h"
#include "algorithms/kamenevs/KuniHero.h"
#include "algorithms/kamenevs/Yakobi.h"
#include "algorithms/fierospirit/limali.h"
#include "algorithms/fierospirit/brower.h"
#include "algorithms/YGazaryan/RightToLeft.h"

#include "algorithms/kamenevs/WrapHiro.h"
#include "algorithms/kamenevs/WrapYakobi.h"

// Векторные
#include "algorithms/Popova/ShamirUnsigned.h"
#include "algorithms/Alex_Gusarin/shamirsign.h"
#include "algorithms/dvork1ng/MultiExpUnsigned.h"
#include "algorithms/dvork1ng/MultiExpSigned.h"


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
void multipleAlgLaunch(ExpAlg* alg, vector<ZZ_p> bases, vector<ZZ> exponents) {
	ZZ_p res;
	for (int i = 0; i < bases.size(); ++i) {
		for (int j = 0; j < exponents.size(); ++j) {
			res = alg->exp(bases[i], exponents[j]);
		}
	}
}
void launchAlgorithms(vector<ExpAlg*> &algs) {
	double st = GetTime();
	double bitsOnTest = 50*1024;
	int testLengths[] = { 2048};
	for (int i = 0; i < sizeof(testLengths) / sizeof(int); i++) {
		int bitLength = testLengths[i];
		cout << "Running bit length = " << bitLength << endl;
		ZZ p = GenPrime_ZZ(bitLength, 80);  // 2^{-80} probability to be mistaken if it's trully prime
		cout << "\tprime generated " << endl;
		ZZ_p::init(p);

		int testBasesCount = (int) floor(sqrt(bitsOnTest / bitLength));
		int testExponentsCount = (int) ceil(sqrt(bitsOnTest / bitLength));

		vector<ZZ_p> bases;
		randomZZ_pVector(bases, testBasesCount, bitLength);

		vector<ZZ> exponents;
		randomZZVector(exponents, testExponentsCount, bitLength);

		for (auto it = algs.begin(); it != algs.end(); ++it) {
			double start = GetTime();
			multipleAlgLaunch(*it, bases, exponents);
			cout << GetTime() - start << " sec";
			wcout << (*it)->getAuthor() << "'s " << (*it)->getMethod() << ":\t" << endl;
		}
	}
	cout << GetTime() - st << endl;
}

int main() {
	ZZ_p::init(conv<ZZ>(59));
	// algorithms
	vector<ExpAlg*> expAlgs;

	expAlgs.push_back(new Adelier::RightToLeft());
	expAlgs.push_back(new Adelier::FloatingWindowUnsigned(8));
	expAlgs.push_back(new Adelier::Euclid(250, new Adelier::NtlExpAlg()));
	expAlgs.push_back(new Veremeenko::Yao(2, 2048));  // bit_length_of_numeral_system_base, max_n_bit_length
	expAlgs.push_back(new Veremeenko::LeftToRight());
	expAlgs.push_back(new FieroSpirit::limali());
	expAlgs.push_back(new FieroSpirit::brower());
	expAlgs.push_back(new Valtonis::SlidingWindowSignExponentation(8)); // Zp - field only
	expAlgs.push_back(new Ilona::Montgomeri());
	expAlgs.push_back(new YGazaryan::RightToLeft());
	expAlgs.push_back(new Ilona::BrowerSigned());
	expAlgs.push_back(new WrapYakobi(new Yakobi()));
	expAlgs.push_back(new WrapHiro(new Kunihero()));
	expAlgs.push_back(new Adelier::NtlExpAlg());


	// векторные
	//expAlgs.push_back(new Popova::ShamirUnsigned());
	//expAlgs.push_back(new Valtonis::ShamirSign());
	//	expAlgs.push_back(new dvork1ng::MultiExpSigned());
	//	expAlgs.push_back(new dvork1ng::MultiExpUnsigned());

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
