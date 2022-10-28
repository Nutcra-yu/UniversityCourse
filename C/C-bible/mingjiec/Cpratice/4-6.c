#include<stdio.h>
int main()
{
	int n;
	int i=2;
	
	scanf("%d",&n);
	
	while( i<=n )
	{
		if( i%2==0 )	printf("%d ",i);
		i++;
	}
	
	printf("\n");
	
	printf("****");
	printf("\n");
	putchar("*");
	
	printf("\n");
	
	return 0;
	
}
