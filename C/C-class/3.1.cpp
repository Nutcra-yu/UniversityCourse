/*
ƽ��ֵ�������С�����
*/
#include<stdio.h>
#include<limits.h>

int main()
{
	//��Ŀ
	puts("����x��ʾ���뼸����\n"
		 "��������");      

	//���� ����                                                                                       
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
	//��� 
	printf("�������%d������\n" 
		   "��Ϊ%d\n"
		   "ƽ��ֵΪ%d\n"
		   "���ֵΪ%d\n"
		   "��СֵΪ%d\n",
		   x,sum,aver,max,min); 
}
