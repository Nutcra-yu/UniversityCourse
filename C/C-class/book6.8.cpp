#include<stdio.h>
int isFlower(int x)
{
	int t=x;
	if( x<100||999<x ) return 0;
	int sum=0;
	while(x!=0)
	{
		int a = x%10;
		sum += a*a*a;
		x = x/10;
	}
	if(sum == t) 	return 1;
	else 			return 0; 
}
int main()
{
	int i,j;
	for(i=100;i<1000;i++)
	{
		if( isFlower(i) == 1 ) 
		{
			printf("%-4d",i);
			j++;
			if(j==5) 
			{
				puts("");
				j=0;
			}
		}
	}
}
