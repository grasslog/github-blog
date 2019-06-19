#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Employee
{
public: 
    Employee();
    Employee(string& s);
    Employee(const Employee&) =delete; // none need construct copy function
    Employee operator= (const Employee&) =delete; // none need construct function
    int number() { return _number; }
private:
    string employee;
    int _number;
    static int o_number;
};

int Employee::o_number = 0;
Employee::Employee()
{
    _number = o_number++;
}
Employee::Employee(string &s)
{
    employee = s;
    _number = o_number++;
}

void show(Employee a)
{
    cout << a.number() << endl;
}

int main(int argc, char **argv)
{
    Employee a, b, c;
    show(a);
    show(b);
    show(c);

    return 0;
}