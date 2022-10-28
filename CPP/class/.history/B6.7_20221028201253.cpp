#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class MyString : public string
{
private:
    string s;

public:
    //四个构造函数
    MyString() : string() {}
    MyString(const string &a) : string(a) { s = string(a); }
    MyString(int n, char a) : string(n, a) { s = string(n, a); }
    MyString(const string &a, int start, int length) : string(a, start, length) { s = string(a, start, length); }

    int size() { return s.size(); }

    void Show(); //打印

    bool IsSubstring(const char *sub);     //判断是否子串
    bool IsSubstring(const MyString &sub); //判断是否子串

    void ReplaceChar(char sub, char replace);       //替换所有特定字符(替换前的字符，替换后的字符)
    void ReplaceString(string sub, string replace); //替换首个特定子串(替换前的子串，替换后的子串)

    void Erase(char sub);
    void Erase(char sub);
};

int main()
{
    /*构造函数测试*/
    MyString s1("nihao"), s2(4, 'f'), s3("0123456789", 1, 9), s4;
    // s1.Show();
    // s2.Show();
    // s3.Show();
    // s4.Show();

    /*查找子串*/
    // MyString s1sub1("ih"), s1sub2("io");
    // cout << s1.IsSubstring(s1sub1) << endl;
    // cout << s1.IsSubstring("ih") << endl;

    /*替换*/
    // //字符
    // s2.Show();
    // s2.ReplaceChar('f', 'a');
    // s2.Show();
    // //子串
    // s3.Show();
    // s3.ReplaceString("456", "FourFiveSix");
    // s3.Show();

    system("pause");
}

//打印
void MyString::Show()
{
    cout << s << endl;
}
//判断是否子串
bool MyString::IsSubstring(const char *sub)
{
    if (s.find(sub) == string::npos)
        return false;
    else
        return true;
}
//判断是否子串
bool MyString::IsSubstring(const MyString &sub)
{
    if (s.find(sub) == string::npos)
        return false;
    else
        return true;
}
//替换字符(替换前的字符，替换后的字符)
void MyString::ReplaceChar(char sub, char replace)
{
    int pos;
    while ((pos = s.find(sub)) != string::npos)
        s.replace(pos, 1, 1, replace);
}
//替换子串(替换前的子串，替换后的子串)
void MyString::ReplaceString(string sub, string replace)
{
    if (IsSubstring(sub) == false)
        return;
    else
        s.replace(s.find(sub), sub.size(), replace);
}