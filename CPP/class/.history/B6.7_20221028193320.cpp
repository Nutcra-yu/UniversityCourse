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

    void Show(); //打印

    bool IsSubstring(const char *sub);   //判断是否子串
    bool IsSubstring(const String &sub); //判断是否子串

    void ReplaceChar(char sub, char replace); //替换字符(替换前的字符，替换后的字符)
};

int main()
{
    /*构造函数测试*/
    String s1("nihao"), s2(4, 'f'), s3("0123456789", 4, 2), s4;
    s1.Show();
    s2.Show();
    s3.Show();
    s4.Show();

    /*查找子串*/
    String s1sub1("ih"), s1sub2("io");
    cout << s1.IsSubstring(s1sub1) << endl;
    cout << s1.IsSubstring("ih") << endl;

    /*替换子串*/

    system("pause");
}

void String::Show()
{
    cout << s << endl;
}
bool String::IsSubstring(const char *sub)
{
    if (s.find(sub) == string::npos)
        return false;
    else
        return true;
}
bool String::IsSubstring(const String &sub)
{
    if (s.find(sub) == string::npos)
        return false;
    else
        return true;
}
void String::ReplaceChar(char sub, char replace)
{
    int
}