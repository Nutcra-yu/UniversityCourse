/*输入数字 判断是奇数偶数 以及是否素数*/ 
#include<stdio.h> 
#include<stdlib.h> 

//将数字a放进数组b中 （c为数组长度） 
void Add(int *b,int a,int c)
{
	c = c + 1 ;
	b = (int*)malloc(c);
	b[c] = a;
}

//打印数组a中所有的数 （c为数组长度） 
void *Printf(int *b,int c)
{
	int a;
	for(a=0;a<c;a++)
	{
		printf("%d ",b[a]);
	}
}

int main()
{
	//题目
	puts("输入数字 判断是奇数偶数 以及是否素数");
	
	//输入 计算 
	puts("您想输入几个数");
	int x;
	scanf("%d",&x);
	
	int a;
	int *odd,*even,*prime;
	int  i=0,j=0,k=0; 
	
	int m;
	for(m=0;m<x;m++)
	{
		scanf("%d",a);
		//判断奇数偶数 
		switch( a%2 )
		{
		case 0: Add(*odd,a,i);
		case 1: Add(*even,a,j);
		}	
		
		//判断是否素数 	
	}	
	
	
}
