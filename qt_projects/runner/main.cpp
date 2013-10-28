#include <iostream>



void f1()
{
    int sum = 0;
    while (sum < 10000)
        sum++;
}

void f2()
{
    long sum = 1;
    while (sum < 100000) {
        sum += 2;
        sum -= 1;
    }
}


int main()
{
    int count = 25000;

    std::cout << "Started.\n";
    for (int i=0; i < count; ++i) {
        f1();
        f2();
    }
    std::cout << "Finished!\n";

    return 0;
}

