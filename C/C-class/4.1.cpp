/*输入5个数字 统计区间数字个数*/
#include <stdio.h>
int main()
{
	puts("输入5个数字（0~1000），将统计各个区间的数字个数");
	
	//存储数据 
	int a[5]={0};
	//统计个数 
	int count[10]={0};
	
	
	//输入数字 
	int i;
	while(i<5)
	{
		printf("第%d个数",i+1);
		scanf("%d",&a[i]);
		if( 0<=a[i] && a[i]<=1000 )	i++;
		else	printf("请输入0~1000的数字\n"); 
	}
	
	//统计数据
	for( i=0;i<5;i++)
	{
		switch( a[i]/100 )
		{
			case 0: count[0]++; break;//0-99
			case 1: count[1]++; break;//100-199
			case 2: count[2]++; break;//200-299
			case 3: count[3]++; break;//300-399
			case 4: count[4]++; break;//400-499
			case 5: count[5]++; break;//500-599
			case 6: count[6]++; break;//600-699
			case 7: count[7]++; break;//700-799
			case 8: count[8]++; break;//800-899
			case 9: count[9]++; break;//900-999
			case 10:count[9]++; break;//1000
		}
	}
	
	//输出结果
	for(i=0;i<9;i++)
	{
		printf("%d00 -  %d99 : %d\n",i,i,count[i]);
	}	 
		printf("900 - 1000 : %d",count[9]);
		
}

 

