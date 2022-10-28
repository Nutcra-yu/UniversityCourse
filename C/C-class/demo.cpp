#include<stdio.h>
#include<malloc.h>

int main()
{
	int x;
	free(&x);
	
	x=1;
	printf("%d",x);
}
