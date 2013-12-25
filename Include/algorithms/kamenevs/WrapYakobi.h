/*
 * WrapYakobi.h
 *
 *  Created on: 26 дек. 2013 г.
 *      Author: Adelier
 */

#ifndef WRAPYAKOBI_H_
#define WRAPYAKOBI_H_

#include "DicitonaryAlg.h"
#include "Yakobi.h"

class WrapYakobi : public ExpAlg {
private:
	Yakobi yakobi;
public:
	WrapYakobi(Yakobi *yakobi);
	virtual ~WrapYakobi();
	void precalc(ZZ exponent){
		yakobi.precalc(exponent);
	}
	ZZ_p exp(ZZ_p base){
		return yakobi.exp(base);
	}
	ZZ_p exp(ZZ_p base, ZZ exponent){
		precalc(exponent);
		return exp(base);
	}
};


#endif /* WRAPYAKOBI_H_ */
