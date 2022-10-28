/*
Problem Description
输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
 
Input
输入数据有多组，每组占一行，每行的开始是一个整数n，表示这个测试实例的数值的个数，跟着就是n个整数。
n=0表示输入的结束，不做处理。
 
Output
对于每组输入数据，输出交换后的数列，每组输出占一行。
*/
#include<stdio.h>

int min(int a[],int n)
{
	int minid=0;
	int i;
	for(i=1;i<n;i++)
	{
		if(a[i]<a[minid])
			minid = i;
	}
	return minid;
}
int main()
{
	printf("输入数据有多组，每组占一行，\n"
	"每行的开始是一个整数n，表示这个测试实例的数值的个数，跟着就是n个整数。\n"
	"n=0表示输入的结束，不做处理。\n\n");
	
	/*需要的变量*/
	int i,j;
	int cnt;							//cnt   记录测试次数 
	int n[50]     = {0};				//n[]   存储每一次测试的数字个数
	int a[50][50] = {0};				//a[][] 存储每一次测试的具体数字 
	 
	/*输入数据*/
	
	for(i=0;;i++)
	{
		//被测个数 
		scanf("%d",&n[i]);
		
		if( n[i] == 0) 	break; 			//结束输出 
		cnt ++;							//记录测试个数 
		
		//被测数字 
		for(j=0;j<n[i];j++)
		{
			scanf("%d",&a[i][j] );
		}
	}
	
	/*计算数据*/
	for(i=0;i<cnt;i++)
	{
		//找出a[i][]中的最小值的位置minid 
		int minid = min( a[i] , n[i] );
		
		//交换a[i][minid]与a[i][0]	
		int temp = a[i][minid];
		a[i][minid] = a[i][0];
		a[i][0] = temp;
		
		printf("\n");
		
		/*输出数据*/ 
		printf("第%d组：",i+1);
		for(j=0;j<n[i];j++)
		{
			printf("%d ",a[i][j]); 
		}
	}
	 
}
