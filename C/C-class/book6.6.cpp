/*输入一个角度 求sin*/
#include<stdio.h>
#include<math.h> 
#define PI 3.1415926535

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
	
	//t用于记录每一项式的值 
	float t=x,sin=x;
	//i用于更新阶乘 
	int count=0;
	int i=1;
	while(fabs(t)>1e-5)
	{
		t=-t*x*x/((i+1)*(i+2));
		i += 2;
		sin += t ;
		count++;
	}
	printf("%d项\n",count);
	printf("sin%d = %lf",m,sin);
}
