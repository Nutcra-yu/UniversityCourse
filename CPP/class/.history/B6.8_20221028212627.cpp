#include <iostream>
using namespace std;

class employee
{
protected:
    string id;
    string name;
    float salary;

public:
    employee( string &id, string &name, float salary)
    {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    virtual void ShowSalary()
    {
        cout << id << ' ' << name << ':' << salary << endl;
    }
};

class manager : public employee
{
public:
    manager(string &id, string &name, float salary = 8000) : employee(id, name, salary) {}
};

class technician : public employee
{
private:
    float workhours;

public:
    technician(string &id, string &name, float salary = 0) : employee(id, name, salary) {}
    void ShowSalary()
    {
        salary = workhours * 100;
        employee::ShowSalary();
    }
};

class salesman : public employee
{
private:
    float sale;

public:
    salesman(string &id, string &name, float salary = 0) : employee(id, name, salary) {}
    void ShowSalary()
    {
        salary = sale * 0.4;
        employee::ShowSalary();
    }
};

class salesmanager : public employee
{
private:
    float allsales;

public:
    salesmanager(string &id, string &name, float salary = 5000) : employee(id, name, salary)
    {
        salary += allsales * 0.05;
        employee::ShowSalary();
    }
};

int main()
{
    manager manager_a("0001", "ljz",100);
}