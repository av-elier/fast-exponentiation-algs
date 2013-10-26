/*
 * ExpAlgInterface.h
 *
 *  Created on: 26 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef EXPALGINTERFACES_H_
#define EXPALGINTERFACES_H_

#include "BigIntGF.h"

class ExpAlgInterface {
public:
	ExpAlgInterface();
	virtual ~ExpAlgInterface();
};


//! Пишу свои варианты в дополнение к твоим. Потом будем их комбинировать


// Пустой класс для порядка, а может потом как-нибудь и пригодится.
class Exponentiation {

};

class ExpAlgFastInterface : ExpAlgInterface {
public:
	ExpAlgFastInterface();
	virtual ~ExpAlgFastInterface();

	virtual BigIntGF exp(BigIntGF x, BigIntGF n);

};

class ExpAlgPrecalcInterface : ExpAlgInterface {
public:
	ExpAlgPrecalcInterface();
	virtual ~ExpAlgPrecalcInterface();

	virtual void precalculate();
	virtual BigIntGF exp(BigIntGF xn);
};


//template <typename T>
//class GeneralExponentiation : public Exponentiation {
    //template <typename T>
    //T exp(T
//};

class ExpAlgPrecalcXInterface : ExpAlgPrecalcInterface {
public:
	ExpAlgPrecalcXInterface(BigIntGF x);
	virtual ~ExpAlgPrecalcXInterface();

	virtual void precalculate();
	virtual BigIntGF exp(BigIntGF n);
};

class ExpAlgPrecalcNInterface : ExpAlgPrecalcInterface {
public:
	ExpAlgPrecalcNInterface(BigIntGF n);
	virtual ~ExpAlgPrecalcNInterface();

	virtual void precalculate();
	virtual BigIntGF exp(BigIntGF x);
};

#endif /* EXPALGINTERFACES_H_ */
