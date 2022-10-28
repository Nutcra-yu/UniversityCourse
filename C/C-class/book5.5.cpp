/*输入一个年份和月份，打印该月份有多少天*/
#include<stdio.h>
int main()
{
	int year,month;
	printf("年份");  scanf("%d",&year);
	printf("月份");  scanf("%d",&month);
	
	switch(month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			puts("31days"); break;
		case 4: case 6: case 9: case 11:
			puts("30days"); break;
		case 2:
			if( (year%4==0 && year%100!=0) || year%400==0){
				puts("29days"); break;}
			else {
				puts("28days"); break;}
			
	}
}
