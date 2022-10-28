#include<stdio.h>
int max(int a[],int len)
{
	int i;
	int maxid=0;
	for(i=1;i<len;i++)
	{
		if(a[i]>a[maxid])	maxid=i;
	}
	return maxid;
}


int main()
{
	//定义一个数组 
	int i,a[3]; 
	puts("请输入三条边");
	for(i=0;i<3;i++)
	{
		printf("第%d条边是:",i+1);
		scanf("%d",&a[i]);
	}
	
	//排个序
	for(i=2;i>=0;i--)
	{
		//找到最大值的位置
		int maxid=max(a,i+1);
		//调换最大值和最后一个数的位置
		int t=a[i];
		a[i]=a[maxid];
		a[maxid]=t;
	}
	
	if(a[0]+a[1]<=a[2])
		printf("0(不能构成一个三角形)");
	else if(a[0] == a[1] && a[1] == a[2])
		printf("1（正三角形）");
	else if(a[0]==a[1] || a[1]==a[2] || a[0]==a[2])
		printf("2(等腰三角形)");
	else
		printf("3(任意三角形)"); 
	
	return 0;
	 
}
