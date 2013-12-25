#include "algorithms/kamenevs/chain_vector_class.h"

ChainVector::ChainVector()
{};
int ChainVector::Size()
{
	return link.size();
};
void ChainVector::Generation(vector<ZZ> high_number)
{
	/*Заполнение первоначальных звеньев цепочки*/
	int size=high_number.size();
	for (int i=0; i<size; ++i)
	{
		Link temp;
		for (int j=0; j<size; ++j)
			if (i==j)
				temp.chain_v.push_back((conv<ZZ>(1)));
			else
				temp.chain_v.push_back((conv<ZZ>(0)));
		temp.start = 0;
		temp.end = 0;
		link.push_back(temp);
	}
	while (link[Size()-1].chain_v!=high_number)
	{
		int a;
		Add(NewLink(high_number));
	}
};
bool ChainVector::Add(Link l)
{
	for (int i = 0; i < Size(); ++i)
	{
		bool equals = true;
		for (int j = 0; j < width; ++j)
			if (l.chain_v[j]!=link[i].chain_v[j])
			{
				equals = false;
				break;
			}
		if (equals)
			return false;
	}
	link.push_back(l);
	return true;
};
ChainVector::Link ChainVector::NewLink(vector<ZZ> high_number)
{
	int *numbers_of_high_vectors = new int[high_number.size()]; 
	for (int i = 0; i < high_number.size(); ++i)
		numbers_of_high_vectors[i] = -1;
	int j = 0;
	int i = 0;
	int flag = 0;//номер элемента в звене, который надо довести до заданного
	while (!flag)
	{
		if (link[i].chain_v[j] != high_number[j])
		{
			if (i < Size()-1)
				++i;
			else
			{
				if (numbers_of_high_vectors[j] != -1)
				{   if (j < high_number.size()-1)
					{
						i = 0;
						++j;
					}
					else
						flag = 1;
				}
				else
					flag = 1;
			}
		}
		else
		{
			numbers_of_high_vectors[j] = i;
			if (j == high_number.size()-1)
			{
				flag = 1;
				++j;
			}
			else
			{
				++j;
				i = 0;
			}
		}
	}
	if (j<high_number.size())
	{
		/*Поиск последнего вектора, ненулевого в данной позиции*/
		int number = Size()-1;
		while (conv<int>(link[number].chain_v[j]) == 0)
			--number;
		{
			ZZ res = link[number].chain_v[j];
			int i = number;
			int position = number;
			while ((conv<int>(link[position].chain_v[j])+conv<int>(link[i].chain_v[j]) > conv<int>(high_number[j])) 
				| (conv<int>(link[i].chain_v[j]) == 0))
			{
				--i;
			}
			Link temp;
			for (int k=0; k<high_number.size(); ++k)
				temp.chain_v.push_back(link[position].chain_v[k] + link[i].chain_v[k]);
			temp.start = position;
			temp.end = i;
			return temp;
		}
	}
	else
	{
		vector<ZZ> start_value =  link[numbers_of_high_vectors[0]].chain_v;
		int index_start_value = numbers_of_high_vectors[0];
		Link temp;
		for (int i = 1; i < high_number.size(); ++i)
		{
			for (int k=0; k<high_number.size(); ++k)
				temp.chain_v.push_back(start_value[k] + link[numbers_of_high_vectors[i]].chain_v[k]);
			temp.start = numbers_of_high_vectors[i];
			i==1 ? temp.end = index_start_value : temp.end = Size()-1;
			start_value = temp.chain_v;
			index_start_value = numbers_of_high_vectors[i];
			if (i != high_number.size() - 1) 
			{
				Add(temp);
				temp.chain_v.clear();
			}
		}
		return temp;
	}
}
