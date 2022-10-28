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
        cout << name << ':' << salary << endl;
    }
};

class manager : public employee
{
public:
    manager(string id, string &name, float salary = 8000) : employee(id, name, salary) {}
};

class technician : public employee
{
private:
    float workhours;

public:
    technician(string id, string &name, float salary = 0) : employee(id, name, salary) {}
    void ShowSalary()
    {
        salary = workhours * 100;
        cout << cout << name << ':' << salary << endl;
    }
};

class salesman : public employee
{
private:
    float sale;

public:
    salesman(string id, string &name, float salary = 0) : employee(id, name, salary)
    {
    }
};

class salesmanager : virtual public employee, public manager, public salesman
{
};

int main()
{
}