/*
Problem Description
Since all we know the ASCII code, your job is simple:
 input numbers and output corresponding messages.
 

Input
The first line contains one integer T (1<=T<=1000).
The input will contain T positive integers separated by whitespaces (spaces, newlines, TABs).
The integers will be no less than 32.
 

Output
Output the corresponding message in just one line.
Warning: no extra characters are allowed.
*/

#include<stdio.h>
int main()
{
	/*需要的变量*/
	int i;
	int n;					//存储数字的个数 
	int a[500]={0};			//存储数字 
	
	/*输入数据*/
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("\n");
	
	/*输出数据*/ 
	for(i=0;i<n;i++)
	{
		printf("%c",a[i]);
	} 
}
