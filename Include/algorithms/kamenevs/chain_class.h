#include <NTL/ZZ_pXFactoring.h>
#include <NTL/ZZ_pEX.h>
#include <vector>
#include <string>
NTL_CLIENT


#ifndef _CHAIN
#define _CHAIN
class Chain{
public:
	class Link {
	public:
		ZZ chain_v;
		string bits;
		int start;
		int end;
	};
	vector<Link> link;
	Chain();
	int Size();
	void Generation(ZZ_p high_number);
	bool Add(Link l);
private:
	
	Link NewLink(ZZ_p high_number);
};
#endif
