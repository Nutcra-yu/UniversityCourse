#include <iostream>
using namespace std;


class employee
{
protected:
    string ID;
    string name;
    float salary;

public:
    employee(string &id,string &name,float salary)
    {
        ID = (char*) id.data(); 
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