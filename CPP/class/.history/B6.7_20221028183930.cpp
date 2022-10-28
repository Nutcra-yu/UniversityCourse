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

    void Show()
    {
        int i;
        for (i = 0; i < len; i++)
            cout << *(p + i);
    }

    //�ж��Ƿ��Ӵ�
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

//�滻�Ӵ�������Ϊ���滻ǰ���Ӵ����������Ӵ���
    void ReplaceSubstring(const char *sub,const char restr)
    {
        if(IsSubstring(sub))
        {
            
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