/*

�����ʽ��
����� 1 �и��������� T (��10)���ǲ��������ĸ�����
������ T �����������ÿ��ռһ�У�˳����� A��B �� C���������Կո�ָ���

�����ʽ��
��ÿ�������������һ������� Case #X: true 
��� A+B>C��������� Case #X: false������ X �ǲ��������ı�ţ��� 1 ��ʼ����

*/
#include<stdio.h>
int main()
{
	printf("����3 ������ A��B �� C�����ж� A+B �Ƿ���� C��\n\n");
	
	/*��Ҫ�ı���*/
	int i; 
	int n;						//���Եĸ���
	int a[50],b[50],c[50];		//ÿ�β��������������  
	
	/*��������*/
	printf("���Դ�����");	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Case #%d:",i+1);
		scanf("%d %d %d",&a[i] , &b[i] , &c[i] );
	}
	
	printf("\n");
	
	/*���㲢���*/ 
	for(i=0;i<n;i++)
	{
		printf("Case #%d:",i+1);
		if( a[i] + b[i] > c[i] )
			printf("true\n");
		else
			printf("false\n");
		
	}
} 
