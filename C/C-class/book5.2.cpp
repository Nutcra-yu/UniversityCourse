/*在屏幕上显示一张时间表*/
#include<stdio.h>
int main()
{
	puts("*****Time*****");
	puts("1 morning ");
	puts("2 afternoon");
	puts("3 night");
	puts("Please enter your choice: ");
	
	int x;
	scanf("%d",&x);
	
	switch (x)
	{
		case 1: puts("Good morning");		break;
		case 2: puts("Good afternoon");		break;
		case 3: puts("Good night");			break;
		default:puts("Selection error!");	break;
	}
}
