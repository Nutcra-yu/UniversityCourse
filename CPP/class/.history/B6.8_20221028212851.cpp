#include <iostream>
using namespace std;

class employee
{
protected:
    string id;
    string name;
    float salary;

public:
    employee(const string &id, const string &name, float salary)
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
    manager(const string &id, const string &name, float salary = 8000) : employee(id, name, salary) {}
};

class technician : public employee
{
private:
    float workhours;

public:
    technician(const string &id, const string &name, float salary = 0) : employee(id, name, salary) {}
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
    salesman(const string &id, const string &name, float salary = 0) : employee(id, name, salary) {}
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
    salesmanager(const string &id, const string &name, float salary = 5000) : employee(id, name, salary)
    {
        salary += allsales * 0.05;
        employee::ShowSalary();
    }
};

int main()
{
    manager manager_a("0001", "ljz");
    technician technician_b("0002","lyl");
    salesman salesman_c("0003")
}