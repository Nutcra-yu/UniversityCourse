#include<stdio.h>
int a1,b1,a2,b2;
//���������������

//�Զ���һ��a��b�еľ���
int set(int a,int b)
{
	int m[a][b] ;
	puts("����������е�����"
		 "(һ�������ڵ���������Tab������������Enter)");
		 
	int i,j;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	
	return m;
}

//����������ˣ��Ҵ洢������������
int  multiply(int M1[a1][b1] ,int M2[a2][b2])
{
	int M[a1][b2];
	int i,j;
	
	for(i=0;i<a1;j++)
	{
		for(j=0;j<b2;j++)
		{
			
		}
	}
}

//ʧ����ѽ���ֵ�5555555 
 
int main()
{
	puts("�������������� M1��M2 ������������\n");
	int a1,b1,a2,b2;
	
	do{	
		printf("M1\n"); 
		printf("����a1��"); 	scanf("%d",&a1);
		printf("����b1��"); 	scanf("%d",&b1);
		putchar('\n');
		printf("M2\n"); 
		printf("����a2��"); 	scanf("%d",&a2);
		printf("����b2��"); 	scanf("%d",&b2);	 
		putchar('\n');
		if(b1 != a2) 	puts("���󣡣���\nb1��a2Ҫ���\n"); 
	}while( b1 != a2);
	
	printf("��һ������\n"); 
	int M1 = set(a1,b1);
	printf("�ڶ�������\n"); 
	int M2 = set(a2,b2);
	
	
	

}





