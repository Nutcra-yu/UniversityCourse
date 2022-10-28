/*
平均值、最大最小、求和
*/
#include<stdio.h>
#include<limits.h>

int main()
{
	//题目
	puts("输入x表示输入几个数\n"
		 "输入数据");      

	//输入 计算                                                                                       
	int x;
	scanf("%d",&x);
	
	int a;
	int sum=0,aver=0;
	int max=INT_MIN,min=INT_MAX;
	
	int i;
	for(i=0;i<x;i++)
	{
		scanf("%d",&a);
		if( a>max ) max = a;
		if( a<min ) min = a;
		sum += a; 
	}
	aver = sum/x;
	 
	 
	puts("") ;
	//输出 
	printf("您输入的%d个数的\n" 
		   "和为%d\n"
		   "平均值为%d\n"
		   "最大值为%d\n"
		   "最小值为%d\n",
		   x,sum,aver,max,min); 
}
