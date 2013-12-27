#include "algorithms/dvork1ng/MultiExpSigned.h"

namespace dvork1ng
{
	MultiExpSigned::MultiExpSigned()
	{
		setAuthor(L"dvork1ng");
		setMethod(L"MultiExpSigned");
	}

	MultiExpSigned::~MultiExpSigned()
	{
	}

	ZZ MultiExpSigned::ExpandMinExp(ZZ lessExp, ZZ bigExp)
	{
		int minLength = NumBits(lessExp);
		int maxLength = NumBits(bigExp);

		lessExp.SetSize(maxLength);

		while (minLength < maxLength)
		{
			minLength++;
			lessExp = SwitchBit(lessExp, 0);
		}

		return lessExp;
	}

	void MultiExpSigned::precalculate(ZZ_p x, ZZ_p x1)
	{
		x_ = 1 / x;
		x1_ = 1 / x1;
		xx1 = x * x1;
		x_x1 = x_ * x1;
		xx1_ = x * x1_;
		x_x1_ = x_ * x1_;
	}

	NAF MultiExpSigned::ConvertToNAF(ZZ exp)
	{
		ZZ	normalExp = exp;
		NAF result;
		// -------------------- adding zeros to the end of exponent <start>--------
		if (bit(exp, NumBits(exp) - 1) == 0)
		{
			if (bit(exp, NumBits(exp) - 2) != 0)
			{
				normalExp.SetSize(NumBits(exp) + 1);
				if (bit(exp, NumBits(exp) - 1) != 0)
				{
					SwitchBit(exp, NumBits(exp) - 1);
				}
			}
		}
		else
		{
			normalExp.SetSize(NumBits(exp) + 2);
			if (bit(exp, NumBits(exp) - 1) != 0)
			{
				SwitchBit(exp, NumBits(exp) - 1);
			}
			if (bit(exp, NumBits(exp) - 2) != 0)
			{
				SwitchBit(exp, NumBits(exp) - 2);
			}
		}
		// -------------------- adding zeros to the end of exponent <end>--------

		int c0 = 0;
		int c1;
		int temp;
		int length = NumBits(normalExp);
		for (int i = 0; i < length - 2; ++i)
		{
			c1 = floor((c0 + bit(exp, length - i) + bit(exp, length - i - 1)) / 2);
			temp = c0 + bit(exp, length - i) - 2 * c1;
			result.exp.SetSize(i + 1);
			result.service.SetSize(i + 1);
			switch (temp)
			{
				case 0:
				{
					if (bit(result.exp, i) == 1)
					{
						SwitchBit(result.exp, i);
					}
					if (bit(result.exp, i) == 1)
					{
						SwitchBit(result.exp, i);
					}
					break;
				}
				case 1:
				{
					if (bit(result.exp, i) == 0)
					{
						SwitchBit(result.exp, i);
					}
					if (bit(result.exp, i) == 1)
					{
						SwitchBit(result.exp, i);
					}
					break;
				}
				case -1:
				{
					if (bit(result.exp, i) == 0)
					{
						SwitchBit(result.exp, i);
					}
					if (bit(result.exp, i) == 0)
					{
						SwitchBit(result.exp, i);
					}
					break;
				}
			}
		}
		return result;
	}

	ZZ_p MultiExpSigned::exp(ZZ_p x, ZZ exp, ZZ_p x1, ZZ exp1)
	{
		ZZ_p result = conv<ZZ_p>(1);

		NAF expNAF = ConvertToNAF(exp);
		NAF exp1NAF = ConvertToNAF(exp1);

		int l = NumBits(expNAF.exp) > NumBits(exp1NAF.exp) ? NumBits(expNAF.exp) : NumBits(exp1NAF.exp);

		if (NumBits(expNAF.exp) != NumBits(exp1NAF.exp))
		{
			if (NumBits(expNAF.exp) == l)
			{
				exp1NAF.exp = ExpandMinExp(exp1NAF.exp, expNAF.exp);
			}
			else
			{
				expNAF.exp = ExpandMinExp(expNAF.exp, exp1NAF.exp);
			}
		}

		for (int i = l - 1; i >= 0; --i)
		{
			result *= result;
			if ((bit(expNAF.exp, i) == 1 && bit(expNAF.service, i) == 0) &&
				(bit(exp1NAF.exp, i == 1) && bit(exp1NAF.service, i) == 0))    //x = 1, x1 = 1
			{
				result *= xx1;
			}
			else if ((bit(expNAF.exp, i) == 1 && bit(expNAF.service, i) == 1) &&  //x = -1, x1 = 1
				(bit(exp1NAF.exp, i == 1) && bit(exp1NAF.service, i) == 0))
			{
				result *= x_x1;
			}
			else if ((bit(expNAF.exp, i) == 1 && bit(expNAF.service, i) == 0) &&  //x = 1, x1 = -1
				(bit(exp1NAF.exp, i == 1) && bit(exp1NAF.service, i) == 1))
			{
				result *= xx1_;
			}
			else if ((bit(expNAF.exp, i) == 1 && bit(expNAF.service, i) == 1) &&  //x = -1, x1 = -1
				(bit(exp1NAF.exp, i == 1) && bit(exp1NAF.service, i) == 1))
			{
				result *= x_x1_;
			}
			else if ((bit(expNAF.exp, i) == 0) &&                               //x = 0, x1 = 1
				(bit(exp1NAF.exp, i == 1) && bit(exp1NAF.service, i) == 0))
			{
				result *= x1;
			}
			else if ((bit(expNAF.exp, i) == 0) &&                              //x = 0, x1 = -1
				(bit(exp1NAF.exp, i == 1) && bit(exp1NAF.service, i) == 1))
			{
				result *= x1_;
			}
			else if ((bit(expNAF.exp, i) == 1 && bit(expNAF.service, i) == 0) &&   //x = 1, x1 = 0
				(bit(exp1NAF.exp, i == 0)))
			{
				result *= x;
			}
			else if ((bit(expNAF.exp, i) == 1 && bit(expNAF.service, i) == 1) &&  //x = 1, x1 = 0
				(bit(exp1NAF.exp, i == 0)))
			{
				result *= x_;
			}
		}
		return result;
	}
} /* namespace dvork1ng */
