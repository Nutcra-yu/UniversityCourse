#include<stdio.h>

int main()
{
	puts("我发现了！！！\n"
		 "输入中间用tab可以不换行，用Enter就会\n"
		 "不行你试试，下面要输入三个数\n"); 
		  
	int i;
	int a[3];
	
	for(i=1;i<=3;i++)
	{
		scanf("%d",&a[i-1]);
	}
	
	putchar('\n');
	puts("come baby\n");
	
	for(i=1;i<=3;i++)
	{
		printf("a[%d]=%d ",i-1,a[i-1]);
	}
	
	return 0;
	
}
