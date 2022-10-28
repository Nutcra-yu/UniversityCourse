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