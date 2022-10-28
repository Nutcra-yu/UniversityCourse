#include <iostream>
#include <stdlib.h>
using namespace std;

int BiggestSub1(int *a, int n);
int BiggestSub2(int *a, int n);
int BiggestSub3(int *a, int n);

int main()
{
    int AllNegative = 1;

    int n, *a;
    cin >> n;
    a = (int *)malloc(sizeof(int) * n);

    int i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            AllNegative = 0;
    }

    if (AllNegative)
        cout << "0";
    else
        cout << BiggestSub2(a, n);
}

int BiggestSub1(int *a, int n)
{

    int i, j, k;
    long sum, biggest;
    //�±���ʼλ��
    for (i = 0; i < n; i++)
    {
        //���г���
        for (j = 1; j < n - i; j++)
        {
            sum = 0;
            //�ۼ�
            for (k = 0; k < j; k++)
                sum += a[i + k];
            if (sum > biggest)
                biggest = sum;
        }
    }

    return biggest;
}

int BiggestSub2(int *a, int n)
{

    int i, j, k;
    long sum, biggest;
    //�±���ʼλ��
    for (i = 0; i < n; i++)
    {
        sum = 0;
        //���г���
        for (j = 1; j < n - i; j++)
        {
            sum += a[j];
            if (sum > biggest)
                biggest = sum;
        }
    }

    return biggest;
}

int BiggestSub2(int *a, int n)
{

    int i, j, k;
    long sum, biggest;
    //�±���ʼλ��
    for (i = 0; i < n; i++)
    {
        sum = 0;
        //���г���
        for (j = 1; j < n - i; j++)
        {
            sum += a[j];
            if (sum > biggest)
                biggest = sum;
        }
    }

    return biggest;
}

int Max3( int A, int B, int C )
{ /* ����3�������е����ֵ */
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer( int List[], int left, int right )
{ /* ���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* �ݹ����ֹ����������ֻ��1������ */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }

    /* ������"��"�Ĺ��� */
    center = ( left + right ) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */

    /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}