/*��֤�ƶ���Χ�����ĸ�°ͺղ���*/
/*�������2��ż��������д����������֮��*/
#include<stdio.h> 

//�ж�a�ǲ������� �Ƿ���1 
int isPrime(int a);

int main()
{
	int min,max;
	puts("������֤��Χ��");
	scanf("%d",&min);
	scanf("%d",&max);
	if(min>max)
	{
		int t = min;
		min = max;
		max = t;
	}
	
	int i;
	for(i=min;i<=max;i++)
	{
		//ֻ�ж�ż�� 
		if(i%2==0)
		{
			int a;
			for(a=2;a<max;a++)
			{
				if(isPrime(a)==1)
				{
					if(isPrime(i-a)==1 )
					{
						printf("%d = %d + %d\n",i,a,i-a);
						break;
					}
				}
			}	
		}
	}
} 

int isPrime(int x)
{
	//���������� 
	int flag = 1;
	
	int i;
	for(i=2;i<=x/2;i++)
	{
		if(x%i == 0) flag = 0;
	}
	
	return flag;
}
