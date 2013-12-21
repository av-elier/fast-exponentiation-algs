#ifndef DICTIONARY_H_
#define DICTIONARY_H_
#include "ExpAlgInterfaces.h"
#include <vector>
#include "chain_class.h"
using namespace std;
class DictionaryAlg : public ExpAlgFixedPower
{
private:
public:
	Chain chain;
	virtual vector<string>* create_str_dicitionary(string s) = 0;
	virtual vector<ZZ>* create_num_dicitionary(vector<string>& strs) = 0;
	void create_chain(ZZ exponent);
	void create_elem(ZZ exponent);
	ZZ_p precalc(ZZ exponent);
	ZZ_p exp(ZZ_p base);
	//ZZ_p exp(ZZ_p base,ZZ exponent);
};
#endif 
