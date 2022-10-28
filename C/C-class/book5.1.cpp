/*判断输入整数的正负性和奇偶性*/
#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	
	//正负性
	if(x<0) puts("负数");
	else if(x>0) puts("正数");
	else puts("0");
	
	//奇偶性
	switch(x%2)
	{
		case 1: puts("奇数"); break; 
		case 0: puts("偶数"); break; 
	}
	
 
}
