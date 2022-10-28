#include <iostream>
#include <MyString.h>
#include <malloc.h>

using namespace std;

class MyMyString : public MyString
{
private:
    MyString s;

public:
    //四个构造函数
    MyString() : MyString() {}
    MyString(const MyString &a) : MyString(a) { s = MyString(a); }
    MyString(int n, char a) : MyString(n, a) { s = MyString(n, a); }
    MyString(const MyString &a, int start, int length) : MyString(a, start, length) { s = MyString(a, start, length); }

    void Show(); //打印

    bool IsSubMyString(const char *sub);   //判断是否子串
    bool IsSubMyString(const MyString &sub); //判断是否子串

    void ReplaceChar(char sub, char replace); //替换字符(替换前的字符，替换后的字符)
};

int main()
{
    /*构造函数测试*/
    MyString s1("nihao"), s2(4, 'f'), s3("0123456789", 4, 2), s4;
    s1.Show();
    s2.Show();
    s3.Show();
    s4.Show();

    /*查找子串*/
    MyString s1sub1("ih"), s1sub2("io");
    cout << s1.IsSubMyString(s1sub1) << endl;
    cout << s1.IsSubMyString("ih") << endl;

    /*替换子串*/

    system("pause");
}

void MyString::Show()
{
    cout << s << endl;
}
bool MyString::IsSubMyString(const char *sub)
{
    if (s.find(sub) == MyString::npos)
        return false;
    else
        return true;
}
bool MyString::IsSubMyString(const MyString &sub)
{
    if (s.find(sub) == MyString::npos)
        return false;
    else
        return true;
}
void MyString::ReplaceChar(char sub, MyString replace)
{
    int pos = s.find(sub);
    while(pos != MyString::npos)
    {
        s.replace(pos,1,replace);
    }
    
}