#ifndef YAKOBI_H_
#define YAKOBI_H_
#include "DicitonaryAlg.h"

class Yakobi : public DictionaryAlg
{
	
public:
	vector<string>* create_str_dicitionary(string s);
	vector<ZZ>* create_num_dicitionary(vector<string>& strs);
};
#endif 
