/*输入数字 判断是奇数偶数 以及是否素数*/ 
#include<stdio.h> 

int main()
{
	int x;
	scanf("%d",&x);
	
	//判断奇数偶数 
	switch( x%2 )
	{
		case 0:printf("%d 是偶数\n",x);break;
		case 1:printf("%d 是奇数\n",x);break; 
	}
	
	//判断是否素数
	//假设为是 
	int flag = 1;
	int i;
	for(i=2;i<x;i++)
	{
		if ( x%i == 0 ) flag = 0; 
	}
	if(flag == 0) printf("%d 不是素数",x);
	else	printf("%d 是素数",x);
	
	return 0; 
}
