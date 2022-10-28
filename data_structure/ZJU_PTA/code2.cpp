#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int AllNegative = 1;

    //存储数据大小
    int n;
    cin >> n;

    //分配数组
    int *a = (int *)malloc(sizeof(int) * n);

    //当前ThisSum 最大MaxSum
    // start, end 记录起始结束数值 tempstart记录再次起始
    int ThisSum = 0, MaxSum = 0, start=0, end=0, tempstart=0;
    int i;

    for (i = 0; i < n; i++)
    {
        //输入数据
        cin >> a[i];
        //是否全为负数
        if (a[i] >= 0)
            AllNegative = 0;
        //若上一个sum小于0 重新记录
        if (ThisSum < 0 || i==0)
        {
            ThisSum = 0;
            tempstart = a[i];
        }
        //sum加上当前数据
        ThisSum += a[i];
        //更换最大sum
        if (ThisSum > MaxSum )
        {
            MaxSum = ThisSum;
            start = tempstart;
            end = a[i];
        }
    }

    if (AllNegative == 0)
        cout << MaxSum << ' ' << start << ' ' << end;
    else
        cout << 0 << ' ' << a[0] << ' ' << a[n - 1];

}