/*
 * MyTests.h
 *
 *  Created on: 28 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef MYTESTS_H_
#define MYTESTS_H_

#include <vector>

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "ExpAlgInterfaces.h"
#include "algorithms/adelier/RightToLeftByAdelier.h"

NTL_CLIENT;

namespace MyTests {

bool success;

static bool testExpAlg(ExpAlg *algo){

	ZZ_p::init(conv<ZZ>(59));

	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>(2));
	ZZ samplen = conv<ZZ>(4);
	if ( algo->exp(samplex, samplen) != 16 ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << 16;
		return false;
	}

	ZZ_p::init(conv<ZZ>(59));
	samplex = conv<ZZ_p>(conv<ZZ>("11"));
	samplen = conv<ZZ>("6");
	if ( algo->exp(samplex, samplen) != 27 ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << 27;
		return false;
	}

	ZZ_p::init(conv<ZZ>(123));
	samplex = conv<ZZ_p>(conv<ZZ>("112"));
	samplen = conv<ZZ>("911");
	if ( algo->exp(samplex, samplen) != 58 ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << 58;
		return false;
	}

	ZZ_p::init(conv<ZZ>("662867092149154843"));
	samplex = conv<ZZ_p>(conv<ZZ>("13131313131313131"));
	samplen = conv<ZZ>("31313131313131313");
	if ( algo->exp(samplex, samplen) != conv<ZZ_p>(conv<ZZ>("312935641032900970")) ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << "312935641032900970";
		return false;
	}

	return true;
}
static void test(ExpAlg *algo){
	wcout << algo->getAuthor() << "'s " << algo->getMethod() << ":\t";
	try {
		if (testExpAlg(algo)) {
			cout<<"test success"<<endl;
		} else {
			cout<<"\tTEST FAILED!"<<endl;
			success = false;
		}
	} catch (int e) {
		cout<<"\tTEST FAILED! With exception"<<endl;
		success = false;
	}
}
static bool testAll(vector<ExpAlg*> &algos){
	success = true;
	for (unsigned int i = 0; i < algos.size(); ++i){
		test(algos[i]); //success = success && test(algos[i]);
		//delete algos[i];
	}
	return success;
}


} /* namespace RightToLeftByAdelier */

#endif /* MYTESTS_H_ */
