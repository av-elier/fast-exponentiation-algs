/*
 * MyTests.h
 *
 *  Created on: 28 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef MYTESTS_H_
#define MYTESTS_H_

#include <vector>

#include "MyTests.h"

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "../ExpAlgInterfaces.h"
#include "../algorithms/adelier/RightToLeftByAdelier.h"

NTL_CLIENT;

namespace MyTests {


static bool testFastAlg(ExpAlgFastInterface *algo){

	ZZ prime = conv<ZZ>(59);
	ZZ_p::init(prime);

	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>(2));
	ZZ samplen = conv<ZZ>(4);
	if ( algo->exp(samplex, samplen) != 16 ) // assert true
		return false;

	samplex = conv<ZZ_p>(conv<ZZ>("11"));
	samplen = conv<ZZ>("6");
	if ( algo->exp(samplex, samplen) != 27 ) { // assert true
		cout << algo->exp(samplex, samplen) << " : expected " << 27;
		return false;
	}

	return true;
}
static bool fixedBaseAlg(ExpAlgPrecalcXInterface *algo){

	ZZ prime = conv<ZZ>(59);
	ZZ_p::init(prime);

	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>(2));
	ZZ samplen = conv<ZZ>(4);
//	if ( algo->exp(samplex, samplen) != 16 ) // assert true
//		return false;
//	samplex = conv<ZZ_p>(conv<ZZ>("11"));
//	samplen = conv<ZZ>("6");
//	if ( algo->exp(samplex, samplen) != 27 ) // assert true
//		return false;
	return true;
}
static bool fixedExponentAlg(ExpAlgPrecalcNInterface *algo){

	ZZ prime = conv<ZZ>(59);
	ZZ_p::init(prime);

	ZZ_p samplex = conv<ZZ_p>(conv<ZZ>(2));
	ZZ samplen = conv<ZZ>(4);
//	if ( algo->exp(samplex, samplen) != 16 ) // assert true
//		return false;
//	samplex = conv<ZZ_p>(conv<ZZ>("11"));
//	samplen = conv<ZZ>("6");
//	if ( algo->exp(samplex, samplen) != 27 ) // assert true
//		return false;
	return true;
}
static bool run(
		vector<ExpAlgFastInterface*> fastAlgs,
		vector<ExpAlgPrecalcXInterface*> fixedBaseAlgs,
		vector<ExpAlgPrecalcNInterface*> fixedExponentAlgs){

	//ExpAlgFastInterface *AdelierRL = new Adelier::RightToLeft();


	bool success = true;

	for (unsigned int i = 0; i < fastAlgs.size(); ++i)
		if (testFastAlg(fastAlgs[i]))
			wcout<< fastAlgs[i]->getLogAuthorNamePath() <<L" test success"<<endl;
		else {
			wcout<< fastAlgs[i]->getLogAuthorNamePath() <<L" TEST FAILED!"<<endl;
			success = false;
		}
	return success;
}


} /* namespace RightToLeftByAdelier */

#endif /* MYTESTS_H_ */
