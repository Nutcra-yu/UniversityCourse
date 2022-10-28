#include <stdio.h>
#include <stdlib.h>

//最大子列和
-5 2 4 -2 7 -10 9;

int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    //子串左端
    for (i = 0; i < N; i++)
    {
        //子串右端
        for (j = i; j < N; j++)
        {
            ThisSum = 0;
            //累加
            for (k = i; k <= j; k++)
                ThisSum += A[k];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

int MaxSubseqSum2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;
    //子串左端
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        //子串右端
        for (j = i; j < N; j++)
        {
            ThisSum += A[k];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

int MaxSubseqSum3(int A[], int N)
{
    int ThisSum = 0, MaxSum = 0;
    int i;
    //左端
    for (i = 0; i < N; i++)
    {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main()  
{
    int AllNegative = 1;

    //存储数据大小
    int n;
    scanf("%d", &n);

    //分配数组
    // int *a = (int *)malloc(sizeof(int) * n);
    int a[100];

    //当前ThisSum 最大MaxSum
    // start, end 记录起始结束数值 tempstart记录再次起始
    int ThisSum = 0, MaxSum = 0, start = 0, end = 0, tempstart = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        //输入数据
        scanf("%d", &a[i]);

        //是否全为负数
        if (a[i] >= 0)
            AllNegative = 0;

        //若上一个sum小于0 重新记录
        if (ThisSum < 0 || i == 0)
        {
            ThisSum = 0;
            tempstart = a[i];
        }

        // sum加上当前数据
        ThisSum += a[i];

        //更换最大sum
        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            start = tempstart;
            end = a[i];
        }
    }

    if (AllNegative == 0)
        printf("%d %d %d", MaxSum, start, end);
    else
        printf("0 %d %d", a[0], a[n - 1]);

    system("pause");
}

