#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

class String
{
private:
    char *p;
    int len;

public:
    String(string a)
    {
        len = sizeof(a) / sizeof(char);
        p = (char *)malloc(len * sizeof(char));

        int i;
        a.copy(p, len + 1, 0); //����5�����Ƽ����ַ���0�����Ƶ�λ�ã�
        *(p + 5) = '\0';       //ע���ֶ��ӽ�����������
    }

    {
        if(IsSubstring(sub))
        {
            
        }else{
            return false;
        }
    }
};

int main()
{
    String S1("hello");

    S1.Show();

    cout << endl;
    system("pause");
}