#include "algorithms/Ilona/Montgomeri.h"

namespace Ilona {

Montgomeri::Montgomeri() {
	setAuthor(L"Ilona");
	setMethod(L"Montgomeri");
}
Montgomeri::~Montgomeri() {
}
ZZ_p Montgomeri::exp(ZZ_p x, ZZ exponent) {
	ZZ_p y = x;
	ZZ_p z = x * x;

	int l = NumBits(exponent);

	for (int i = l - 2; i >= 0; --i) {
		if (bit(exponent, i) == 1) {
			y *= z;
			z *= z;
		} else {
			z *= y;
			y *= y;
		}
	}
	return y;
}

} /* namespace Adelier */
