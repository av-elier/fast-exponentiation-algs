/*
 * brower.cpp
 *
 *  Created on: 22 ���. 2013 �.
 *      Author: FieroSpirit
 */

#include "algorithms/FieroSpirit/brower.h"

using namespace std;
using namespace FieroSpirit;

brower::brower() 
{
	setAuthor(L"FieroSpirit");
	setMethod(L"Brower ");


}

brower::brower(ZZ_p _x, ZZ _n) 
{
	x = _x;
	n = _n;
	setAuthor(L"FieroSpirit");
	setMethod(L"Brower ");

}

brower::~brower() 
{
	x = conv<ZZ_p>(0);
	n = conv<ZZ>(0);
	k = 0;
	base = 0;
	bin.~vector();
	arr.clear();
}

/*------- precomputations auxilary functions  -------*/
inline int brower::pow2( unsigned int P)
//2^P
{
	return 1<<P;
//	int w = 1; // ��� ������� = 0 ��������� ����� 1
//		for (; P-- > 0;)
//			w *= 2;
//	return w;
}


void brower::kcount( ZZ n , int limit )
//log_2(n)<= ( k*(k+1)*2^(2^k) )/( 2^{k+1}-k-2 )
//either k found as a result of inequality solving, or set as limit
//degree = 2^k-1
{
	bool flag = false; //we have not reached/found a border=k yet
	int tmp ;
	k = 1;
	double logarifm2n = log(n)/log(2.0);
	tmp = 0;
	while ( (k <= limit) & (!flag) )
	{
		tmp = pow2(k);
		if ( logarifm2n <= ( (k*(k+1))*pow2(tmp)/(tmp*2 - k - 2) ) )
			flag = true;
		else k++;
	}

	base = (int)tmp/2;
	if (!flag)
	{
		k = limit;
		base = pow2(k-1);
	}
}

void brower::dec_base( ZZ i, int basenum )
//represents decimal number n in base=2k nubmber system(notation)
//lowest degree is located in the very first element of bin
//the highest in the last respectievely
{
	if ( i == 0 ) 
		bin.push_back(0);
	while( i >=1 )
	{
		bin.push_back( i % basenum );
		i = i/basenum;
	}
}
/*------- precomputations auxilary functions have ended -------*/


/*------- method auxilary functions  -------*/
void brower::precomps( int degree )
//degree = 2^k-1
// arr = [ x^3, x^5, ... , x^degree ]
{
	int i ;	
	ZZ_p sq_x = x*x ; //x^2
	arr[0] = 1 ; //essential!!!!!!! 
	arr[1] = x ;

	arr[2] = sq_x;
	if ( degree > 2 )
	{
		arr[3] = x*sq_x ; //x^3
		for ( i = 5 ; i <= degree ; ++(++i) )
		{
			arr[i] = sq_x*arr[i-2] ;
		}
	}
}

void brower::sigma( int m , int & s , int & u )
//sigma(0) = (k,0)
//sigma(m) = (s,u), where m = u*2^s
{
	if ( m==0 )
	{
		s = k ;
		u = 0 ;
	}
	else
	{
		s = 0;
		u = m;
		while ( u % 2 == 0 )
		{
			u = u / 2 ;
			s++;
		}
	}
}
/*------- method auxilary functions have ended -------*/

void brower::precalc(ZZ_p x , ZZ n)
{
	int limit = 100000000000; 
	//we don't want to compute it for all our life. Thus I've stricted the number k.

	kcount( n , limit );//base = 2^k-1
	
	dec_base( n, base*2 ); // n = (n_{l-1},...,n_0)_{2^k} is placed in bin

	precomps( base*2 ); // x^0,x^1,x^3,x^5,x^7,...,x^{2^k-1}

}

ZZ_p brower::exp(ZZ_p x, ZZ n)
{
	this->x = x;
	this->n = n;
	ZZ_p y = conv<ZZ_p>(1);
	int i,j,s,u,ni;

	precalc( x , n);

	for ( i = bin.size()-1 ; i >= 0 ; i--)
	{
		ni = bin.at(i);
		sigma(ni,s,u);
		
		for ( j = 1 ; j <= k-s ; j++ )
			y = y*y;

		if (arr.find(u)!=arr.end() )
		y = y*arr[u];
		
		for ( j = 1 ; j <= s ; j++ )
			y = y*y;
	}
	k = 0;
	base = 0;
	//bin.~vector();
	arr.clear();
	bin.clear();
	return y;
}

