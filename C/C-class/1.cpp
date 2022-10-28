#include<stdio.h>
#include<conio.h>
int main()
{
	int x,y,z;
	char ch;
	float a,b,c;
	
	x=10;
	y=20;
	z=(x=20) + (y=30)*4;
	printf("x = %d \n",x);
	printf("z = %d \n",z);
	getch();
	
	ch = 'g';
	ch ++;
	printf("\n ch = %c  ch = %d \n",ch,ch);
	getch();
	
	a=1.0;
	b=2.0;
	c=a/b;
	printf("\n c= %20.16f",c);
	getch;
	
	
	
		
}
