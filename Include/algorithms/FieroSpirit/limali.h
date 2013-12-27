/*
 * limali.h
 *
 *  Created on: 27 ���. 2013 �.
 *      Author: FieroSpirit
 */

#ifndef LIMALI_H_
#define LIMALI_H_
#include <stdio.h>
#include <NTL/ZZ_p.h>
#include <NTL/ZZ.h>
#include <vector>
#include <map>
#include <cmath>
#include "ExpAlgInterfaces.h"
using namespace std;
NTL_CLIENT

namespace FieroSpirit {

class limali : public ExpAlgFixedBase {
public:
	//limali::limali();
	limali();
	~limali();

	void precalc(ZZ_p x);
	ZZ_p exp(ZZ n);


private:
	ZZ p;
	ZZ n;
	ZZ_p x;

	//method's auxilary variables and structures
	int h;
	int a;
	int v;
	int r;
	int l;
	map< pair<int,int> , ZZ_p > G;
	vector<int> nbin;


	/*------- auxiliary functions -------*/
	inline ZZ_p sum(ZZ_p a , ZZ_p b)
	//����� ���� ��������� ��������� ���� F_p
		{return a+b;}

	inline ZZ_p product(ZZ_p a , ZZ_p b)
	//������������ ���� ��������� ��������� ���� F_p
		{return a*b;}

	inline ZZ_p square(ZZ_p a)
	//���������� � ������� �������� � �� ��������� ���� F_p
		{return a*a;}
	/*------- auxiliary functions have ended-------*/


	template <typename T>
	void dec_base( T i, vector<int> &bin  );
	//represents decimal number n in binary nubmber system(notation)
	//lowest degree is located in the very first element of bin
	//the highest in the last respectievely

	ZZ_p xdegree( ZZ_p x , int xdeg );
	//x^xdeg

	int pow2( unsigned int P);
//2^P

	void gcomputing(ZZ_p x);
	//filling the map with computed values of G(j,i), where
	//j in [0,v-1] ; i in [0, 2^h - 1]

};

} /* namespace FieroSpirit */

#endif /* LIMALI_H_ */
