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
        a.copy(p, len + 1, 0); //这里5代表复制几个字符，0代表复制的位置，
        *(p + 5) = '\0';       //注意手动加结束符！！！
    }

    void Show()
    {
        int i;
        for (i = 0; i < len; i++)
            cout << *(p + i);
    }

    //判断是否子串
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

//替换子串，参数为（替换前的子串，替代后的子串）
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