#include<iostream>
using namespace std;

#define IDNUM 10

class employee
{
    protected:
        char[IDNUM] id;
};
class manager:public employee{};
class technician:public employee{};
class salesman:public employee{};
class salesmanager:public employee{};