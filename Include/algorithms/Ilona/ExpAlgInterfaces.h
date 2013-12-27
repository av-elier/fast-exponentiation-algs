
#ifndef EXPALGINTERFACES_H_
#define EXPALGINTERFACES_H_


#include "NTL/ZZ.h"
#include "NTL/ZZ_p.h"

NTL_CLIENT

enum AlgTypes {ASd};

/*
 * Общие методы экспоненцирования
 */
class ExpAlg {
public:
	virtual ZZ_p exp(ZZ_p base, ZZ exponent) = 0;

	const std::wstring& getAuthor() const {
		return author;
	}
	const std::wstring& getMethod() const {
		return method;
	}
	void setAuthor(const std::wstring& author) {
		this->author = author;
	}
	void setMethod(const std::wstring& method) {
		this->method = method;
	}

private:
	// Должен быть задан в конструкторе вашей реализации
	std::wstring author;
	// Должен быть задан в конструкторе вашей реализации
	std::wstring method;
};

/*
 * Методы экспоненцирования с фиксированным основанием
 */
class ExpAlgFixedBase : public ExpAlg {
public:
	virtual void precalc(ZZ_p base) = 0;
	virtual ZZ_p exp(ZZ exponent) = 0;

	ZZ_p exp(ZZ_p base, ZZ exponent){
		precalc(base);
		return exp(exponent);
	}
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
};

#endif /* EXPALGINTERFACES_H_ */
