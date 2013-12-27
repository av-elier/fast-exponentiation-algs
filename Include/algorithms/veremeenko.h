#ifndef _LEFT_TO_RIGHT_BY_ARWER_H_
#define _LEFT_TO_RIGHT_BY_ARWER_H_

#include <vector>

#include "ExpAlgInterfaces.h"


namespace Veremeenko {

	class LeftToRight : public ExpAlg {
	public:
		LeftToRight();
		ZZ_p exp(ZZ_p x, ZZ n);
	};


	class Yao : public ExpAlgFixedBase {
	public:
		Yao(long log2_numeral_system_base, long max_exponent_bit_length);
		void precalc(ZZ_p base);
		ZZ_p exp(ZZ n);
	private:
		std::vector<ZZ_p> _precalculated;
		const long _log2_numeral_system_base, _max_exponent_bit_length;
		const long _numeral_system_base;

	};

} /* namespace Veremeenko */


#endif /* _LEFT_TO_RIGHT_BY_ARWER_H_ */