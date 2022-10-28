#include<stdio.h>

int main()
{
	int prime;
	int n=2;
	for(; n<=100 ; n++)
	{
		int i;
		for( i=2 ; i<=n/2 ;i++)
		{
			prime=1;
			if( n%i == 0 ) 	
			{
			prime=0;
			break;
			}
		}
		if(prime == 1)
		{
			printf("%d ",n);
		}
		
	}
	
	return 0;
	//???这就是差距吗？？？
	//TMD太厉害了 
}

