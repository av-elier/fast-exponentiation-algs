/*
 * ExpAlgInterface.h
 *
 *  Created on: 26 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef EXPALGINTERFACES_H_
#define EXPALGINTERFACES_H_


#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

NTL_CLIENT

/*
 * Общие методы экспоненцирования
 */
class ExpAlg {
public:
	virtual ZZ_p exp(ZZ_p base, ZZ exponent) = 0;

	const std::string& getAuthor() const {
		return author;
	}
	const std::string& getMethod() const {
		return method;
	}
	virtual ~ExpAlg() = 0;

private:
	// Должен быть задан в конструкторе вашей реализации
	std::string author;
	// Должен быть задан в конструкторе вашей реализации
	std::string method;
};

/*
 * Методы экспоненцирования с фиксированным основанием
 */
class ExpAlgFixedBase : public ExpAlg {
public:
	virtual ZZ_p precalc(ZZ_p base) = 0;
	virtual ZZ_p exp(ZZ exponent) = 0;

	ZZ_p exp(ZZ_p base, ZZ exponent){
		precalc(base);
		return exp(exponent);
	}
	virtual ~ExpAlgFixedBase() = 0;
};

/*
 * Методы экспоненцирования с фиксированной экспонентой
 */
class ExpAlgFixedPower : public ExpAlg {
public:
	virtual ZZ_p precalc(ZZ exponent) = 0;
	virtual ZZ_p exp(ZZ_p base) = 0;

	ZZ_p exp(ZZ_p base, ZZ exponent){
		precalc(exponent);
		return exp(base);
	}
	virtual ~ExpAlgFixedPower() = 0;
};

#endif /* EXPALGINTERFACES_H_ */
