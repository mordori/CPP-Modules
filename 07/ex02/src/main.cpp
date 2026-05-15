#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<const int>a{ 3};
    std::cout << a[2] << "\n";
    return 0;
}
