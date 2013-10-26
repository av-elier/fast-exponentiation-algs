/*
 * BigIntGF.h
 *
 *  Created on: 26 ���. 2013 �.
 *      Author: Adelier
 */

#ifndef BIGINTGF_H_
#define BIGINTGF_H_


class BigIntGF{
public:
	BigIntGF();
	virtual ~BigIntGF();

	/// returns x*x
	BigIntGF sqr();
	/// returns x*y
	BigIntGF mult(BigIntGF y);
private:
};


#endif /* BIGINTGF_H_ */