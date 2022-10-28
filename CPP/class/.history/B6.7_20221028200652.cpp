#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class MyString : public string
{
private:
    string s;

public:
    //�ĸ����캯��
    MyString() : string() {}
    MyString(const string &a) : string(a) { s = string(a); }
    MyString(int n, char a) : string(n, a) { s = string(n, a); }
    MyString(const string &a, int start, int length) : string(a, start, length) { s = string(a, start, length); }

    int size() { return s.size(); }

    void Show(); //��ӡ

    bool IsSubstring(const char *sub);     //�ж��Ƿ��Ӵ�
    bool IsSubstring(const MyString &sub); //�ж��Ƿ��Ӵ�

    void ReplaceChar(char sub, char replace);           //�滻�ַ�(�滻ǰ���ַ����滻����ַ�)
    void ReplaceString(MyString sub, MyString replace); //�滻�Ӵ�(�滻ǰ���Ӵ����滻����Ӵ�)
};

int main()
{
    /*���캯������*/
    MyString s1("nihao"), s2(4, 'f'), s3("0123456789", 4, 2), s4;
    // s1.Show();
    // s2.Show();
    // s3.Show();
    // s4.Show();

    /*�����Ӵ�*/
    // MyString s1sub1("ih"), s1sub2("io");
    // cout << s1.IsSubstring(s1sub1) << endl;
    // cout << s1.IsSubstring("ih") << endl;

    /*�滻�Ӵ�*/
    s2.Show();
    s2.ReplaceChar('f', 'a');
    s2.Show();

    system("pause");
}

//��ӡ
void MyString::Show()
{
    cout << s << endl;
}
//�ж��Ƿ��Ӵ�
bool MyString::IsSubstring(const char *sub)
{
    if (s.find(sub) == string::npos)
        return false;
    else
        return true;
}
//�ж��Ƿ��Ӵ�
bool MyString::IsSubstring(const MyString &sub)
{
    if (s.find(sub) == string::npos)
        return false;
    else
        return true;
}
//�滻�ַ�(�滻ǰ���ַ����滻����ַ�)
void MyString::ReplaceChar(char sub, char replace)
{
    int pos;
    while ((pos = s.find(sub)) != string::npos)
        s.replace(pos, 1, 1, replace);
}
//�滻�Ӵ�(�滻ǰ���Ӵ����滻����Ӵ�)
void MyString::ReplaceString(MyString sub, MyString replace)
{
    if(IsSubstring(sub) == )
}