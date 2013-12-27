/*
 * brower.cpp
 *
 *  Created on: 22 ���. 2013 �.
 *      Author: FieroSpirit
 */

#ifndef BROWER_H_
#define BROWER_H_

#include <stdio.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ.h>
#include <vector>
#include <map>
#include <cmath>
#include "ExpAlgInterfaces.h"

using namespace std;
NTL_CLIENT

namespace FieroSpirit{
class brower : public ExpAlg {
public:
	brower();
	brower(ZZ_p _x, ZZ n);
	~brower();
	ZZ_p exp(ZZ_p x, ZZ n);
private:
	ZZ_p x;
	ZZ n;
	int k;
	int base;

	vector<int> bin;
	map<int,ZZ_p> arr;



/*------- precomputations auxilary functions  -------*/
int pow2( unsigned int P);
//2^P

void kcount( ZZ n , int limit );
//log_2(n)<= ( k*(k+1)*2^(2^k) )/( 2^{k+1}-k-2 )
//either k found as a result of inequality solving, or set as limit
//sets base = 2^k-1

void dec_base( ZZ i, int basenum );
//represents decimal number n in base=2k nubmber system(notation)
//lowest degree is located in the very first element of bin
//the highest in the last respectievely
/*------- precomputations auxilary functions have ended -------*/


/*------- method auxilary functions  -------*/
void precomps( int degree );
//degree = 2^k-1
// vecx = [ x^3, x^5, ... , x^degree ]

void sigma( int m , int & s , int & u );
//sigma(0) = (k,0)
//sigma(m) = (s,u), where m = u*2^s
/*------- method auxilary functions have ended -------*/

void precalc(ZZ_p x , ZZ n);

};
}

#endif /* BROWER_H_ */
