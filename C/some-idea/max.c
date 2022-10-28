#include<stdio.h>
int main()
{
	printf("int 最大应该数2147483647\n"
			"你可以写两个试一下\n");
	putchar("\n");
	
	int a1;
	printf("int max=");
	scanf("%d",&a1);
	printf("int max=%d\n",a1);
	int a2;
	printf("int max=");
	scanf("%d",&a2);
	printf("int max=%d\n",a2);
	
	printf("\n");
	printf("\n");
	
	
	
	
	printf("unsigned int 最大应该数4294967295\n"
			"你可以写两个试一下\n");
	putchar("\n");
	
	
	unsigned int b1;
	printf("unsigned int max=");
	scanf("%d",&b1);
	printf("unsigned int max=%d\n",b1);
	unsigned int b2;
	printf("unsigned int max=");
	scanf("%d",&b2);
	printf("unsigned int max=%d",b2);
	
}
