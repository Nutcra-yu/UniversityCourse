/*
��6������ƽ�����ܺ͡�������Сֵ
*/
float sum(float a,float b,float c,float d,float e,float f);
float min(float a,float b,float c,float d,float e,float f);
float max(float a,float b,float c,float d,float e,float f);

#include<stdio.h>
int main()
{
	//���� 
	float a,b,c,d,e,f;
	float sum1,max1,min1;
	
	//���� 
	puts("������λ��");
	scanf("%f",&a);
	scanf("%f",&b);
	scanf("%f",&c);
	scanf("%f",&d);
	scanf("%f",&e);
	scanf("%f",&f);
	
	//����
	sum1 = sum(a,b,c,d,e,f);
	max1 = max(a,b,c,d,e,f);
	min1 = min(a,b,c,d,e,f); 
	
	//��� 
	printf("sum = %f \n",sum1);
	printf("min = %f \n",min1);
	printf("max = %f \n",max1);
	
	return 0;
}

float sum(float a,float b,float c,float d,float e,float f)
{
	float sum = 0;
	sum = a+b+c+d+e+f;
	return sum;
}



float max(float a,float b,float c,float d,float e,float f)
{
	float max = a;
	max>b ? max:max = b;
	max>c ? max:max = c;
	max>d ? max:max = d;
	max>e ? max:max = e;
	max>f ? max:max = f;
	return max;
}

float min(float a,float b,float c,float d,float e,float f)
{
	float min = a;
	min<b ? min:min = b;
	min<c ? min:min = c;
	min<d ? min:min = d;
	min<e ? min:min = e;
	min<f ? min:min = f;
	return min;
}
