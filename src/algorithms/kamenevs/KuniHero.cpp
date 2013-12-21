#include "algorithms/kamenevs/KuniHero.h"
#include <algorithm>

vector<string>* Kunihero::create_str_dicitionary(string s)
{
	double p = 0;
	for (int i = 0; i < s.length(); ++i)
		p+=s[i] - 48;
	p /= s.length();
	double q = 1 - p;

	Node* n = Node::fill(k,p);
	
	vector<string>* res = (n->get_paths());
	
	for (int i = 0; i < res->size(); ++i)
	{
		(*res)[i] = (*res)[i].substr(0,(*res)[i].find_last_of("1")+1).c_str();
	}
	return res;
}
vector<ZZ>* Kunihero::create_num_dicitionary(vector<string>& strs)
{
	vector<ZZ>* res = new vector<ZZ>();
		for (int i = 0; i < strs.size(); ++i)
		{
			ZZ z;
			conv(z,0);
			for (int j = 0; j < strs[i].size(); ++j)
			{
				if (strs[i][j]=='1')
				{
					SetBit(z,strs[i].size() - j - 1);
				}
			}
			res->push_back(z);
		}
		return res;
}
