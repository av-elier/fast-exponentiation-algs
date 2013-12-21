#ifndef KUNIHERO_H_
#define KUNIHERO_H_
#include "algorithms/kamenevs/DicitonaryAlg.h"
#include <list>
class Kunihero : public DictionaryAlg
{
	class Node {
	static bool compare (const Node* first, const Node* second)
	{
		return first->propagation > second->propagation;
	}
	long leafsCount(Node* n)
	{
		if (n==0)
			return 0;
		return n->IsLeaf() + leafsCount(n->left) + leafsCount(n->right);
	}
	void paths(Node* n,string cur, vector<string>* arrOfPaths)
	{
		if (n==0)
			return;
		if (n->value)
				cur += "1";
			else cur += "0";
		if (n->IsLeaf())
		{
			arrOfPaths->push_back(cur);
		}
		else
		{
			paths(n->left,cur,arrOfPaths);
			paths(n->right,cur,arrOfPaths);
		}
	}
	bool IsLeaf()
	{
		return right == 0 && left == 0;
	}
	public:
		int value;
		double propagation;
		Node* left;
		Node* right;

		Node(int value)
		{
			this->value = value;
			left = 0;
			right = 0;
		}

		Node(int value, double propagation)
		{
			this->value = value;
			this->propagation = propagation;
			left = 0;
			right = 0;
		}

		Node(int value, bool left, bool right)
		{
			this->value = value;
			this->left = new Node(left);
			this->right = new Node(left);
		}

		void add_left(bool value)
		{
			this->left = new Node(value);
		}

		void add_right(bool value)
		{
			this->right = new Node(value);
		}

		long leafs_count()
		{
			return leafsCount(this);
		}

		static Node* fill(int count, double propagationOfOne)
		{
			vector<int> v;
		
			Node* n = new Node(1);
			n->propagation = 1;
			Node* res = n;
			list<int> l;
			
			list<Node*>* nodes = new list<Node*>();
			while (res->leafs_count()<=count)
			{
				n->left = new Node(0,(1 - propagationOfOne) * n->propagation);
				nodes->push_back(n->left);
				n->right = new Node(1,propagationOfOne * n->propagation);
				nodes->push_back(n->right);
				nodes->sort(compare);
				n = nodes->front(); 
				nodes->pop_front();
			}
			return res;
		}

		vector<string>* get_paths()
		{
			vector<string>* res = new vector<string>();
			paths(this,"",res);
			return res;
		}
	};
public:
	int k;
	vector<string>* create_str_dicitionary(string s);
	vector<ZZ>* create_num_dicitionary(vector<string>& strs);
};
#endif 
