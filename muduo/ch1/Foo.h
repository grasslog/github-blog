#include "Observer.h"
#include "MutexLockGuard.h"

/* class Foo : public Observer
{
public: 
    Foo(Observable* s)
    {
        s->register_(this); // 构造函数泄露 this 指针
    }

    virtual void update();
}; */

class Foo : public Observer
{
public:
    Foo();
    virtual void update();

// 另外定义一个函数，在构造函数完成后执行回调函数的注册
    void observe(Observable* s)
    {
        s->register_(this);
    }
private:
    MutexLock mutex_;
};

//Foo* pFoo = new Foo;
//Observable* s = getSubject();
//pFoo->observe(s);

Foo::~Foo()
{
    MutexLockGuard lock(mutex_);
    // ...
}

void Foo::update()
{
    MutexLockGuard lock(mutex_);
    // ...
}

// thread A
delete x;
x = NULL;

// thread B
if (x) {
    x->update();
}
