#include "algorithms/kamenevs/Yakobi.h"
#include <algorithm>

vector<string>* Yakobi::create_str_dicitionary(string s)
{
	reverse(s.begin(),s.end());
	int i = 0;
	vector<string>* strs = new vector<string>();
	vector<string>* res = new vector<string>();
	string tmp = "";
	while (i<s.length())
	{
		tmp.insert(0,1,s[i++]);
		bool contains = false;
		for (int i = 0; i < strs->size(); ++i)
			if (!(*strs)[i].compare(tmp))
			{
				contains = true;
				break;
			}
		if (!contains)
		{
				strs->push_back(tmp);
				tmp.clear();
		}
	}
	for (int i = 0; i < strs->size();++i)
	{
		string tmp = (*strs)[i].substr(0,(*strs)[i].find_last_of("1")+1);
		if (!tmp.size() || tmp.find('1')==string::npos)
			continue;
		tmp = tmp.substr((*strs)[i].find_first_of("1"));
		bool contains = false;
		for (int j = 0; j < res->size();++j)
		{
			if (!(*res)[j].compare(tmp))
			{
				contains = true;
				break;
			}
		}
		if (contains)
			continue;
		else 
			res->push_back(tmp);
	}
	return res;
	
	return strs;
}
vector<ZZ>* Yakobi::create_num_dicitionary(vector<string>& strs)
{
	vector<ZZ>* dictionary = new vector<ZZ>();
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
		dictionary->push_back(z);
	}
	return dictionary;
}
