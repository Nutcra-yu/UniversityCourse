#include <iostream>
#include <MyString.h>
#include <malloc.h>

using namespace std;

class MyMyString : public MyString
{
private:
    MyString s;

public:
    //�ĸ����캯��
    MyString() : MyString() {}
    MyString(const MyString &a) : MyString(a) { s = MyString(a); }
    MyString(int n, char a) : MyString(n, a) { s = MyString(n, a); }
    MyString(const MyString &a, int start, int length) : MyString(a, start, length) { s = MyString(a, start, length); }

    void Show(); //��ӡ

    bool IsSubMyString(const char *sub);   //�ж��Ƿ��Ӵ�
    bool IsSubMyString(const MyString &sub); //�ж��Ƿ��Ӵ�

    void ReplaceChar(char sub, char replace); //�滻�ַ�(�滻ǰ���ַ����滻����ַ�)
};

int main()
{
    /*���캯������*/
    MyString s1("nihao"), s2(4, 'f'), s3("0123456789", 4, 2), s4;
    s1.Show();
    s2.Show();
    s3.Show();
    s4.Show();

    /*�����Ӵ�*/
    MyString s1sub1("ih"), s1sub2("io");
    cout << s1.IsSubMyString(s1sub1) << endl;
    cout << s1.IsSubMyString("ih") << endl;

    /*�滻�Ӵ�*/

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