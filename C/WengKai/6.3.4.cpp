#include<stdio.h>

void a();

void b(int b);

int main( )
{
	a();
	
	b(1);
	
}


void a()
{
	printf("void a()\n");
}

void b(int b)
{
	printf("\nvoid b(void)\n");
	printf("%d",b);
}
 
