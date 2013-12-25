#include <NTL/ZZ_pXFactoring.h>
#include <NTL/ZZ_pEX.h>
#include <vector>
NTL_CLIENT


#ifndef _CHAIN_VECTOR
#define _CHAIN_VECTOR
class ChainVector{
public:
	class Link {
	public:
		vector<ZZ> chain_v;
		vector<string> bits;
		int start;
		int end;
	};
	vector<Link> link;
	ChainVector();
	int width;
	int Size();
	void Generation(vector<ZZ> high_number);
	bool Add(Link l);
private:
	
	Link NewLink(vector<ZZ> high_number);
};
#endif