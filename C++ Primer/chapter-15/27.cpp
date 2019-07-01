#include <string>
#include <iostream>
using namespace std;

class B
{
public:
    B(const string &s);
};
class A:public B
{
public:
    using B::B;
};