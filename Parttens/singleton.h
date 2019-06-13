#include <pthread.h>
#include <iostream>

class singleton
{
private:
    singleton()
    {
        pthread_mutex_init(&mutex, NULL);
    }

    static singleton* p;
    static pthread_mutex_t mutex;

public:
    static singleton *instance()
    {
        if(p == nullptr){
            pthread_mutex_lock(&mutex);
            if(p == nullptr)
            {
                p = new singleton();
            }
            pthread_mutex_unlock(&mutex);          
        }
        
        return p;
    }
};

pthread_mutex_t singleton::mutex;
singleton *singleton::p = nullptr;