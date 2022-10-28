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
    String(const string &a):string(a){}
    String(int n,char a):string(n,a){}
    String(const string&a,int start,int end):string(a,start,)
};

int main()
{

}