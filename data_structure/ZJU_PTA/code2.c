#include <stdio.h>
#include <stdlib.h>

//������к�
-5 2 4 -2 7 -10 9;

int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    //�Ӵ����
    for (i = 0; i < N; i++)
    {
        //�Ӵ��Ҷ�
        for (j = i; j < N; j++)
        {
            ThisSum = 0;
            //�ۼ�
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
    //�Ӵ����
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        //�Ӵ��Ҷ�
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
    //���
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

    //�洢���ݴ�С
    int n;
    scanf("%d", &n);

    //��������
    // int *a = (int *)malloc(sizeof(int) * n);
    int a[100];

    //��ǰThisSum ���MaxSum
    // start, end ��¼��ʼ������ֵ tempstart��¼�ٴ���ʼ
    int ThisSum = 0, MaxSum = 0, start = 0, end = 0, tempstart = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        //��������
        scanf("%d", &a[i]);

        //�Ƿ�ȫΪ����
        if (a[i] >= 0)
            AllNegative = 0;

        //����һ��sumС��0 ���¼�¼
        if (ThisSum < 0 || i == 0)
        {
            ThisSum = 0;
            tempstart = a[i];
        }

        // sum���ϵ�ǰ����
        ThisSum += a[i];

        //�������sum
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

