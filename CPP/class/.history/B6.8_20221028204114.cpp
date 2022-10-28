#include <iostream>
using namespace std;

#define IDNUM 10

class employee
{
protected:
    char id[IDNUM];
    string name;
    float salary;
};

class manager : virtual public employee
{
};

class technician : public employee
{
};

class salesman : virtual public employee
{
};

class salesmanager : virtual public employee,public manager ,public 
{
};

int main()
{
}