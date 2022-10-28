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
    String(const string &a) : string(a) { s = string(a); }
    String(int n, char a) : string(n, a) { s = string(n, a); }
    String(const string &a, int start, int length) : string(a, start, length) { s = string(a, start, length); }

    //打印
    void Show();
};

int main()
{
    String s1("nihao"), s2(4, 'f'), s3("0123456789", 4, 2),s4();
    s1.Show();
    s2.Show();
    s3.Show();

    system("pause");
}

void String::Show()
{
    cout << s << endl;
}