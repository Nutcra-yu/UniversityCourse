/*�������� �ж�������ż�� �Լ��Ƿ�����*/ 
#include<stdio.h> 
#include<stdlib.h> 

//������a�Ž�����b�� ��cΪ���鳤�ȣ� 
void Add(int *b,int a,int c)
{
	c = c + 1 ;
	b = (int*)malloc(c);
	b[c] = a;
}

//��ӡ����a�����е��� ��cΪ���鳤�ȣ� 
void *Printf(int *b,int c)
{
	int a;
	for(a=0;a<c;a++)
	{
		printf("%d ",b[a]);
	}
}

int main()
{
	//��Ŀ
	puts("�������� �ж�������ż�� �Լ��Ƿ�����");
	
	//���� ���� 
	puts("�������뼸����");
	int x;
	scanf("%d",&x);
	
	int a;
	int *odd,*even,*prime;
	int  i=0,j=0,k=0; 
	
	int m;
	for(m=0;m<x;m++)
	{
		scanf("%d",a);
		//�ж�����ż�� 
		switch( a%2 )
		{
		case 0: Add(*odd,a,i);
		case 1: Add(*even,a,j);
		}	
		
		//�ж��Ƿ����� 	
	}	
	
	
}
