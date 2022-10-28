#include<stdio.h>
int make(int n,int a)
{
	int x=a;
	
	int i;
	for(i=1;i<n;i++)
	{
		x = x*10+a;
	}
	return x;
}
int main()
{
	int a,n;
	printf("a:"); scanf("%d",&a); 
	printf("n:"); scanf("%d",&n); 
	
	int sum=0;
	
	int i;
	for(i=1;i<=n;i++)
	{
		sum += make(i,a);
	}
	printf("%d",sum);
	
}
