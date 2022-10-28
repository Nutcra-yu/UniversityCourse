#include <iostream>
using namespace std;

#define IDNUM 10

class employee
{
protected:
    char id[IDNUM];
    string name;
    float salary;

public:
    void ShowSalary()
    {
        cout << salary << endl;
    }
};

class manager : virtual public employee
{
    public:
    void ShowSalary()
};

class technician : public employee
{
};

class salesman : virtual public employee
{
};

class salesmanager : virtual public employee, public manager, public salesman
{
};

int main()
{
}