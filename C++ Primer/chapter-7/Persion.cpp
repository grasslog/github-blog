#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persion
{
public:
    Persion(string Client_name, string Client_address);
    Persion();

    string name;
    string address;

    void Show_info()
    {
        cout << name <<"'s" << " address is " << address << endl;
    }

    string& const getname()
    {
        return name;
    }
    string& const getaddress()
    {
        return address;
    }
};

Persion::Persion(string Client_name, string Client_address): name(Client_name), address(Client_address) { }

int main(int argc, char **argv)
{
    Persion Client1("Mr.right", "your heart");
    Client1.Show_info();

    return 0;
}