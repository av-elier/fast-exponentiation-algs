#include "algorithms/kamenevs/DicitonaryAlg.h"

void DictionaryAlg::create_elem(ZZ exponent)
{
	for (int i = 0; i < chain.link.size(); ++i)
		if (exponent == chain.link[i].chain_v)
			return;
	string sBits = "";
	for (int i = NumBits(exponent) - 1; i >= 0 ; --i)
			sBits+=(bit(exponent,i) + 48);
	//cout<<sBits.c_str()<<endl;
	int k = 0;
	for (int i = 0; i < this->chain.link.size(); ++i)
	{
		int tmp = this->chain.link[i].bits.length();
		if (tmp>k)
			k = tmp;
	}
	int start = 0;
	int end = min (start + k, (int)sBits.length());
	ZZ res = conv<ZZ>(0);
	int step = end - start;
	while (1)
	{
		string tmp = sBits.substr(start,end - start);
		if (!tmp.length())
			break;
		int max = 0;
		int index = -1;
		
		for (int i = 0; i < this->chain.link.size(); ++i)
		{
			int size = min((int)this->chain.link[i].bits.size(),(int)tmp.size());
			if (size<max)
				continue;
			int count = 0;
			for (int j = 0; j < size ; ++j)
			{
				if (this->chain.link[i].bits[j]!=tmp[j])
					break;
				++count;
			}
			if (count==chain.link[i].bits.size())
			{
				max = size;
				index = i;
			}
			count = 0;
		}
		for (int i = 0; i < max; ++i)
		{
			int ind;
				for (ind = chain.link.size()-1; ind >= 0; --ind)
					if (chain.link[ind].chain_v==res)
						break;
			res *= 2;
			if (res!=0)
			{
				Chain::Link link;
				
				link.start =ind;
				link.end = ind;
				link.chain_v = res;
				string s;
				for (int i = NumBits(res) - 1; i >= 0; --i)
					s += bit(res,i) + 48;
				link.bits = s;
				if (chain.Add(link))
				{
					//cout<<res<<endl;
					if (NumBits(res)>k)
						k = NumBits(res);
				}
			}
		}
		int ind;
			for (ind = chain.link.size()-1; ind >= 0; --ind)
				if (chain.link[ind].chain_v==res)
					break;
		res += this->chain.link[index].chain_v;
		Chain::Link link;
		link.start = ind;
		link.end = index;
		link.chain_v = res;
		string s;
		for (int i = NumBits(res) - 1; i >= 0; --i)
			s += bit(res,i) + 48;
		link.bits = s;
		if (chain.Add(link))
		{
			//cout<<res<<endl;
			if (NumBits(res)>k)
				k = NumBits(res);
		}
		start += max;
		while (start < sBits.length() && sBits[start] == '0')
		{
			++start;
			int ind;
				for (ind = chain.link.size()-1; ind >= 0; --ind)
					if (chain.link[ind].chain_v==res)
						break;
			res *= 2;
			if (res!=0)
			{
				Chain::Link link;
				
				link.start =ind;
				link.end = ind;
				link.chain_v = res;
				string s;
				for (int i = NumBits(res) - 1; i >= 0; --i)
					s += bit(res,i) + 48;
				link.bits = s;
				if (chain.Add(link))
				{
					//cout<<res<<endl;
					if (NumBits(res)>k)
						k = NumBits(res);
				}
			}
		}
		if (end>sBits.length() || start >= sBits.length())
			break;
		end = min (start + k, (int)sBits.length());
	}

}
void DictionaryAlg::create_chain(ZZ exponent)
{
	string sBits = "";
	for (int i = NumBits(exponent) - 1; i >= 0 ; --i)
			sBits+=(bit(exponent,i) + 48);
	//cout<<sBits.c_str()<<endl;
	vector<string> strDictionary = *create_str_dicitionary(sBits);
	vector<ZZ> dictionary = *create_num_dicitionary(strDictionary);

	for (int i = 0; i < strDictionary.size(); ++i)
	{
		create_elem(dictionary[i]);
	}
	create_elem(exponent);
	
}

ZZ_p DictionaryAlg::precalc(ZZ exponent)
{
	create_chain(exponent);
	return conv<ZZ_p>(0);
}

ZZ_p DictionaryAlg::exp(ZZ_p base)
{
	Chain v = this->chain;
	ZZ_p *result = new ZZ_p[v.Size()+1];
	result[0] = base;
	for (int i = 1; i < v.Size(); ++i) 
	{
		result[i] = result[v.link[i].start]*result[v.link[i].end];
	}
	return result[v.Size()-1];
}
