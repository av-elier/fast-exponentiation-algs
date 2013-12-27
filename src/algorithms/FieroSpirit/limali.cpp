/*
 * limali.cpp
 *
 *  Created on: 27 ���. 2013 �.
 *      Author: FieroSpirit
 */

#include "algorithms/fierospirit/limali.h"
//#include "limali.h"	q


namespace FieroSpirit {

limali::limali()
{
	setAuthor(L"FieroSpirit");
	setMethod(L"LimaLi");
}

limali::~limali() 
//the destructor. It is only one, u know
{
	G.clear();
}


template <typename T>
void limali::dec_base( T i, vector<int> &bin  )
//represents decimal number n in binary nubmber system(notation)
//lowest degree is located in the very first element of bin
//the highest in the last respectievely
{
	if ( i == 0 ) 
		bin.push_back(0);
	while( i >=1 )
	{
		bin.push_back( (i % 2) );
		i = i/2;
	}
}



ZZ_p limali::xdegree( ZZ_p x , int xdeg )
//x^xdeg
{
	ZZ_p res = conv<ZZ_p>(1) ;
	for ( int i = 0 ; i < xdeg ; i++ )
		res = product(res,x);
	return res;
}


int limali::pow2( unsigned int P)
//2^P
{
	int r = 1; // ��� ������� = 0 ��������� ����� 1
		for (; P-- > 0;)
			r *= 2;
	return r;
}


void limali::precalc(ZZ_p x)
{
	//xn = conv<ZZ_p>(0);
	//dec_base( n , nbin ) ;
	dec_base( ZZ_p::modulus() , nbin ) ;
	//dec_base( conv<ZZ>(4) , nbin ) ;
	l = nbin.size(); nbin.clear();
	h = (int)ceil( 0.001*l/2 );
	a = l/h;
	v = h = (int)ceil( 0.001*a/2 );
//	h = (int)ceil( 0.1*l/2 );
//	a = l/h;
//	v = h = (int)ceil( 0.1*a/2 );
	r = a/v; 
	gcomputing(x);
}

void limali::gcomputing(ZZ_p x)
//filling the map with computed values of G(j,i), where
//j in [0,v-1] ; i in [0, 2^h - 1]
{
	vector<int> ibin;
	ZZ_p temp = conv<ZZ_p>(1);
	for ( int i = 0 ; i <= pow2(h) - 1 ; i++ )
	{
		dec_base( i , ibin );
		for ( int j = 0 ; j < v ; j++ )
		{
			for ( int s = 0 ; s < h ; s++ )
			{
			try 
			{
				if ( ibin.at(s) == 1 )
					G[make_pair(j,i)] = xdegree( xdegree( x,pow2( a*s ) ) , pow2 ( j*r ) ); 
				else  
					G[make_pair(j,i)] = conv<ZZ_p>(1);
			 }
			catch (int )// (const std::out_of_range& oor)
			{
				//std::cerr << "Out of Range error: " << oor.what() << '\n';
				  G[make_pair(j,i)] = conv<ZZ_p>(1);
			}
			}
		}
		ibin.clear();
	}
}



ZZ_p limali::exp(ZZ n)
{
	ZZ_p y = conv<ZZ_p>(1);
	dec_base( n , nbin ) ;
	int i;

	for ( int k = r-1 ; k>= 0 ; k-- )
	{
		y = square(y);
		for ( int j = v-1 ; j>= 0 ; j-- )
		{
			i = 0;
			for ( int s = 0 ; s < h ; s++ )
			{
				int index = a*s + j*r + k ;
				if ( index < nbin.size() )
				{
					i = i + nbin[ index ]*pow2(s);
				}
				//else_if n_index = 0
				
			}
			y = product(y,G[make_pair(j,i)]);
		}
		
	}
	//xn = y;
	nbin.clear();
	return y;
}

} /* namespace FieroSpirit */
