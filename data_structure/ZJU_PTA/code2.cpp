#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int AllNegative = 1;

    //�洢���ݴ�С
    int n;
    cin >> n;

    //��������
    int *a = (int *)malloc(sizeof(int) * n);

    //��ǰThisSum ���MaxSum
    // start, end ��¼��ʼ������ֵ tempstart��¼�ٴ���ʼ
    int ThisSum = 0, MaxSum = 0, start=0, end=0, tempstart=0;
    int i;

    for (i = 0; i < n; i++)
    {
        //��������
        cin >> a[i];
        //�Ƿ�ȫΪ����
        if (a[i] >= 0)
            AllNegative = 0;
        //����һ��sumС��0 ���¼�¼
        if (ThisSum < 0 || i==0)
        {
            ThisSum = 0;
            tempstart = a[i];
        }
        //sum���ϵ�ǰ����
        ThisSum += a[i];
        //�������sum
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