#include <bits/stdc++.h>
using namespace std;

class StrBlobPtr;

class StrBlob
{
public:
    friend class StrBlobPtr;
    StrBlobPtr begin();
    StrBlobPtr end();
    StrBlob();
    StrBlob(std::string il):data(make_shared<vector<string>> (il)) { }
    typedef vector<string>::size_type size_type;

    size_type size() const{
        return data->size();
    }

    bool empty()
    {
        return data->empty();
    }

    void pushback(const string &s)
    {
        data->push_back(s);
    }

    string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    void popback()
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const
    {
        if(i > data->size())
        {
            throw out_of_range(msg);
        }
    }
};

class StrBlobPtr
{
public: 
    StrBlobPtr():curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    string &deref() const
    {
        auto p = check(curr, "deference past end");
        return (*p)[curr];
    }
    StrBlobPtr &incr()
    {
        auto p = check(curr, "deference past end");
        ++curr;
        return *this;
    }
private:
    shared_ptr<vector<string>> check(size_t i, const string& msg) const
    {
        auto ret = wptr.lock();
        if(!ret)
        {
            throw runtime_error("not bind");
        }
        if(i >= ret->size())
        {
            throw out_of_range(msg);
        }
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}