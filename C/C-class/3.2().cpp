/*�������� �ж�������ż�� �Լ��Ƿ�����*/ 
#include<stdio.h> 

int main()
{
	int x;
	scanf("%d",&x);
	
	//�ж�����ż�� 
	switch( x%2 )
	{
		case 0:printf("%d ��ż��\n",x);break;
		case 1:printf("%d ������\n",x);break; 
	}
	
	//�ж��Ƿ�����
	//����Ϊ�� 
	int flag = 1;
	int i;
	for(i=2;i<x;i++)
	{
		if ( x%i == 0 ) flag = 0; 
	}
	if(flag == 0) printf("%d ��������",x);
	else	printf("%d ������",x);
	
	return 0; 
}
