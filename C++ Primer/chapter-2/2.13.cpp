#include <iostream>

int i = 42;
int main()
{
    std::cout << i << std::endl;
    int i = 100;
    std::cout << i << std::endl;
    int j = i;
    std::cout << j << std::endl;
}