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

#include <sstream>

using namespace NTL;
using namespace std;

class ExpAlgInterface {
public:
	const wchar_t* author; // unique
	const wchar_t* name; // unique

	ExpAlgInterface(){
		author = L"author";
		name = L"name";
	}
	virtual ~ExpAlgInterface(){}


	const wchar_t* getLogDirPath(){
		return L"./Profiler";
	}
	const wchar_t* getLogAuthorPath(){
		std::wostringstream buf;
		buf << getLogDirPath() << L"/" << author;
		return buf.str().c_str();
	}
	const wchar_t* getLogAuthorNamePath(){
		std::wostringstream buf;
		buf << getLogAuthorPath() << L"/" << name;
		return buf.str().c_str();
	}
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
