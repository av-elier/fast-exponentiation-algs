/*
 * BigIngGF.h
 *
 *  Created on: 26 окт. 2013 г.
 *      Author: Adelier
 */

#ifndef BIGINGGF_H_
#define BIGINGGF_H_

class BigIntGF {
public:
	BigIntGF();
	virtual ~BigIntGF();

	/// returns x*x
	BigIntGF sqr();

	/// returns x*y
	BigIntGF mult(BigIntGF y);


};



#endif /* BIGINGGF_H_ */
