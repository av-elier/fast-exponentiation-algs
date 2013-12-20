#ifndef EUCLIDIANALG_H
#define EUCLIDIANALG_H

#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

//namespace Valtonis
namespace
{
    using namespace NTL;

    ZZ findInvr(const ZZ& a,const ZZ& p)//возвращает x уравнения ax = 1 (mod p)
    {
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
            cur_q = r[0] / r[1];
            cur_r = r[0] - r[1] * cur_q;
            cur_s = s[0] - cur_q * s[1];
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

}//END namespace


#endif // EUCLIDIANALG_H
