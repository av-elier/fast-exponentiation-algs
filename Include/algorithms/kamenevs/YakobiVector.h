#ifndef YAKOBIV_H_
#define YAKOBIV_H_
#include "algorithms/kamenevs/VectorDictionatyAlg.h"

class YakobiVector : public VectorDictionaryAlg
{
	
public:
	vector<string>* create_str_dicitionary(string s);
	vector<ZZ>* create_num_dicitionary(vector<string>& strs);
};
#endif 
