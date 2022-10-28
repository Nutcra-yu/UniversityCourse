#include<stdio.h>
//绝对值排序一个数组
//不能直接输出一个数组，输出最大值，再去排序数组 
//注意在后面n要递减 
int max(int a[],int n)
{
	int maxid=0;
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i]    <0)
			a[i]     *= -1;
		if(a[maxid]<0)
			a[maxid] *= -1;
		if(a[i]>a[maxid])
			maxid=i;
	}
	return maxid;
} 
 
int main()
{
	/*输入数据有多组，每组占一行，
	每行的第一个数字为n,接着是n个整数，
	n=0表示输入数据的结束，不做处理*/
	
	printf("输入多组数据，每组占一行\n"
	"每行的第一个数字为n,接着是n个整数\n"
	"数字中间用空格，换行用回车\n"
	"n=0表示输入数据的结束\n\n");
	
	
	//定义一个100*100的数组 
	int a[100][100]={0};
	
	int i,j,n; 
	int cnt=0;
	int num[100];
	
	//第i行
	for(i=0;;i++)
	{	
		
		//数一下总共有几行———cnt 
		cnt ++;
		
		//第i行有几个数，并存到num中 
		scanf("%d",&n);
		num[i]=n;
		
		//如果输入的是0，则停止输入 
		if(n==0) 	break;
		
		//第j个数 
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	

	/*
	//输出一下
	for(i=0;i<cnt;i++)
	{
		for(j=0;j<num[i];j++)
		{
			printf("%d ",a[i][j]);
		}
		putchar('\n');
	}
	*/
	
	printf("\n");

	for(i=0;i<cnt-1;i++)
	{
		printf("第%d行：",i+1);
		
		//现在来排序i行里面的j个元素 
		for(j=1;j<num[i];j++)
		{
			int  len     =  num[i] - j ;
			int  maxid   =  max( a[i] , len );
			int  temp    =  a[i][len];
			a[i][len]    =  a[i][maxid];
			a[i][maxid]  =  temp;
		}
		
		for(j=num[i]-1;j>=0;j--)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	} 
	
	
} 
