/*
����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
*/
#include<stdio.h>
int main()
{
	//���� 
	int x;
	printf("x = ");
	scanf("%d",&x);
	
	//����x
	int m = x; 
	
	int a = 0;
	while( x != 0)
	{
		a = a*10 + x%10;
		x /= 10;
	}
	
	if( a == m ) printf("true" );
	if( a != m ) printf("false");
}










