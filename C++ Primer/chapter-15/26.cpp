#include <string>
#include <iostream>
using namespace std;

class Quote
{
    friend double print_total(ostream &,const Quote&,size_t);
public:
    Quote();
    Quote(const string &book,double sales_price):BookNo(book),price(sales_price){}
    Quote(const Quote& quote1):BookNo(quote1.BookNo),price(quote1.price)
    {
        cout << "Copy construct function." << endl;
    }
    Quote& operator=(const Quote& quote2)
    {
        if(*this != quote2)
        {
            BookNo = quote2.BookNo;
            price = quote2.price;
        }
        cout << "Copy operator = " << endl;
        return *this;
    }
    Quote(const Quote&& quote3):BookNo(move(quote3.BookNo)),price(move(quote3.price))
    {
        cout << "Move construct function." << endl;
    }
    Quote& operator=(const Quote&& quote4) noexcept
    {
        if(*this != quote4)
        {
            BookNo = move(quote4.BookNo);
            price = move(quote4.price);
        }
        cout << "Copy operator = " << endl;
        return *this;
    }
    string isbn() const{ return BookNo; }
    virtual void debug()
    {
        cout << "This is Quote Class." << endl;
        cout << "ISBN: " << BookNo << endl;
        cout << "Price: " << price << endl;
    }
private:
    string BookNo;
protected:
    double price;
};