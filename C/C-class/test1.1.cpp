/*输入一个范围 求范围内的所有系数*/
#include<stdio.h>

int isPrime(int a)
{
	int i;
	if(a==1) return 0;
	for(i=2;i<=(a/2);i++)
	{
		if( a%2==0 ||  a%i==0 )  return 0;
	}
	return 1;
}

int main()
{
	int min,max;
	puts("输入两个数 用于表示范围");
	scanf("%d",&min);
	scanf("%d",&max);
	
	if(min>max)
	{
		int t=min;
		min = max;
		max = t;
	}
	
	int i,j=0;
	for(i=min;i<=max;i++)
	{
		
		if (isPrime(i) == 1)
		{
			printf("%-4d",i);
			j++;
			if (j == 5)
			{
				puts("\n");
				j=0;
			}
			
		}
	}
}
