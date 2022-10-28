#include<stdio.h> 		/*线性查找*/

#define NUMBER 5


int search( int n , int a[] , int x) 	//寻找n是否存在于a[x]中，存在为1，不存在为0 
{
	int i=1;
	
	while(1)
	{
		if(n == a[i-1]) 	return i;	//i>=1 
		if(i == x) return 0;
		i++;
	}
}


int main()
{
	int a[NUMBER];
	int i,n;
	
	for(i=0;i<NUMBER;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	
	puts("请输入你想寻找的数");
	scanf("%d",&n); 
	
	int sear = search( n , a , NUMBER);
	 
	if(sear == 0) 	printf("%d不在a[]里面哦"); 
	else 				printf("%d是a[%d]",n,sear-1);
	
	return 0;
	
}

/*好吧
我根本就没有在学，不过是在混时长而已
TMD艹
我怎么，哎呀
不行啊不行啊
rnm rnm rnm rnm */
