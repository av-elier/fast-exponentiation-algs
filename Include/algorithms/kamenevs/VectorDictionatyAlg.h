#ifndef VECTOR_DICTIONARY_H_
#define VECTOR_DICTIONARY_H_
#include <vector>
#include "chain_vector_class.h"
#include "node.h"
using namespace std;
class VectorDictionaryAlg 
{
private:
	void create_chain(vector<ZZ>& exponents);
	void create_elem(ZZ exponent, int column, int size);
	void precalc(vector<ZZ>& exponents);
	vector<ZZ_p>* exp(vector<ZZ_p>& bases);
	ZZ_p* Multiply(ZZ_p* a, ZZ_p* b, int size);
public:
	ChainVector chain;
	virtual vector<string>* create_str_dicitionary(string s) = 0;
	virtual vector<ZZ>* create_num_dicitionary(vector<string>& strs) = 0;
	vector<ZZ_p>* exp(vector<ZZ>& exponents, vector<ZZ_p>& bases);
};
#endif 