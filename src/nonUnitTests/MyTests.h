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
#include "../algorithms/RightToLeftByAdelier.h"

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
	if ( algo->exp(samplex, samplen) != 27 ) // assert true
		return false;
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
static void run(
		vector<ExpAlgFastInterface*> fastAlgd,
		vector<ExpAlgPrecalcXInterface*> fixedBaseAlgs,
		vector<ExpAlgPrecalcNInterface*> fixedExponentAlgs){

	ExpAlgFastInterface *AdelierRL = new Adelier::RightToLeft();
	if (testFastAlg(AdelierRL))
		cout<<"test success"<<endl;
	else
		cout<<"TEST FAILED!"<<endl;
}


} /* namespace RightToLeftByAdelier */

#endif /* MYTESTS_H_ */
