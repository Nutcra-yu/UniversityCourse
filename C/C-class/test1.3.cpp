/*����һ������
�������Сֵ��ƽ��ֵ������������������ƽ��ֵ��0~9���ֵĸ���*/
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
	//�������Сֵ��ƽ��ֵ������������������ƽ��ֵ��0~9���ֵĸ���*/
	printf("\n���ֵ:%d\n",max);
	printf("��Сֵ:%d\n",min);
	printf("��������:%d\n",neg);
	printf("����ƽ��ֵ:%lf\n",averZ);
	printf("ƽ��ֵ%lf\n",aver);
	for(i=0;i<10;i++)
	{
		printf("%d:%d��\n",i,count[i]);
	}
}
