/*验证制定范围的数的哥德巴赫猜想*/
/*任意大于2的偶数都可以写成两个质数之和*/
#include<stdio.h> 

//判断a是不是素数 是返回1 
int isPrime(int a);

int main()
{
	int min,max;
	puts("输入验证范围：");
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
		//只判断偶数 
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
	//假设是素数 
	int flag = 1;
	
	int i;
	for(i=2;i<=x/2;i++)
	{
		if(x%i == 0) flag = 0;
	}
	
	return flag;
}
