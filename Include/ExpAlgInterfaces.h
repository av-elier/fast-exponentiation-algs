/*
 * ExpAlgInterface.h
 *
 *  Created on: 26 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef EXPALGINTERFACES_H_
#define EXPALGINTERFACES_H_


enum ExpAlgos
{
    algLeftRight = 0,
    algRightLeft
};


class ExpAlgInterface {
public:
	ExpAlgInterface(){}
	virtual ~ExpAlgInterface(){}
};

class ExpAlg {
    virtual void setAuthor(std::string author) = 0;
    virtual void setMethod(std::string author) = 0;
};

class ExpAlgFastInterface : public ExpAlgInterface {
public:
	ExpAlgFastInterface(){}
	virtual ~ExpAlgFastInterface(){}

	virtual ZZ_p exp(ZZ_p x, ZZ n){return conv<ZZ_p>(0);}

};


class ExpAlgPrecalcXInterface : public ExpAlgInterface {
public:
	ExpAlgPrecalcXInterface(){}
	virtual ~ExpAlgPrecalcXInterface(){}

	virtual void precalculate(ZZ_p x){}
	virtual ZZ_p exp(ZZ n){return conv<ZZ_p>(0);}
};

class ExpAlgPrecalcNInterface : public ExpAlgInterface {
public:
	ExpAlgPrecalcNInterface(){}
	virtual ~ExpAlgPrecalcNInterface(){}

	virtual void precalculate(ZZ n){}
	virtual ZZ_p exp(ZZ_p x){return conv<ZZ_p>(0);}
};

#endif /* EXPALGINTERFACES_H_ */
