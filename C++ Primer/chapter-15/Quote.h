#pragma once

#include <string>
using namespace std;
class Quote
{
    friend double print_total(ostream &,const Quote&,size_t);
public:
    Quote();
    Quote(const string &book,double sales_price):BookNo(book),price(sales_price) {}
    string isbn() const { return BookNo; }
    virtual double net_price(size_t n) const
    {
        return n * price;
    }
private:
    string BookNo;
protected:
    double price;
};

double print_total(ostream &os,const Quote &item,size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN" << item.isbn() << endl;
    os << "sold:" << n << " total price: " << ret << endl;
    return ret;
}


class bulk_quote : public Quote
{
public:
    bulk_quote() {}
    bulk_quote(const string &book, double p, size_t n, double disc):Quote(book,p),min_qty(n),discount(disc) {}
    double net_price(size_t cnt) const override
    {
        if(cnt >= min_qty)
        {
            return cnt * (1-discount) * price;
        }
        else 
        {
            return cnt * price;
        }
    }
private:
    double discount;
    size_t min_qty;
};