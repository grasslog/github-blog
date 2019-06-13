#include<bits/stdc++.h>

using namespace std;

class MutexLock
{
public:
    MutexLock()
    {
        pthread_mutex_init(&mutex, NULL);
    }
    ~MutexLock()
    {
        pthread_mutex_lock(&mutex);
        pthread_mutex_destroy(&mutex);
    }
    void lock()
    {
        pthread_mutex_lock(&mutex);
    }
    void unlock()
    {
        pthread_mutex_unlock(&mutex);
    }
    pthread_mutex_t *get()
    {
        return &mutex;
    }
private:
    pthread_mutex_t mutex;
};

class MutexLockGuard
{
public:
    explicit MutexLockGuard(MutexLock &_mutex)
    : mutex(_mutex)
    {
        mutex.lock();
    }
    ~MutexLockGuard()
    {
        mutex.unlock();
    }
private:
    MutexLock mutex;
};

class Singleton
{
public:
    static Singleton *Instantialize();
    static Singleton *pInstance;
    static MutexLock mutex;
private:
    Singleton();
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton&);
};
Singleton* Singleton::pInstance = 0;

Singleton* Singleton::Instantialize()
{
    if(pInstance==NULL)
    {
        MutexLockGuard guard(mutex);
        if(pInstance==NULL)
        {
            pInstance = new Singleton();
        }
    }
    return pInstance;
}
