/*输入一个角度 求sin*/
#include<stdio.h>
#define PI 3.1415926535

int factorial(int t)
{
	int fact=1;
	int i;
	for(i=2;i<=t;i++)
	{
		fact = fact*i;
	}
	return fact;
}
int main()
{
	int m;
	puts("输入一个角度");
	scanf("%d",&m);
	if(m<0 || m>360)
	{
		puts("0~360:");
		scanf("%d",&m); 
	}
	//转化成弧度
	float x = (1.0*m/360)*2*PI;
	
	double sin;
	int n;
	for(n=1;n<=7;n++)
	{
		//a:每项式的正负 
		int a=1;
		if(n%2==0)  a=-1;
		//b:2n-1
		int b = 2*n-1;
		//c:x的b次方 
		double c=1,i;
		for(i=1;i<=b;i++) c *= x;
		//d:b的阶乘
		int d= factorial(b); 
		
		sin += a*c/d;
	}
	printf("sin%d = %lf",m,sin);
		
}
