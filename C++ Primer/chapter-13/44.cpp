#pragma once
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

class String
{
public:
    String();

    String(const char*s)
    {
        auto s1 = const_cast<char*>(s);
        while(*s1)
        {
            ++s1;
        }
        alloc_n_copy(s, s1);
    }
    String(const String&);
    String& operator=(const String&);
    ~String()
    {
        free();
    }
    void free()
    {
        if(elements)
        {
            for_each(elements, end, [this](char &rhs){alloc.destroy(&rhs);});
            alloc.deallocate(elements, end-elements);
        }
    }
private:
    allocator<char> alloc;
    char *elements;
    char *end;

    std::pair<char*, char*>alloc_n_copy(const char *a, const char *b)
    {
        auto s1 = alloc.allocate(b-a);
        auto s2 = uninitialized_copy(a, b, s1);
        return make_pair(s1, s2);
    }

    void range_initializer(const char *c, const char *d)
    {
        auto p = alloc_n_copy(d, c);
        elements = p.first;
        end = p.second;
    }
};