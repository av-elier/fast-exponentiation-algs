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

static bool testExpAlg(ExpAlg *algo){

	ZZ_p::init(conv<ZZ>(59));

	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>(2));
	ZZ samplen = conv<ZZ>(4);
	if ( algo->exp(samplex, samplen) != 16 ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << 16 << endl;
		return false;
	}

	ZZ_p::init(conv<ZZ>(59));
	samplex = conv<ZZ_p>(conv<ZZ>("11"));
	samplen = conv<ZZ>("6");
	if ( algo->exp(samplex, samplen) != 27 ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << 27 << endl;
		return false;
	}

	ZZ_p::init(conv<ZZ>(123));
	samplex = conv<ZZ_p>(conv<ZZ>("112"));
	samplen = conv<ZZ>("911");
	if ( algo->exp(samplex, samplen) != 58 ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << 58 << endl;
		return false;
	}

	ZZ_p::init(conv<ZZ>("662867092149154843"));
	samplex = conv<ZZ_p>(conv<ZZ>("13131313131313131"));
	samplen = conv<ZZ>("31313131313131313");
	if ( algo->exp(samplex, samplen) != conv<ZZ_p>(conv<ZZ>("312935641032900970")) ){ // assert true
		cout << algo->exp(samplex, samplen) << " != " << "312935641032900970" << endl;
		return false;
	}

	return true;
}
static bool test(ExpAlg *algo){
	bool success = true; // optimistic, yes
	wcout << algo->getAuthor() << "'s " << algo->getMethod() << ":\t";
	try {
		if (testExpAlg(algo)) {
			cout<<"test success"<<endl;
		} else {
			cout<<"TEST FAILED!"<<endl;
			success = false;
		}
	} catch (int e) {
		cout<<"TEST FAILED!"<<endl;
		success = false;
	}
	return success; // lie
}
static bool testAll(vector<ExpAlg*> &algos){
	bool success = true;
	for (unsigned int i = 0; i < algos.size(); ++i){
		success = success && test(algos[i]);
	}
	return success;
}


} /* namespace RightToLeftByAdelier */

#endif /* MYTESTS_H_ */
