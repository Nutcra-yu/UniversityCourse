#include<stdio.h>
int sumup (int x)
{
	int i,sum=0;
	for(i=1;i<=x;i++)	sum += i;
	
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d", sumup(n) );
}
