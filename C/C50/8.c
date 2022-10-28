//青年歌手大奖赛中，评委会给参赛选手打分。
//选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分

#include<stdio.h>

//输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
//结果保留2位小数

//找最大值 
int max(int a[],int len)
{
	int i;
	int maxid=0;
	
	for(i=1;i<len;i++)
	{
		if(a[i]>a[maxid])
			maxid = i;
	}
	return maxid;
}
//找最小值
int min(int a[],int len)
{
	int i;
	int minid=0;
	
	for(i=0;i<len;i++)
	{
		if(a[i]<a[minid])
			minid = i;
	}
	return minid;
}


int main()
{
	printf("输入数据有多组，每组占一行\n"
	"每行的第一个数是n(2<n<=100)，表示评委的人数\n"
	"然后是n个评委的打分。结果保留2位小数\n\n");
	
	//定义一个100*100的数组
	int a[100][100]={0};
	
	/*需要的变量*/
	int i,j;
	//数组num用来存储每一行的元素个数 
	int num[100]={0};
	//cnt记录行数 
	int cnt=0;
	//sum记录总分
	int sum=0;
	//average记录平均分
	double average; 


	/*先存储数据*/
	
	//第i行 
	for(i=0;;i++)
	{
		//第i行有num[i]个数 
		scanf("%d",&num[i]);
		
		//为 0 结束输入 
		if(num[i] == 0) 	break;
		
		//不能小于三个评委
		while(num[i] < 3)
		{
			printf("不能小于三个评委\n"); 
			scanf("%d",&num[i]);
		}
		
		//记行 
		cnt++;
		
		//j个元素 
		for(j=0;j<num[i];j++)
		{
			scanf("%d",&a[i][j]);
		} 
	}
	
	printf("\n");
	/*计算平均分*/
	for(i=0;i<cnt;i++)
	{
		for(j=0;j<num[i];j++)
		{
			sum += a[i][j];
		}
		
		int maxid=max(a[i],num[i]);
		sum -= a[i][maxid];
		int minid=min(a[i],num[i]);
		sum -= a[i][minid];
			
		average = 1.0*sum/(num[i]-2);
		printf("第%d组评委给的成绩是：%.2f\n",i+1,average);
	}
	
	
	
	
	
}
