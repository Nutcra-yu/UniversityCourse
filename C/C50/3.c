#include<stdio.h>

int main()
{
	int line;
	int i;
	
	for( line=1 ; line<=3 ; line++ )
	{
		//blank
		for( i=1 ; i<line ; i++)
			printf(" ");
		
		//star
		for( i=1 ; i<=7-line*2 ; i++)
			printf("*");
			
		putchar('\n');
	}
	
	for( line=4 ; line<=5 ; line++)
	{
		//blank
		for( i=5 ; i>line ; i--)
			printf(" ");
			
		//satr
		for( i=1 ; i<=line*2-5 ; i++ )
			printf("*");
			
		putchar('\n');
	}
	
	return 0;
	
}
