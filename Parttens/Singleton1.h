#include <iostream>
#include<pthread.h>

class Singleton1
{
    Singleton1()
    {
        std::cout << "Singleton1 construct function." << std::endl;
    }

    static Singleton1 * instance;

public:
    static Singleton1 *GetSingleton1()
    {
        return instance;
    }
};

Singleton1 *Singleton1::instance = new Singleton1;