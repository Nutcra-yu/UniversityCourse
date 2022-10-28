#include<stdio.h>
int main()
{
	int a,b;
	
	printf("  ");
	for(a=1;a<=9;a++)
		printf("%d  ",a);
		
	putchar('\n');
		
	for(a=1;a<=30;a++)
		printf("-");

	putchar('\n');
	
	for(a=1;a<=9;a++)
	{
		printf("%d|",a);
		for(b=1;b<=9;b++)
		{
			if(a*b<10)
			printf("%d  ",a*b);
			else
			printf("%d ",a*b);
		}
		putchar('\n');
	}	
		return 0;
}
