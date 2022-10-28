/*定义一个数组
求：最大最小值；平均值；负数个数；正数的平均值；0~9出现的个数*/
#include<stdio.h>
#define X 5
int main()
{
	int num[X];
	int i; 
	for(i=0;i<X;i++)
	{
		printf("num[%d]:",i);
		scanf("%d",&num[i]);
	}
	
	int sum,sumZ;
	int min=num[0],max=num[0];
	int neg=0;
	int count[10]={0};
	for(i=0;i<X;i++)
	{
		sum += num[i];
		if(num[i]<min) min=num[i];
		if(num[i]>max) max=num[i];
		if(num[i]<0) neg++;
		if(num[i]>0) sumZ += num[i];
		int t=num[i];
		if(t<0) t=-t;
		while(t>0)
		{
			count[t%10]++;
			t = t/10;
		}
	}
	
	double aver=sum/X , averZ=sumZ/X;
	//求：最大最小值；平均值；负数个数；正数的平均值；0~9出现的个数*/
	printf("\n最大值:%d\n",max);
	printf("最小值:%d\n",min);
	printf("负数个数:%d\n",neg);
	printf("正数平均值:%lf\n",averZ);
	printf("平均值%lf\n",aver);
	for(i=0;i<10;i++)
	{
		printf("%d:%d次\n",i,count[i]);
	}
}
