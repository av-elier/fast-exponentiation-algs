#include <iostream>
#include "NTL/ZZ.h"

using namespace std;

int main()
{
    NTL::ZZ p = NTL::GenPrime_ZZ(512);
    cout << p << endl;
    return 0;
}

