/*循环输入数字 判断其区间*/
#include<stdio.h>
int main()
{
	puts("输入数字 判断其区间");
	puts("(输入-1结束)");
	
	while(1)
	{
		int x;
		scanf("%d",&x);
		
		if( x==-1 ) return 0;
		
		printf("%d00 ~ %d99 \n",x/100,x/100);
		
	}
}


