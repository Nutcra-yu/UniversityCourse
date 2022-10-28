//浙江桐乡乌镇共有n个人,请找出该镇上的前m个大富翁.

//每个用例首先包含2个整数n（0<n<=100000）和m(0<m<=10)，
//其中: n为镇上的人数，m为需要找出的大富翁数, 接下来一行输入镇上n个人的财富值.
//n和m同时为0时表示输入结束.

#include<stdio.h>

//在a[i][]中找到最大的前m[i]个数
//找到a[i][]中最大的数 
int max(int a[] ,int n)
{
	int i;
	int maxid=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>a[maxid])
			maxid = i;
	}
	return maxid;
} 

int main()
{
	printf("浙江桐乡乌镇共有n个人,请找出该镇上的前m个大富翁\n"
	"每个用例首先包含2个整数n（0<n<=100000）和m(0<m<=10)\n"
	"其中: n为镇上的人数，m为需要找出的大富翁数, 接下来一行输入镇上n个人的财富值\n"
	"n和m同时为0时表示输入结束.\n\n");
	
	/*需要的变量*/
	int i,j; 
	int cnt;				//记录测试次数 
	int a[50][50]={0};		//定义数组 a[][] 记录每一次测试的人数及其财富 
	int n[50]={0};			//每一次受测的人数 n 
	int m[50]={0};			//每一次测试想要找出的人数 m
	int temp;				//交换最大值 
	
	//标头printf
	
	/*记录数据*/
	//第 i 次 
	for(i=0;;i++)
	{
		//受测人数n[i] 
		scanf("%d",&n[i]);
		if(n[i] == 0) break;
		cnt ++;
		
		//需要人数 m[i] 
		scanf("%d",&m[i]);
		
		//记录每个人的财富
		for(j=0;j<n[i];j++)
		{
			scanf("%d",&a[i][j]);
		} 
	}
	

	printf("\n");
	
	
	/*计算并输出*/
	printf("大富翁排行榜\n");
	for(i=0;i<cnt;i++)
	{
		printf("第%d组：",i+1);
		
		//找到 n[i] 中最大的 m[i] 个
		for(j=0;j<m[i];j++)
		{
			//找到最大并输出
				//除去上一个最大的数
			//找下一个最大
			int maxid=max(a[i] , n[i]);
			printf("%d ",a[i][maxid]);
			a[i][maxid] = 0;
		} 
		
		printf("\n");
	} 
}
