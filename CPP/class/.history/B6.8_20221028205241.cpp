#include <iostream>
using namespace std;

#define IDNUM 4

class employee
{
protected:
    char ID[IDNUM];
    string name;
    float salary;

public:
    employee(string &id,string &name,float salary)
    {
        this.id = id.data(); 
    }

    void ShowSalary()
    {
        cout << salary << endl;
    }
};

class manager : virtual public employee
{
    public
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