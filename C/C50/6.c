#include<stdio.h>
//����ֵ����һ������
//����ֱ�����һ�����飬������ֵ����ȥ�������� 
//ע���ں���nҪ�ݼ� 
int max(int a[],int n)
{
	int maxid=0;
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i]    <0)
			a[i]     *= -1;
		if(a[maxid]<0)
			a[maxid] *= -1;
		if(a[i]>a[maxid])
			maxid=i;
	}
	return maxid;
} 
 
int main()
{
	/*���������ж��飬ÿ��ռһ�У�
	ÿ�еĵ�һ������Ϊn,������n��������
	n=0��ʾ�������ݵĽ�������������*/
	
	printf("����������ݣ�ÿ��ռһ��\n"
	"ÿ�еĵ�һ������Ϊn,������n������\n"
	"�����м��ÿո񣬻����ûس�\n"
	"n=0��ʾ�������ݵĽ���\n\n");
	
	
	//����һ��100*100������ 
	int a[100][100]={0};
	
	int i,j,n; 
	int cnt=0;
	int num[100];
	
	//��i��
	for(i=0;;i++)
	{	
		
		//��һ���ܹ��м��С�����cnt 
		cnt ++;
		
		//��i���м����������浽num�� 
		scanf("%d",&n);
		num[i]=n;
		
		//����������0����ֹͣ���� 
		if(n==0) 	break;
		
		//��j���� 
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	

	/*
	//���һ��
	for(i=0;i<cnt;i++)
	{
		for(j=0;j<num[i];j++)
		{
			printf("%d ",a[i][j]);
		}
		putchar('\n');
	}
	*/
	
	printf("\n");

	for(i=0;i<cnt-1;i++)
	{
		printf("��%d�У�",i+1);
		
		//����������i�������j��Ԫ�� 
		for(j=1;j<num[i];j++)
		{
			int  len     =  num[i] - j ;
			int  maxid   =  max( a[i] , len );
			int  temp    =  a[i][len];
			a[i][len]    =  a[i][maxid];
			a[i][maxid]  =  temp;
		}
		
		for(j=num[i]-1;j>=0;j--)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} 
	
	
} 
