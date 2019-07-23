#pragma once

#include <string>
using namespace std;
class Quote
{
    friend double print_total(ostream &,const Quote&,size_t);
public:
    Quote();
    Quote(const string &book,double sales_price):BookNo(book),price(sales_price) {}
    Quote(const Quote &quote1):BookNo(quote1.BookNo),price(quote1.price)
    {
        cout << "Copy construct function." << endl;
    }
    Quote(const Quote &&quote3):BookNo(move(quote3.BookNo)),price(move(quote3.price))
    {
        cout << "Move construct function." << endl;
    }
    string isbn() const { return BookNo; }
    virtual double net_price(size_t n) const
    {
        cout << "Quote" << endl;
        return n * price;
    }
    virtual void debug()
    {
        cout << "This is Quote Class" << endl;
        cout << "ISBN " << BookNo << endl;
        cout << "Price: " << price << endl;
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
        cout << "bulk_uote" << endl;
        if(cnt >= min_qty)
        {
            cout << cnt*(1-discount)*price<<endl;
            return cnt * (1-discount) * price;
        }
        else 
        {
            return cnt * price;
        }
    }
    void debug()
    {
        cout << "This is bulk_quote Class" << endl;
        cout << "DISCOUNT: " << discount << endl;
        cout << "Min_qty: " << min_qty << endl;
        cout << "Price; " << price << endl;
    }
private:
    double discount;
    size_t min_qty;
};

class number_quote : public Quote
{
public:
    number_quote();
    number_quote(string &book, double p, size_t n, double disc):Quote(book,p),number1(n),discount1(disc){}
    double net_price(size_t cnt) const override
    {
        if(cnt >= number1)
        {
            return number1*(1-discount1)*price+(cnt-number1)*price;
        }
        else
        {
            return cnt*(1-discount1)*price;
        }
    }
    void debug()
    {
        cout << "This is number_quote Class" << endl;
        cout << "DISCOUNT: " << discount1 << endl;
        cout << "Max_qty: " << number1 << endl;
        cout << "Price: " << price << endl;
    }
private:
    double discount1;
    size_t number1;
};