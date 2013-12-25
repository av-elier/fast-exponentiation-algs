#ifndef KUNIHEROV_H_
#define KUNIHEROV_H_
#include "algorithms/kamenevs/VectorDictionatyAlg.h"
#include "algorithms/kamenevs/node.h"

class KuniheroVector : public VectorDictionaryAlg
{
	
public:
	int k;
	vector<string>* create_str_dicitionary(string s);
	vector<ZZ>* create_num_dicitionary(vector<string>& strs);
};
#endif 
