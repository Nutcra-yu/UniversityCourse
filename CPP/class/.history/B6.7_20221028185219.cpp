#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class String : public string
{
private:
    string s;

public:
    //四个构造函数
    String() : string() {}
    String(const string &a) : string(a) {}
    String(int n, char a) : string(n, a) {}
    String(const string &a, int start, int end) : string(a, start, end) {}

    //


};

int main()
{
    String s1("nihao");
}