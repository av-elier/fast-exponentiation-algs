#include "algorithms/dvork1ng/MultiExpUnsigned.h"

namespace dvork1ng 
{
	MultiExpUnsigned::MultiExpUnsigned()
	{
		setAuthor(L"dvork1ng");
		setMethod(L"MultiExpSigned");
	}

	MultiExpUnsigned::~MultiExpUnsigned()
	{
	}

	ZZ MultiExpUnsigned::ExpandMinExp(ZZ lessExp, ZZ bigExp)
	{
		int minLength = NumBits(lessExp);
		int maxLength = NumBits(bigExp);

		lessExp.SetSize(maxLength);

		while (minLength < maxLength)
		{
			minLength++;
			if (bit(lessExp, minLength))
			{
				SwitchBit(lessExp, minLength);
			}
			
		}
		
		return lessExp;
	}

	void MultiExpUnsigned::precalculate(ZZ_p x, ZZ_p x1)
	{
		xx1 = x * x1;
	}

	ZZ_p MultiExpUnsigned::exp(ZZ_p x, ZZ exp, ZZ_p x1, ZZ exp1)
	{
		ZZ_p result = conv<ZZ_p>(1);

		int l = NumBits(exp) > NumBits(exp1) ? NumBits(exp) : NumBits(exp1);

		if (NumBits(exp) != NumBits(exp1))
		{
			if (NumBits(exp) == l)
			{
				exp1 = ExpandMinExp(exp1, exp);
			}
			else
			{
				exp = ExpandMinExp(exp, exp1);
			}
		}


		for (int i = l - 1; i >= 0; --i)
		{
			result *= result;
			if (bit(exp, i) == 1 && bit(exp1, i) == 1)
			{
				result *= xx1;
			}
			else if (bit(exp, i) == 1 && bit(exp1, i) == 0)
			{
				result *= x;
			}
			else if (bit(exp, i) == 0 && bit(exp1, i) == 1)
			{
				result *= x1;
			}
		}
		return result;
	}
} /* namespace dvork1ng */
