#include<stdio.h>
int main()
{
	int i;
	int a[5]={17,23,36};
	int b[5];
	
	for(i=0;i<5;i++)
		b[i]=a[i];
		
	puts(" a  b ");
	puts("------");
	for(i=0;i<5;i++)
		printf("%2d%4d\n",a[i],b[i]);
	
	return 0;
}
