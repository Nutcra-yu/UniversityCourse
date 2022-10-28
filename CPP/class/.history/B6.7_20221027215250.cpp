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
        len = sizeof(a)/sizeof;
        p = (char *)malloc(len);

        int i;
        str.copy(p, 5, 0); //这里5代表复制几个字符，0代表复制的位置，
        *(p + 5) =‘\0’;    //注意手动加结束符！！！
    }

    void Show()
    {
        int i;
        for (i = 0; i < len; i++)
            cout << *(p + i);
    }

    bool IsSubstring(const char *str)
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