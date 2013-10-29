#include <iostream>
#include "NTL/ZZ.h"


void f1()
{
    NTL::ZZ p = NTL::GenPrime_ZZ(1024, 80); // takes quite a time
    std::cout << p << std::endl;
}


int main()
{
    int count = 25000;

    std::cout << "Started.\n";
    f1();
    std::cout << "Finished!\n";

    return 0;
}

