/*

输入格式：
输入第 1 行给出正整数 T (≤10)，是测试用例的个数。
随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔。

输出格式：
对每组测试用例，在一行中输出 Case #X: true 
如果 A+B>C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）。

*/
#include<stdio.h>
int main()
{
	printf("给定3 个整数 A、B 和 C，请判断 A+B 是否大于 C。\n\n");
	
	/*需要的变量*/
	int i; 
	int n;						//测试的个数
	int a[50],b[50],c[50];		//每次测试输入的三个数  
	
	/*输入数据*/
	printf("测试次数：");	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Case #%d:",i+1);
		scanf("%d %d %d",&a[i] , &b[i] , &c[i] );
	}
	
	printf("\n");
	
	/*计算并输出*/ 
	for(i=0;i<n;i++)
	{
		printf("Case #%d:",i+1);
		if( a[i] + b[i] > c[i] )
			printf("true\n");
		else
			printf("false\n");
		
	}
} 
