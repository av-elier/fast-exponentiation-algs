/*
 * NtlExpAlg.cpp
 *
 *  Created on: 19 дек. 2013 г.
 *      Author: Adelier
 */

#include "algorithms/NtlExpAlg.h"

namespace Adelier {

NtlExpAlg::NtlExpAlg() {
	setAuthor(L"ExpAlg");
	setMethod(L"NTL");

}

NtlExpAlg::~NtlExpAlg() {
	// TODO Auto-generated destructor stub
}

ZZ_p NtlExpAlg::exp(ZZ_p x, ZZ n){
	return power(x, n);
}

} /* namespace Adelier */
