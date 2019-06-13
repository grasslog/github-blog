#include <pthread.h>
#include <iostream>

class Singleton2
{
    Singleton2()
    {
        std::cout << "Singleton2()" << std::endl;
    }

    static Singleton2 *instance2;

public:
    static Singleton2 *GetSingleton2()
    {
        if(instance2 == NULL)
        {
            instance2 = new Singleton2();
            std::cout << "it is once" << std::endl;
        }
        else
        {
            std::cout <<"it is not need once" << std::endl;            
        }

        return instance2;
    }
};

Singleton2 *Singleton2::instance2 = nullptr;