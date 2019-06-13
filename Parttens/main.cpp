#include "Singleton1.h"
#include <cstdlib>

int main()
{
    std::cout << "main begin" << std::endl;

    Singleton1 *ptr = Singleton1::GetSingleton1();
    Singleton1 *ptr2 = Singleton1::GetSingleton1();
    if(ptr == ptr2)
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }
    
    return 0;
}