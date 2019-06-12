#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
using namespace std;

shared_ptr<vector<int>> vector_i()
{
    shared_ptr<vector<int>> _ptr(new vector<int>);

    return _ptr;
}

void vector_j(shared_ptr<vector<int>> _ptr)
{
    int int_val;
    while(cin >> int_val)
    {
        _ptr->push_back(int_val);
    }
}

void vector_k(shared_ptr<vector<int>> _ptr)
{
    for(size_t i = 0; i < (*_ptr).size(); ++i)
    {
        cout << (*_ptr)[i] << endl;
    }
}

int main(int argc, char **argv)
{
    shared_ptr<vector<int>> my_ptr = vector_i();
    vector_j(my_ptr);
    vector_k(my_ptr);

    return 0;
}