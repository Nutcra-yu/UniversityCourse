/*
给定一个整数数组 nums?和一个整数目标值 target，
请你在该数组中找出 和为目标值 target? 的那?两个?整数，
并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。
但是，数组中同一个元素在答案里不能重复出现。
*/

#include<stdio.h>
#define LENGTH  10000
int main()
{
	int nums[LENGTH] = {0};
	int target =0;
	
	int i;
	puts( "请输入数组" );
	for(i=0;i<LENGTH;i++)
	{
		scanf( "%d", &nums[i] );
		if(getchar() == '\n')	break;
	}
	 
	puts( "\n请输入目标值" ); 
	scanf( "%d"  , &target ); 
	
	int a,b ;
	for( a=0; a< LENGTH-1 ;a++ )
	{
		for(b=1;b<LENGTH;b++)
		{
			if( nums[a]+nums[b] == target)
			goto BREAK;
		}
	} 
	BREAK:b ;
	
	printf("%d,%d",a,b);
}

















