/*输入一个整数 判断能否被3 5 7整除 并输出一下信息之一
能同时被3 5 7 整除
能被其中两个数整除
能被其中一个数整除
不能被任一个整除*/

#include<stdio.h>
#include<string.h>
int main()
{
	int x;
	scanf("%d",&x);
	
	//存储能被几个数整除 
	int a=0;
	//存储能够被哪几个数整除 
	char b[7]; 
	
	if(x%3 == 0)
	{
		a++;
		strcat(b,"3 ");
	}
	if(x%5 == 0)
	{
		a++;
		strcat(b,"5 ");
	}
	if(x%7 == 0)
	{
		a++;
		strcat(b,"7 ");
	}	
	
	printf("%d 能被 %d 个数整除 \n",x,a);
	if(a!=0)
	printf("%d 能被 %s整除",x,b);
}

