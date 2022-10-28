#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class String: public string
{
private:
    string s;

public:
    String(): string(){}
    String(string a):string(a){};
    String(int n,char a):string(n)
};

int main()
{

}