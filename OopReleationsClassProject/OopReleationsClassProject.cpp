#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
class Passport
{

};

class Citizen
{
public:
    bool male;
    Passport passport;
};

class Flat
{
    vector<Citizen*> citizen;

    vector<Master*> master;
};
class Master
{
    vector<Flat*> flats;
};
*/

class Person
{
protected:
    string name;
    int age;

public:
    Person() : name{ "" }, age{ 0 }
    {}
    Person(string name, int age) :
        name{ name }, age{ age }
    {}

    string GetInfo()
    {
        return name + " " + to_string(age);
    }
};

class Manager : public Person
{
    float salary;
public:
    Manager() : Person(), salary{ 0.0f } {}
    Manager(string name, int age, float salary) 
        : Person(name, age), salary{ salary }
    {}

    string GetInfo()
    {
        return Person::GetInfo() + " " + to_string(salary);
    }
};

class Gaget
{
public:
    void Do()
    {
        cout << this << " Gaget work\n";
    }
};

class Scanner : public Gaget
{
public:
    Scanner()
    {
        cout << this << " Scanner construct\n";
    }
    ~Scanner()
    {
        cout << this << " Scanner destruct\n";
    }
    void Do()
    {
        cout << this << " Scanner work\n";
    }
};

class Printer : public Gaget
{
public:
    Printer()
    {
        cout << this << " Printer construct\n";
    }
    ~Printer()
    {
        cout << this << " Printer destruct\n";
    }
    void Do()
    {
        cout << this << " Printer work\n";
    }
};

class Mfu : public Scanner, public Printer
{
public:
    Mfu()
    {
        cout << this << " Mfu construct\n";
    }
    ~Mfu()
    {
        cout << this << " Mfu destruct\n";
    }

    void Do()
    {
        Scanner::Do();
        Printer::Do();
        cout << this << " Mfu work\n";
    }
    
};


int main()
{
    //Manager manager("Bob", 24, 65000);

    //cout << manager.GetInfo();

    Mfu mfu;
    mfu.Do();
}
