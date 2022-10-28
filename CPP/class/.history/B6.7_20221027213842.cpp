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
    String(char a[])
    {
        len = strlen(a);
        p = (char *)malloc(sizeof(char) * len);

        int i;
        for (i = 0; i < len; i++)
            *(p + i) = *(a + i);
    }

    void Show()
    {
        int i;
        for (i = 0; i < len; i++)
            cout << *(p + i);
    }

    bool IsSubstring(char *str)
    {
        //默认不为子串
        bool flag = false;

        //判断str长度
        int LenStr = 0;
        while (*(str + LenStr) != '\0')
            LenStr++;

        //判断是否为子串
        int i, j;
        for (i = 0; i < len && i < LenStr && LenStr <= len; i++)
        {
            //从相同首字符开始判断
            if (*(p + i) == *(str + i) && (len - i) >= LenStr)
            {
                for (j = 0; j < LenStr; j++)
                {
                    if (*(p + i) != *(str + i))
                        break;
                }
                //是子串
                if (j == LenStr)
                    flag = true;
            }
        }

        if (flag)
        {
            for (i = 0; i < LenStr; i++)
                cout << *(str + i);
                cout<<"是";
                this->Show();
                cout<<"的子串"<<endl;
        }else{
            for (i = 0; i < LenStr; i++)
                cout << *(str + i);
                cout<<"不是";
                this->Show();
                cout<<"的子串"<<endl;
        }
    }
};

int main()
{
    String S1("hello");
    
    S1.IsSubstring("aaa");
    S1.IsSubstring("hell");
    S1.IsSubstring("hello");

    cout << endl;
    system("pause");
}