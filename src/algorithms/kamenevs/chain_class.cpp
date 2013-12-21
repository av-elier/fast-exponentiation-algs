#include "algorithms/kamenevs/chain_class.h"

Chain::Chain()
{
	Link temp;
	temp.chain_v = 1;
	temp.bits = "1";
	temp.start = 0;
	temp.end = 0;
	link.push_back(temp);
};
int Chain::Size()
{
	return link.size();
}
void Chain::Generation(ZZ_p high_number)
{
	/*while (link[Size()-1].chain_v!=high_number)
	{
		int a;
		Add(NewLink(high_number));
	}*/
};
bool Chain::Add(Link l)
{
	for (int i = 0; i < link.size(); ++i)
		if (link[i].chain_v==l.chain_v)
			return false;
	link.push_back(l);
	return true;
};
Chain::Link Chain::NewLink(ZZ_p high_number)
{
	if (conv<int>(link[Size()-1].chain_v)+conv<int>(link[Size()-1].chain_v) <= conv<int>(high_number))
	{
		Link temp;
		temp.chain_v = link[Size()-1].chain_v + link[Size()-1].chain_v;
		temp.start = Size()-1;
		temp.end = Size()-1;
		return temp;
	}
	else
	{
		ZZ res = link[Size()-1].chain_v;
		int i = Size()-1;
		int position = Size()-1;
		while (conv<int>(link[position].chain_v)+conv<int>(link[i].chain_v) > conv<int>(high_number))
		{
			--i;
		}
		Link temp;
		temp.chain_v = link[position].chain_v + link[i].chain_v;
		temp.start = position;
		temp.end = i;
		return temp;
	}
}
