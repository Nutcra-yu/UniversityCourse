#include<stdio.h>
int max(int a[],int len)
{
	int i;
	int maxid=0;
	for(i=1;i<len;i++)
	{
		if(a[i]>a[maxid])	maxid=i;
	}
	return maxid;
}


int main()
{
	//����һ������ 
	int i,a[3]; 
	puts("������������");
	for(i=0;i<3;i++)
	{
		printf("��%d������:",i+1);
		scanf("%d",&a[i]);
	}
	
	//�Ÿ���
	for(i=2;i>=0;i--)
	{
		//�ҵ����ֵ��λ��
		int maxid=max(a,i+1);
		//�������ֵ�����һ������λ��
		int t=a[i];
		a[i]=a[maxid];
		a[maxid]=t;
	}
	
	if(a[0]+a[1]<=a[2])
		printf("0(���ܹ���һ��������)");
	else if(a[0] == a[1] && a[1] == a[2])
		printf("1���������Σ�");
	else if(a[0]==a[1] || a[1]==a[2] || a[0]==a[2])
		printf("2(����������)");
	else
		printf("3(����������)"); 
	
	return 0;
	 
}
