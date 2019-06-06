#include "mutex.h"
#include <stdlib.h>
#include <stdio.h>

void someFunctionMayCallExit()
{
    exit(1);
}

class GlobalObject
{
public:
    void doit()
    {
        MutexLockGuard lock(mutex_);
        someFunctionMayCallExit();
    }

    ~GlobalObject()
    {
        printf("GlobalObject:~GlobalObject() \n");
        MutexLockGuard lock(mutex_);
        printf("GlobalObject:~GlobalObject() cleanning\n");
    }

private:
    MutexLock mutex_;
};

GlobalObject g_obj;

int main()
{
    g_obj.doit();
}