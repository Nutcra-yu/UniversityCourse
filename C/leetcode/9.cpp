/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/
#include<stdio.h>
int main()
{
	//输入 
	int x;
	printf("x = ");
	scanf("%d",&x);
	
	//保存x
	int m = x; 
	
	int a = 0;
	while( x != 0)
	{
		a = a*10 + x%10;
		x /= 10;
	}
	
	if( a == m ) printf("true" );
	if( a != m ) printf("false");
}










