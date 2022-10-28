#include<stdio.h>

int main()
{
	int a,b;
	printf("请输入两个正整数\n");
	printf("a="); 	scanf("%d",&a);
	printf("b="); 	scanf("%d",&b);	
	
	int big= a>b ? a : b;//the bigger one
	int sma= a>b ? b : a;//the smaller one
	
	/*
	big%sma = 0  最大公约数就是sma
	
	big%sam = y1 那还要继续除
	sam%y1  = y2 ······
	yi %y2  = 0  最大公约数就是y2 
	*/

	int t;
	
	if(big%sma == 0)
		printf("最大公约数是：%d",sma);
		
	do{

		t=sma;
		sma = big%sma;
		big = t;
		
		if(big%sma == 0)
			{
			printf("最大公约数是：%d",sma);
			break;
			}
	}while(big%sma != 0);
	
	return 0;
}
