/*
����һ���������� nums?��һ������Ŀ��ֵ target��
�����ڸ��������ҳ� ��ΪĿ��ֵ target? ����?����?������
���������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡�
���ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
*/

#include<stdio.h>
#define LENGTH  10000
int main()
{
	int nums[LENGTH] = {0};
	int target =0;
	
	int i;
	puts( "����������" );
	for(i=0;i<LENGTH;i++)
	{
		scanf( "%d", &nums[i] );
		if(getchar() == '\n')	break;
	}
	 
	puts( "\n������Ŀ��ֵ" ); 
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

















