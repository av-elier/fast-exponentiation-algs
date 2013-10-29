//============================================================================
// Name        : fast-exponention-algs-main.cpp
// Author      : Adelier
// Version     : 0.0.0
// Copyright   : 
// Description : Homework 1-st year graduate students mmcs.sfedu.ru
//============================================================================

#include <iostream>
#include <vector>
#include <windows.h>
//#include "shlobj.h"

#include "nonUnitTests/MyTests.h"

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "./algorithms/RightToLeftByAdelier.h"

#include "Launcher.h"

using namespace std;
using namespace NTL;

const int TESTS_COUNT = 50000;
const double PROFFY_SAMPLING_DELAY = 1.0 / 200; // Delay between samples, so here set to 200 Hz
const wchar_t* PATH_TO_PROFFY_EXE = L"J:/Program Files/Proffy profiler/Proffy64.exe"; // Path to Proffy.exe
//const wchar_t* PATH_TO_PROFFY_OUT = L"./Profiler"; // Output directory for the result files. Should exist!!!


void MyCreateDirForAlgo(ExpAlgInterface* algo){
	::CreateDirectoryW(algo->getLogDirPath(), NULL);
	::CreateDirectoryW(algo->getLogAuthorPath(), NULL);
	::CreateDirectoryW(algo->getLogAuthorNamePath(), NULL);
}

// maybe TODO threading. Proffy rewrites file thread-<numthread>.xml (1)
void profile_fast_algo(int testsCount, ExpAlgFastInterface* algo) {
	// before profiling starts
	MyCreateDirForAlgo(algo);

	// TODO: generate array of pseudo-random x and n (locale-proof!)
	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>("1000000000000011"));
	ZZ samplen = conv<ZZ>("600000000000000000");

	ZZ_p res;


	const wchar_t* logPath = algo->getLogAuthorNamePath();

	// to profile
	{
		Proffy::Launcher profiler(PATH_TO_PROFFY_EXE, logPath, PROFFY_SAMPLING_DELAY);

		for (int i = 0; i < TESTS_COUNT; ++i) {
			res = algo->exp(samplex, samplen);
		}
	}
}

void profileFixedBaseAlgo(int testsCount, ExpAlgFastInterface* algo) {
	MyCreateDirForAlgo(algo);

}

void profileFixedExponentAlgo(int testsCount, ExpAlgFastInterface* algo) {
	MyCreateDirForAlgo(algo);

}

int main() {

	ZZ p = conv<ZZ>("27712789691413846856012333153970297296163904004968269562890174449688286689257199609606535023277510515406034761982956594518529310511546197362568094872418982726657993701492763179666043542495989488079404320326261147722413208737192692418855589011153981546533455140457076112131239236203432902115682930366048558529408451428808206998758788180262272085883410424636537719739093395540455527338386935943856295506908799163300014272396102579730407670957135454497986490504948008147820336881023710843768633407741391118690537112243688304714186312631347293412881026493085011018061051821439480590001356880342976195464741900137237920847");
	//ZZ p = GenPrime_ZZ(2048, 80); // takes quite a time
	ZZ_p::init(p);


	// algorithms
	vector<ExpAlgFastInterface*> fastAlgs;
	fastAlgs.push_back(new Adelier::RightToLeft());

	vector<ExpAlgPrecalcXInterface*> fixedBaseAlgs;

	vector<ExpAlgPrecalcNInterface*> fixedExponentAlgs;


	MyTests::run(fastAlgs, fixedBaseAlgs, fixedExponentAlgs);


	// NOTE: FIRST RUN IS SLOWER THAN NEXT. Probably NTL optimization
	// TODO solve this problem
	// their profiling
	for (int i = 0; i < fastAlgs.size(); ++i){
		wcout << L"Test "<< i << L": "<< fastAlgs[i]->name << L" by " << fastAlgs[i]->author << endl;
		profile_fast_algo(TESTS_COUNT, fastAlgs[i]);
	}



	return 0;
}
