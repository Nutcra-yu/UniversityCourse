#include <iostream>
using namespace std;

void diagscan(int row, int column);

int main()
{
    //没学指针 先用全局变量

    static int n; //存储array1的长度
    scanf("%d", &n);
    char array1[n + 1];
    scanf("%s", &array1);

    static int m; //存储array2的长度
    scanf("%d", &m);
    char array2[m + 1];
    scanf("%s", &array2);

    static int flag[n][m] = {0}; //没学指针 先用全局变量

    int row, column; // row行 column列
    for (row = 0; row < n; row++)
    {
        for (column = 0; column < m; column++)
        {
            if (array1[row] == array2[column])
                flag[row][column] = 1;
        }
    }

    static int maxlen = 0, i, j; //用于记录最大字串的长度和位置

    int k;
    row = 3, column = 0;
    for (k = m; k > -n, k--)
    {
        row = k + column;
        diagscan(row, column);
        if (k <= 0)
            column += 1;
    }

    system("pause");
}

void diagscan(int row, int column)
{
    int thislen = 0, tempi, tempj;
    while (row < n && column < m)
    {
        if (flag[row][column] == 1)
        {
            thislen++;
            if (thislen > maxlen)
            {
                i = tempi, j = tempj;
            }
        }
        else
        {
            thislen = 0;
        }

        row++;
        column++;
    }
}