#include "algorithms/veremeenko.h"

#include <cmath>

namespace Veremeenko {

	/* ============== LeftToRight ============== */

	LeftToRight::LeftToRight()
	{
		setAuthor(L"Veremeenko A. E.");
		setMethod(L"Left-Right");
	}

	ZZ_p LeftToRight::exp(ZZ_p x, ZZ n)
	{
		ZZ_p y = conv<ZZ_p>(x);
		long bit_length = NTL::NumBits(n);
		for (long i = bit_length - 2; i >= 0; --i) {
			y = NTL::sqr(y);
			if (NTL::bit(n, i)) {
				y *= x;
			}
		}

		return y;
	}


	/* ============== Yao ============== */

	Yao::Yao(long log2_numeral_system_base, long max_exponent_bit_length)
		: _log2_numeral_system_base(log2_numeral_system_base),
		  _max_exponent_bit_length(max_exponent_bit_length),
		  _numeral_system_base((long)pow(2, log2_numeral_system_base))
	{
		setAuthor(L"Veremeenko A. E.");
		setMethod(L"Yao");
	}

	void Yao::precalc(ZZ_p base)
	{
		LeftToRight l_to_r;
		_precalculated.resize(_max_exponent_bit_length / _log2_numeral_system_base);
		_precalculated[0] = base;
		for (long i = 1; i < _precalculated.size(); ++i) {
			_precalculated[i] = l_to_r.exp(_precalculated[i - 1], NTL::conv<ZZ>(_numeral_system_base));
		}
	}


	ZZ_p Yao::exp(ZZ n)
	{
		std::vector<long> coefficients(_precalculated.size(), 0);
		// вот так вот не очень красиво получаем коэффициенты разложения
		//cout << "\n\n========== Yao::exp ==========" << endl;
		for (long i = 0, q = 0; i < NTL::NumBits(n); ++q) {
			long power_of_2 = 1;
			for (const long bound = i + _log2_numeral_system_base; i < bound; ++i) {
				//std::cout << i << " ";
				if (NTL::bit(n, i)) {
					coefficients[q] += power_of_2;
				}
				power_of_2 *= 2;
			}
		}
		//NTL::bit_xor()

		//cout << "n = " << n << endl;
		//for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
		//	cout << *it << " ";
		//}
		//cout << endl;

		//cout << "x = " << _precalculated[0] << endl;
		//for (auto it = _precalculated.begin(); it != _precalculated.end(); ++it) {
		//	cout << *it << " ";
		//}
		//cout << endl;

		ZZ_p y = conv<ZZ_p>(1);
		ZZ_p u = conv<ZZ_p>(1);
		for (long j = _numeral_system_base - 1; j > 0; --j) {
			for (long i = 0; i < coefficients.size(); ++i) {
				if (coefficients[i] == j) {
					u *= _precalculated[i];
				}
			}
			y *= u;
		}

		return y;
	}

}