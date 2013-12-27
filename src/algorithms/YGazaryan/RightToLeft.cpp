#include "algorithms/YGazaryan/RightToLeft.h"

namespace YGazaryan {

RightToLeft::RightToLeft(){
		setAuthor(L"YGazaryan");
		setMethod(L"RightToLeft");
		bin.empty();
}
RightToLeft::~RightToLeft(){
    bin.~vector();
}
void RightToLeft::CreateNAF(ZZ x)
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
ZZ RightToLeft::findInvr(const ZZ& a)//���������� x ��������� ax = 1 (mod p)
    {
		ZZ_p x;
		ZZ p = x.modulus();
        if(a == 1)
        {
            ZZ res = conv<ZZ>(1);
            return res;
        }
        ZZ* s = new ZZ[2];//������������ ��� a
        ZZ* t = new ZZ[2];//������������ ��� p, ����� ���: r[n-2] = s[0]*a + t[0]*p ; r[n-1] = s[1]*a + t[1]*p
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
ZZ_p RightToLeft::exp(ZZ_p x, ZZ exponent){

	bin.clear();

	ZZ_p y = conv<ZZ_p>(1);
	ZZ temp;

    CreateNAF(exponent);
    int l = bin.size()-1;

	for(int i = 0; i <= l; ++i){
		if (bin[i] == 1)
			y*=x;
        if (bin[i] == -1) {
			y*=conv<ZZ_p>(findInvr(conv<ZZ>(x)));
		}
       
	   x*=x;
	}
	return y;
}


}
