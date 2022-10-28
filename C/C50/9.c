//给定一个日期，输出这个日期是该年的第几天。
//输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成
//输入0结束输入
 
#include<stdio.h>
int main()
{
	printf("给定一个日期，输出这个日期是该年的第几天\n"
	"输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成\n"	
	"输入0结束输入\n\n");
	
	
	/*需要的变量*/
	
	//i 存放日期 
		//year[i]存放年
		//month[i]存放月
		//day[i]存放日
	int i;
	//3个数组  存放年月日 
	int  year[100] = {0};
	int month[100] = {0};
	int   day[100] = {0};
	//monthdata 存放每个月的天数
	int monthdata[12]={31,28,31,30,31,30,31,31,30,31,30,31} ;
	//cnt 记录数据个数 
	int cnt = 0 ;
	//sum存放天数
	int sum = 0 ; 
	
	
	 
	//存储数据 
	for(i=0;;i++)
	{
		scanf("%d/%d/%d",&year[i],&month[i],&day[i]);
		if(year[i] == 0) 	break;
		cnt ++;
	}
	
	printf("\n");
	
	//计算天数
	for(i=0;i<cnt;i++)
	{
		int m;
		for(m=1;m<month[i];m++)
		{
			sum += monthdata[m-1];
		}
		
		sum += day[i];
		
		if(year[i]%4 == 0 && month[i]>2 )
			sum += 1;
		
		printf("%d/%d/%d是当年的第 %d 天\n",year[i],month[i],day[i],sum);
	} 
}





