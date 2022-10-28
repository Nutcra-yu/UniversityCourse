#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class String : public string
{
private:
    string s;

public:
    //�ĸ����캯��
    String() : string() {}
    String(const string &a) : string(a) { s = string(a); }
    String(int n, char a) : string(n, a) { s = string(n, a); }
    String(const string &a, int start, int length) : string(a, start, length) { s = string(a, start, length); }

    void Show(); //��ӡ

    bool IsSubstring(const char *sub);   //�ж��Ƿ��Ӵ�
    bool IsSubstring(const String &sub); //�ж��Ƿ��Ӵ�

    void ReplaceChar(char sub, char replace); //�滻�ַ�(�滻ǰ���ַ����滻����ַ�)
};

int main()
{
    /*���캯������*/
    String s1("nihao"), s2(4, 'f'), s3("0123456789", 4, 2), s4;
    s1.Show();
    s2.Show();
    s3.Show();
    s4.Show();

    /*�����Ӵ�*/
    String s1sub1("ih"), s1sub2("io");
    cout << s1.IsSubstring(s1sub1) << endl;
    cout << s1.IsSubstring("ih") << endl;

    /*�滻�Ӵ�*/

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