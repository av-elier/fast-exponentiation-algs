/*
 * MyTests.h
 *
 *  Created on: 28 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef _EXP_ALG_TESTS_H_
#define _EXP_ALG_TESTS_H_

#include <vector>

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

#include "ExpAlgInterfaces.h"
#include "algorithms/adelier/RightToLeftByAdelier.h"

NTL_CLIENT;

namespace ExpAlgTests {

struct TestValues
{
	ZZ prime;
	ZZ base;
	ZZ exponent;
	ZZ result;
	TestValues(ZZ p, ZZ b, ZZ e, ZZ r) : prime(p), base(b),
		exponent(e), result(r) {}
};

static bool testExpAlg(ExpAlg *algo){


	vector<TestValues> test_values;  // TestValues(prime, base, exponent, result)
	test_values.push_back(TestValues(conv<ZZ>(59), conv<ZZ>(2), conv<ZZ>(4), conv<ZZ>(16)));
	test_values.push_back(TestValues(conv<ZZ>(59), conv<ZZ>("11"), conv<ZZ>("6"), conv<ZZ>(27)));
	test_values.push_back(TestValues(conv<ZZ>("662867092149154843"), conv<ZZ>("13131313131313131"),
		conv<ZZ>("31313131313131313"), conv<ZZ>("312935641032900970")));

	for (auto it = test_values.begin(); it != test_values.end(); ++it) {
		ZZ_p::init(it->prime);
		ZZ_p tmp = algo->exp(conv<ZZ_p>(it->base), it->exponent);
		if (tmp != conv<ZZ_p>(it->result)) {
			cout << tmp << " != " << conv<ZZ_p>(it->result) << endl;
			return false;
		}
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
		cout<<"\tTEST FAILED! With exception"<<endl;
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


} /* namespace ExpAlgTests */

#endif /* _EXP_ALG_TESTS_H_ */
