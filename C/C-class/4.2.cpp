/*ѭ���������� �ж�������*/
#include<stdio.h>
int main()
{
	puts("�������� �ж�������");
	puts("(����-1����)");
	
	while(1)
	{
		int x;
		scanf("%d",&x);
		
		if( x==-1 ) return 0;
		
		printf("%d00 ~ %d99 \n",x/100,x/100);
		
	}
}


