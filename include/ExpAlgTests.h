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

	ZZ prime = conv<ZZ>(59);
	ZZ_p::init(prime);

	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>(2));
	ZZ samplen = conv<ZZ>(4);
	if ( algo->exp(samplex, samplen) != 16 ) // assert true
		return false;

	samplex = conv<ZZ_p>(conv<ZZ>("11"));
	samplen = conv<ZZ>("6");
	if ( algo->exp(samplex, samplen) != 27 ) // assert true
		return false;

	return true;
}
static bool test(ExpAlg *algo){
	bool success = true; // optimistic, yes
	if (testExpAlg(algo))
		cout<<"test success"<<endl;
	else {
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
