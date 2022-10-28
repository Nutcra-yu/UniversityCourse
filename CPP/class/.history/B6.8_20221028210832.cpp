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
    manager(string id, string &name) : employee(id, name, 8000) {}
};

class technician : public employee
{
private:
    float workhours;

public:
    technician(string id, string &name) : employee(id, name, 0) {}
    void ShowSalary()
    {
        salary = workhours * 100;
        cout <<cout << name << ':' << salary << endl;
    }
};

class salesman : public employee
{
    private:
    ÏúÊÛ¶î
};

class salesmanager : virtual public employee, public manager, public salesman
{
};

int main()
{
}