#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include "Quote.h"
using namespace std;

int main(int argc, char **argv)
{
    vector<Quote> vec1;
    bulk_quote b1(string("C++ Primer I"),128,10,0.5);
    bulk_quote b2(string("C++ Primer II"),118,8,0.6);
    bulk_quote b3(string("C++ Primer III"),108,12,0.4);
    bulk_quote b4(string("C++ Primer IV"),138,4,0.3);
    vec1.push_back(b1);
    vec1.push_back(b2);
    vec1.push_back(b3);
    vec1.push_back(b4);
    double Sum_of_net_price1 = 0;
    for(int i = 0; i < vec1.size(); ++i)
    {
        Sum_of_net_price1 += vec1[i].net_price(20);
        cout << Sum_of_net_price1 << endl;
    }
    cout << "The total net price is: " << Sum_of_net_price1 << endl;

    vector<shared_ptr<Quote>> vec2;
    vec2.push_back(make_shared<bulk_quote>(b1));
    vec2.push_back(make_shared<bulk_quote>(b2));
    vec2.push_back(make_shared<bulk_quote>(b3));
    vec2.push_back(make_shared<bulk_quote>(b4));
    double Sum_of_net_price2 = 0;
    for(int i = 0; i < vec2.size(); ++i)
    {
        Sum_of_net_price2 += vec2[i]->net_price(20);
        cout << Sum_of_net_price2 << endl;
    }
    cout << "The total net price is: " << Sum_of_net_price2 << endl;

    return 0;
}