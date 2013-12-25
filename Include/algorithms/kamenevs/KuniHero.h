#ifndef KUNIHERO_H_
#define KUNIHERO_H_
#include "algorithms/kamenevs/DicitonaryAlg.h"
#include "node.h"

class Kunihero : public DictionaryAlg
{
	
public:
	int k;
	vector<string>* create_str_dicitionary(string s);
	vector<ZZ>* create_num_dicitionary(vector<string>& strs);
};
#endif 