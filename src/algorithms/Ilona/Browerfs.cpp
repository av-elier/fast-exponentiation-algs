
#include <stdio.h>
#include <locale>
#include <time.h>
#include "algorithms/Ilona/Browerfs.h"
#include "ExpAlgInterfaces.h"
using namespace std;
using namespace Ilona;

//NTL_CLIENT


BrowerSigned::BrowerSigned()
{
    setAuthor(L"Ilona Vinnichuk");
    setMethod(L"BrowerSigned");
	
    vecx[conv<ZZ>(0)]=conv<ZZ_p>(0);
		
	bin.empty();
	binN.empty();

	k = 0;
	
}

BrowerSigned::~BrowerSigned()
{
	vecx.clear();
	
	bin.~vector();
	binN.~vector();
}




 
/*------- auxiliary functions -------*/
 ZZ_p BrowerSigned::sum(ZZ_p a , ZZ_p b)
//сумма двух элементов конечного поля F_p
	{return a+b;}

 ZZ_p BrowerSigned::product(ZZ_p a , ZZ_p b)
//произведение двух элементов конечного поля F_p
	{return a*b;}

 ZZ_p BrowerSigned::square(ZZ_p a)
//возведение в квадрат элемента а из конечного поля F_p
	{return a*a;}
/*------- auxiliary functions have ended-------*/


ZZ BrowerSigned::findInvr(const ZZ& a)//возвращает x уравнения ax = 1 (mod p)
    {
		ZZ_p x;
		ZZ p = x.modulus();
        if(a == 1)
        {
            ZZ res = conv<ZZ>(1);
            return res;
        }
        ZZ* s = new ZZ[2];//коэффициенты при a
        ZZ* t = new ZZ[2];//коэффициенты при p, такие что: r[n-2] = s[0]*a + t[0]*p ; r[n-1] = s[1]*a + t[1]*p
        ZZ* r = new ZZ[2];//r[n] = r[0] - r[1]*q[n-1]
        s[0] = 0;
        t[0] = 1;
        r[0] = p;
        s[1] = 1;
        t[1] = 0;
        r[1] = a;
        ZZ cur_q;
        ZZ cur_r;
        ZZ cur_s;
        while(1)
        {

			if (r[1]==0)
				{
            cur_q=0;    
            } 
			else
            cur_q = r[0] / r[1];

            cur_r = r[0] - r[1] * cur_q;

            cur_s = s[0] - cur_q * s[1];
			 if (cur_r ==0)
			{
                delete []s;
                delete []t;
                delete []r;
                return conv<ZZ>(0);
            } 

            if(cur_r == 1)
            {
                delete []s;
                delete []t;
                delete []r;
                return cur_s;
            }
            ZZ cur_t = t[0] - cur_q * t[1];
            t[0] = t[1];
            t[1] = cur_t;
            s[0] = s[1];
            s[1] = cur_s;
            r[0] = r[1];
            r[1] = cur_r;
        }
    }




/*------- precomputations auxilary functions  -------*/
long long BrowerSigned::pow2( unsigned long long P)
//2^P
{
	long long r ;
	r = 1;
		for (; P-- > 0;)
			r *= 2;
	return r;
}

//int k;
 long long BrowerSigned::kcount( ZZ n , int limit , int &degree )
//log_2(n)<= ( k*(k+1)*2^(2^k) )/( 2^{k+1}-k-2 )
//either k found as a result of inequality solving, or set as limit
//degree = 2^k-1
{
	bool flag ;
	flag = false;
	int tmp, tmptmp, k;
		k=1 ;
	double logarifm2n;
	logarifm2n = log(n)/log(2.0);
	tmp = 0;
	//for( k = 1 ; (k <= limit) & (!flag)  ; k++ )
	while ( (k <= limit) & (!flag) )
	{
		tmp = pow2(k);
		tmptmp = pow2(tmp);
		if ( logarifm2n <= ( (k*k+k)*tmptmp/(tmp*2 - k - 2) ) )
			flag = true;
		else k++;
	}

	degree = tmp/2;
	if (!flag)
	{
		k = limit;
		degree = pow2(k-1);
	}
return k;
}

void BrowerSigned::dec_base( ZZ n, int base , vector<ZZ> &bin  )
//represents decimal number n in base=2k nubmber system(notation)
//lowest degree is located in the very first element of bin
//the highest in the last respectievely
{
	while( n >=1 )
	{
		bin.push_back( conv<ZZ>(n % base) );
	
		n = n/base;
	}
}


/*------- precomputations auxilary functions have ended -------*/


 void BrowerSigned::CreateNAF(ZZ x)
{
	long long sz = NumBits(x);
	long long size = sz + 1;

	ZZ c[2];
	c[0] = 0;
	ZZ* tempNAF = new ZZ[size];
	ZZ n[2];
	n[0] = bit(x,0);

	for (long long i = 0; i < size; i++)
	{
		n[1] = bit(x, i + 1);
		c[1] = (c[0] + n[0] + n[1]) / 2;
		tempNAF[i] = c[0] + n[0] - 2 * c[1];
		bin.push_back( tempNAF[i] );
		//cout<<bin[i];
		c[0] = c[1];
		n[0] = n[1];
	
	}

	
} 


 void BrowerSigned::InvNAF(ZZ n )
{
	long long l,z;
	int degree;
	l= bin.size();
	
	k=kcount( n , 1,degree );
	ZZ* tempInvNAF = new ZZ[l];
	
	z=l/k;
	for (long long i = 0; i < z; i++)
	{
		for (long long j = 0; j < k; j++)
		{
          tempInvNAF[i]+=bin[i*k+j]*pow2(j);
		}
        binN.push_back( tempInvNAF[i] );
          
	}
 
	if (l%k>0)
	{
		long long j = z*k;
		long long i=0;
		while (j<l)
		{
           tempInvNAF[z]+=bin[j+i]*pow2(i);
		    j++;
			i++;
		}
		binN.push_back( tempInvNAF[z] );
		
      
		
	}

} 

 void BrowerSigned::sigma( ZZ m , int k , int & s , ZZ & u )
//sigma(0) = (k,0)
//sigma(m) = (s,u), where m = u*2^s
{
	if ( IsZero(m) )
	{
		s = k ;
		u = 0 ;
	}
	else
	{
		s = 0;
		u = m;
		while ( conv<int>(u)% 2 == 0 )
		{
			u = u / 2 ;

			s++;
		}
	}
}

/*------- method auxilary functions have ended -------*/

/*------- method auxilary functions  -------*/
 void BrowerSigned::precalculate(  ZZ_p x,ZZ exponent )
//degree = 2^k-1
// vecx = [ 1,x^1,x^(-1),x^3,x^(-3), x^5, ... , x^degree, x^(-degree) ]
{
	//vecx.clear();
	//bin.~vector();
	//binN.~vector();

	//bin.empty();
	//binN.empty();

	//vecx[conv<ZZ>(0)]=conv<ZZ_p>(0);
	
    int degree;
	 
    ZZ p = x.modulus();
	int lim;

	ZZ i ;
	ZZ_p sq_x = square(x) ; 
	CreateNAF (exponent);
	
    k=kcount( exponent , 10 , degree );
	
	
	InvNAF(exponent );   


	vecx[conv<ZZ>(0)] = 1 ; 
	vecx[conv<ZZ>(1)] = x ;
	vecx[conv<ZZ>(-1)] = conv<ZZ_p>(findInvr(conv<ZZ>(x)));;
	
	vecx[conv<ZZ>(2)] = sq_x;
    vecx[conv<ZZ>(-2)] = conv<ZZ_p>(findInvr(conv<ZZ>(vecx[conv<ZZ>(2)])));
	if ( degree > 2 )
	{
		vecx[conv<ZZ>(3)] = product( x , sq_x) ; //x^3
    
		vecx[conv<ZZ>(-3)] = conv<ZZ_p>(findInvr(conv<ZZ>(vecx[conv<ZZ>(3)])));
		

		for ( i = conv<ZZ>(5) ; i <= conv<ZZ>(degree) ; ++(++i) )
		{
			vecx[i] = product(sq_x, vecx[i-conv<ZZ>(2)] ) ;
			vecx[-i] = conv<ZZ_p>(findInvr(conv<ZZ>(vecx[conv<ZZ>(i)])));
			
		}
	}

	
}





/*------- Brower's method -------*/
 ZZ_p BrowerSigned::exp( ZZ_p x , ZZ exponent )
//the method that should be assessed/measured !!!!!!!!
//it's called in brower_with_precomps  or anything like that
{	
	precalculate(x, exponent);
	int degree;
	ZZ_p y = conv<ZZ_p>(1);
	int i,j,s;
	ZZ u;
	ZZ ni;

	for ( i = binN.size()-1 ; i >= 0 ; i--)
	{
	
		ni = binN[i];
		sigma(ni,k,s,u);
		
		for ( j = 1 ; j <= k-s ; j++ )
			y = square( y );

		y = product( y , vecx[u] );
		
		for ( j = 1 ; j <= s ; j++ )
		{
			y = square( y );
		}
	}
	//bin.~vector();
	//binN.~vector();
	vecx.clear();
	binN.clear();
	bin.clear();
	return y;

}    
