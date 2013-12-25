/*
 * WrapYakobi.cpp
 *
 *  Created on: 26 дек. 2013 г.
 *      Author: Adelier
 */

#include "algorithms/kamenevs/WrapYakobi.h"
#include "algorithms/kamenevs/Yakobi.h"


WrapYakobi::WrapYakobi(Yakobi *yakobi){
	this->yakobi = *yakobi;
}

WrapYakobi::~WrapYakobi() {
	// TODO Auto-generated destructor stub
}
