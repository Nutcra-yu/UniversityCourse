#include<stdio.h>
int factorial(int x)
{
	int fact=1;
	int i;
	for(i=1;i<=x;i++)
	{
		fact *= i;
	}
	return fact;
}
int main()
{
	int sum=0;
	
	int i;
	for(i=1;i<11;i++)
	{
		sum += factorial(i);
	}
	printf("%d",sum);
}
