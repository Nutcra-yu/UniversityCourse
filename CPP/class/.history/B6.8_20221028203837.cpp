#include<iostream>
using namespace std;

#define IDNUM 10

class employee
{
    protected:
        char id[IDNUM];
};
class manager:public employee{};
class technician:public employee{};
class salesman:public employee{};
class salesmanager:public employee{};