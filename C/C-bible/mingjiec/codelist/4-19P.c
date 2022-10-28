#include<stdio.h>
int main()
{
	int n,m;
	int i,j=1;
	
	printf("¶Ì±ßÊÇ");
	scanf("%d",&i);
	
	for(n=1;n<=i;n++)
	{
		for( m=1;m<=i-j;m++ )
		putchar(' ');
		for( j=1;j<=n;j++ )
			printf("0");
			
		putchar('\n');
	}
	
	return 0;
} 
