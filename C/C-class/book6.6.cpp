/*����һ���Ƕ� ��sin*/
#include<stdio.h>
#include<math.h> 
#define PI 3.1415926535

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
	
	//t���ڼ�¼ÿһ��ʽ��ֵ 
	float t=x,sin=x;
	//i���ڸ��½׳� 
	int count=0;
	int i=1;
	while(fabs(t)>1e-5)
	{
		t=-t*x*x/((i+1)*(i+2));
		i += 2;
		sin += t ;
		count++;
	}
	printf("%d��\n",count);
	printf("sin%d = %lf",m,sin);
}
