/*����һ���Ƕ� ��sin*/
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
	puts("����һ���Ƕ�");
	scanf("%d",&m);
	if(m<0 || m>360)
	{
		puts("0~360:");
		scanf("%d",&m); 
	}
	//ת���ɻ���
	float x = (1.0*m/360)*2*PI;
	
	double sin;
	int n;
	for(n=1;n<=7;n++)
	{
		//a:ÿ��ʽ������ 
		int a=1;
		if(n%2==0)  a=-1;
		//b:2n-1
		int b = 2*n-1;
		//c:x��b�η� 
		double c=1,i;
		for(i=1;i<=b;i++) c *= x;
		//d:b�Ľ׳�
		int d= factorial(b); 
		
		sin += a*c/d;
	}
	printf("sin%d = %lf",m,sin);
		
}
