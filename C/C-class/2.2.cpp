/*	输入一个数，求他的每个数位的平方和	*/

#include<stdio.h>

//求整数部分 
int SumInt(int a);

int main()
{
	puts("二进制不能精确表示小数，请输入整数");
	int a;
	int sum=0;
	
	//输入数据
	scanf("%d",&a);
	
	//计算 
	sum = SumInt(a);
	
	//输出数据 
	printf("%d",sum);
}


int SumInt(int a)
{
	int sum = 0;
	
	while(a != 0)
	{
		int i = a % 10;
		sum += i*i;
		a = a / 10; 
	}
	
	return sum;
}

