#include<stdio.h>

#define NUMBER 100

int search (int n , int a[] , int key ) 	//在n个元素的数组a里寻找key 
{
	int i=0;
	a[n] = key;
	while(1)
	{
		if( a[i] == key ) 	return i;
		i++;
	}
}

int main()
{ 	//哨兵查找
	int n;
	int i;
	int a[ NUMBER ];
	int key;
	
	printf("您想输入几个数：");
	scanf("%d",&n);
	putchar('\n');
	 
	for(i=0;i<n;i++)
	{
		printf("a[%d]是：",i);
		scanf("%d",&a[i] );
	}
	
	putchar('\n');
	printf("您想找的数是：");
	scanf("%d",&key);
	putchar('\n');
	
	int result = search( n , a ,key);
	if(result == n) 	puts("查找失败");
	else 	printf("您要找的是a[%d]",result);
	
	return 0; 
}
