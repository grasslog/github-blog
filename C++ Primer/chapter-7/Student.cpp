#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
public:
    Student(string name, int age, int score);

    string m_name;
    int m_age;
    int m_score;

    void showname()
    {
        cout << m_name << "the age is " << m_age << m_score << endl;
    }
private:
protected:
};
Student::Student(string name, int age, int score):m_name(name), m_age(age), m_score(score){ }

struct Students
{
    Students(string name, int age, int score);

    string m_name;
    int m_age;
    int m_score;

    void shownames()
    {
        cout<< m_name << " the age is " << m_age << " the score is " << m_score << endl;
    }
};
Students::Students(string name, int age, int score): m_name(name), m_age(age), m_score(score) { }

int main(int argc, char** argv)
{
    Student stu1("xiaoming", 18, 3);
    Students stu2("xiaoming", 18, 3);
    stu1.showname();
    stu2.shownames();

    return 0;
}