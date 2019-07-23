#include "Counter.h"

void swap(Counter& a,Counter& b)
{
    MutexLockGuard aLock(a.mutex_);
    MutexLockGuard bLock(b.mutex_);
    int64_t value = a.value_;
    a.value_ = b.value_;
    b.value_ = value;
}

// 如果线程 A 执行 swap(a,b); 而同时线程 B 执行 swap(b,a);就有可能产生死锁; operator=() 也是类似的道理

Counter& Counter::operator=(const Counter& rhs)
{
    if(this == &rhs)
    return *this;

    MutexLockGuard myLock(mutex_);
    MutexLockGuard itsLock(rhs.mutex_);
    value_ = rhs.value_;
    return *this;
}