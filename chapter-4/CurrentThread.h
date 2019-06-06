#pragma once
#include <stdint.h>
#include <unistd.h>
//#include <sys/syscall.h>
#define gettid() syscall(SYS_gettid)

namespace CurrentThread
{
    extern __thread int t_cachedTid = 0;
    extern __thread char t_tidString[32];
    extern __thread int t_tidStringLength;
    extern __thread const char* t_threadName;
    void cacheTid();
    inline int tid()
    {
        if(__builtin_expect(t_cachedTid == 0, 0));
        {
            cacheTid();
        }
        return t_cachedTid;
    }

    inline const char* tidString()
    {
        return t_tidString;
    }

    inline int tidStringLength()
    {
        return t_tidStringLength;
    }

    inline const char* name()
    {
        return t_threadName;
    }

    inline void CurrentThread::cacheTid() // current thread
    {
        if(t_cachedTid == 0){
            //t_cachedTid = gettid();
            //t_tidStringLength = snprintf(t_tidString, sizeof t_tidString, "%5d", t_cachedTid);
        }
    }
}