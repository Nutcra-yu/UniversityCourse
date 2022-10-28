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
        len = sizeof(a)/sizeof(char);
        p = (char *)malloc(len*sizeof(char));

        int i;
        a.copy(p, len, 0); //����5�������Ƽ����ַ���0�������Ƶ�λ�ã�
        *(p + 5) =��\0��;    //ע���ֶ��ӽ�����������
    }

    void Show()
    {
        int i;
        for (i = 0; i < len; i++)
            cout << *(p + i);
    }

    bool IsSubstring(const char *str)
    {
        //Ĭ�ϲ�Ϊ�Ӵ�
        bool flag = false;

        //�ж�str����
        int LenStr = 0;
        while (*(str + LenStr) != '\0')
            LenStr++;

        //�ж��Ƿ�Ϊ�Ӵ�
        int i, j;
        for (i = 0; i < len && i < LenStr && LenStr <= len; i++)
        {
            //����ͬ���ַ���ʼ�ж�
            if (*(p + i) == *(str + i) && (len - i) >= LenStr)
            {
                for (j = 0; j < LenStr; j++)
                {
                    if (*(p + i) != *(str + i))
                        break;
                }
                //���Ӵ�
                if (j == LenStr)
                    flag = true;
            }
        }

        return flag;
    }
};

int main()
{
    String S1("hello");

    S1.Show();

    S1.IsSubstring("aaa");
    S1.IsSubstring("hell");
    S1.IsSubstring("hello");

    cout << endl;
    system("pause");
}