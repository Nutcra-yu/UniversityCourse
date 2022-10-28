#include <iostream>
using namespace std;

class employee
{
protected:
    string id;
    string name;
    float salary;

public:
    employee(string id, string &name, float salary)
    {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    void ShowSalary()
    {
        cout << salary << endl;
    }
};

class manager : public employee
{
public:
    manager(string id, string &name) : employee(id, name, 8000) {}
};

class technician : public employee
{
    private:
    float workhour
};

class salesman : public employee
{
};

class salesmanager : virtual public employee, public manager, public salesman
{
};

int main()
{
}