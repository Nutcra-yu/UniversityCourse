//������ִ����У���ί�������ѡ�ִ�֡�
//ѡ�ֵ÷ֹ���Ϊȥ��һ����߷ֺ�һ����ͷ֣�Ȼ�����ƽ���÷�

#include<stdio.h>

//���������ж��飬ÿ��ռһ�У�ÿ�еĵ�һ������n(2<n<=100)����ʾ��ί��������Ȼ����n����ί�Ĵ�֡�
//�������2λС��

//�����ֵ 
int max(int a[],int len)
{
	int i;
	int maxid=0;
	
	for(i=1;i<len;i++)
	{
		if(a[i]>a[maxid])
			maxid = i;
	}
	return maxid;
}
//����Сֵ
int min(int a[],int len)
{
	int i;
	int minid=0;
	
	for(i=0;i<len;i++)
	{
		if(a[i]<a[minid])
			minid = i;
	}
	return minid;
}


int main()
{
	printf("���������ж��飬ÿ��ռһ��\n"
	"ÿ�еĵ�һ������n(2<n<=100)����ʾ��ί������\n"
	"Ȼ����n����ί�Ĵ�֡��������2λС��\n\n");
	
	//����һ��100*100������
	int a[100][100]={0};
	
	/*��Ҫ�ı���*/
	int i,j;
	//����num�����洢ÿһ�е�Ԫ�ظ��� 
	int num[100]={0};
	//cnt��¼���� 
	int cnt=0;
	//sum��¼�ܷ�
	int sum=0;
	//average��¼ƽ����
	double average; 


	/*�ȴ洢����*/
	
	//��i�� 
	for(i=0;;i++)
	{
		//��i����num[i]���� 
		scanf("%d",&num[i]);
		
		//Ϊ 0 �������� 
		if(num[i] == 0) 	break;
		
		//����С��������ί
		while(num[i] < 3)
		{
			printf("����С��������ί\n"); 
			scanf("%d",&num[i]);
		}
		
		//���� 
		cnt++;
		
		//j��Ԫ�� 
		for(j=0;j<num[i];j++)
		{
			scanf("%d",&a[i][j]);
		} 
	}
	
	printf("\n");
	/*����ƽ����*/
	for(i=0;i<cnt;i++)
	{
		for(j=0;j<num[i];j++)
		{
			sum += a[i][j];
		}
		
		int maxid=max(a[i],num[i]);
		sum -= a[i][maxid];
		int minid=min(a[i],num[i]);
		sum -= a[i][minid];
			
		average = 1.0*sum/(num[i]-2);
		printf("��%d����ί���ĳɼ��ǣ�%.2f\n",i+1,average);
	}
	
	
	
	
	
}
