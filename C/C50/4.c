#include<stdio.h>

int main()
{
	int a,b;
	printf("����������������\n");
	printf("a="); 	scanf("%d",&a);
	printf("b="); 	scanf("%d",&b);	
	
	int big= a>b ? a : b;//the bigger one
	int sma= a>b ? b : a;//the smaller one
	
	/*
	big%sma = 0  ���Լ������sma
	
	big%sam = y1 �ǻ�Ҫ������
	sam%y1  = y2 ������������
	yi %y2  = 0  ���Լ������y2 
	*/

	int t;
	
	if(big%sma == 0)
		printf("���Լ���ǣ�%d",sma);
		
	do{

		t=sma;
		sma = big%sma;
		big = t;
		
		if(big%sma == 0)
			{
			printf("���Լ���ǣ�%d",sma);
			break;
			}
	}while(big%sma != 0);
	
	return 0;
}
