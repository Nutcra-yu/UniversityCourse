//给你n个整数，求他们中所有奇数的乘积。

#include<stdio.h>

//输入数据包含多个测试实例，每个测试实例占一行，每行的第一个数为n，表示本组数据一共有n个，
//接着是n个整数，你可以假设每组数据必定至少存在一个奇数。

 
int main()
{
	printf("输入数据包含多个测试实例，每个测试实例占一行\n"
	"每行的第一个数为n，表示本组数据一共有n个，接着是n个整数\n\n");
	
	//定义一个100*100的数组
	int a[100][100]={0};
	
	//数组numu用来存储每一行的元素个数 
	int num[100]={0};
	
	/*需要的变量*/
	int i,j;
	//cnt记录行数 
	int cnt=0;
	//result存储乘积 
	int result;
	//记录是否有奇数
	int odd; 
	 
	/*先存储数据*/
	
	//第i行 
	for(i=0;;i++)
	{
		//第i行有num[i]个数 
		scanf("%d",&num[i]);
		
		//为 0 结束输入 
		if(num[i] == 0) 	break;
		
		//记行 
		cnt++;
		
		//j个元素 
		for(j=0;j<num[i];j++)
		{
			scanf("%d",&a[i][j]);
		} 
	}
	
	printf("\n奇数的乘积\n");
	
	//计算并输出 
	for(i=0;i<cnt;i++)
	{
		result = 1 ;
		
		odd = 0;
		
		for(j=0;j<num[i];j++)
		{
			if(a[i][j]%2 == 1)
			{
				result *= a[i][j];
				odd++;
			}
		}
		
		if(odd == 0)
			printf("第%d行没有奇数呢\n",i+1);
		else
			printf("第%d行：%d\n",i+1,result);
		
	}
	
	
	
	
}
