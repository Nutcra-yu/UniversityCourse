#include<stdio.h>
int a1,b1,a2,b2;
//任意两个矩阵相乘

//自定义一个a行b列的矩阵
int set(int a,int b)
{
	int m[a][b] ;
	puts("请输入矩阵中的数字"
		 "(一行中相邻的两个数用Tab隔开，换行用Enter)");
		 
	int i,j;
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	
	return m;
}

//两个矩阵相乘，且存储到第三个矩阵
int  multiply(int M1[a1][b1] ,int M2[a2][b2])
{
	int M[a1][b2];
	int i,j;
	
	for(i=0;i<a1;j++)
	{
		for(j=0;j<b2;j++)
		{
			
		}
	}
}

//失败了呀好兄弟5555555 
 
int main()
{
	puts("请输入两个矩阵 M1和M2 的行数和列数\n");
	int a1,b1,a2,b2;
	
	do{	
		printf("M1\n"); 
		printf("行数a1："); 	scanf("%d",&a1);
		printf("列数b1："); 	scanf("%d",&b1);
		putchar('\n');
		printf("M2\n"); 
		printf("行数a2："); 	scanf("%d",&a2);
		printf("列数b2："); 	scanf("%d",&b2);	 
		putchar('\n');
		if(b1 != a2) 	puts("错误！！！\nb1和a2要相等\n"); 
	}while( b1 != a2);
	
	printf("第一个矩阵\n"); 
	int M1 = set(a1,b1);
	printf("第二个矩阵\n"); 
	int M2 = set(a2,b2);
	
	
	

}





