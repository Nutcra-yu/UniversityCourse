#include <iostream>
using namespace std;


class employee
{
protected:
    string id;
    string name;
    float salary;

public:
    employee(string &id,string &name,float salary)
    {
        this->id = (char*) id.data();
        this->name = name; 
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