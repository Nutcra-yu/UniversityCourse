#include<stdio.h>

/*
void put-chars( int n ,operator ch)
{
	int i,
	while( i-- > 0) 	putchar(ch);
}
*/

void put_chars( int n , int ch)
{
	while( n-- > 0) 	putchar(ch);
}

int main()
{
	int i;
	for(i=1;i<=5;i++)
	{
		put_chars(5-i,' ');	//put_chars(5-i,' ');
		put_chars( i ,'*'); //一定要有''，不能省去 
		putchar('\n');
	}
	
	return 0;
}
