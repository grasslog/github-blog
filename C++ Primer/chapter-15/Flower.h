#pragma once
#include <string>
using namespace std;

class Flower
{
public:
    Flower();
    Flower(const string& s,double sale_price):name(s),Price(sale_price){}
    virtual int net_price() const = 0;
protected:
    double Price;
private:
    string name;
};

class Rose:public Flower
{
public:
    Rose();
    Rose(const string &SR,double n,size_t m):Flower(SR,n),quantity(m){}
    int net_price() const 
    {
        return quantity * Price;
    }
protected:
    size_t quantity;
};

class Discount_Rose:public Rose
{
public:
    Discount_Rose();
    Discount_Rose(const string &SR,double n,size_t m,double disc):Rose(SR,n,m),discount(disc){}
    int net_price() const
    {
        return quantity * Price *(1-discount);
    }
protected:
    double discount;
};
