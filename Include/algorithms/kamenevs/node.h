#ifndef NODE_H_
#define NODE_H_
#include <string>
#include <list>
#include <vector>
using namespace std;

class Node {
	static 
	long leafsCount(Node* n);
	void paths(Node* n,string cur, vector<string>* arrOfPaths);
	bool IsLeaf();
	public:
		int value;
		double propagation;
		Node* left;
		Node* right;

		Node(int value);

		Node(int value, double propagation);

		Node(int value, bool left, bool right);

		void add_left(bool value);

		void add_right(bool value);

		long leafs_count();

		vector<string>* get_paths();
	};

bool compare (const Node* first, const Node* second);
Node* fill(int count, double propagationOfOne);
#endif