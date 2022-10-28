#include<stdio.h>
int main()
{
	int n;
	int i;
	
	scanf("%d",&n);
	
	for( i=1;i<=n;i++)
	{
		if(i%5==0)
		{
			putchar('*');
			putchar('\n');
		}
		else
		putchar('*');
	}
	
	return 0;
}
