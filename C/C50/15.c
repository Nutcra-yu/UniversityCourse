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
	/*��Ҫ�ı���*/
	int i;
	int n;					//�洢���ֵĸ��� 
	int a[500]={0};			//�洢���� 
	
	/*��������*/
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("\n");
	
	/*�������*/ 
	for(i=0;i<n;i++)
	{
		printf("%c",a[i]);
	} 
}
