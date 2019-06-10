#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Sales_data
{
public:
    Sales_data() { };
    Sales_data(string s): _isbn(s) { }
    string isbn() const
    {
        return _isbn;
    }
    string _isbn;
};

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn().size() < s2.isbn().size();
}

int main(int argc, char **argv)
{
    Sales_data a("because");
    Sales_data b("I");
    Sales_data c("like");
    Sales_data d("your");
    Sales_data e("beautiful");
    Sales_data f("eyes");

    vector<Sales_data> vec1;
    vec1.resize(8);
    vec1[0] = a;
    vec1[1] = b;
    vec1[2] = c;
    vec1[3] = d;
    vec1[4] = e;
    vec1[5] = f;

    stable_sort(vec1.begin(), vec1.end(), compareIsbn);
    cout << "after sort the vector shows: ";
    for(int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i].isbn() << " ";
    }

    return 0;
}