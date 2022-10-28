/*键盘输入一个二维数组，求该数组的鞍点。*/
//鞍点：
//该数组的某个数（某行某列），该数是所在行的最大值，同时也是所在列的最小值。
//反之，该数是所在行的最小值，同时也是所在列的最大值。
//对给定数组可能有鞍点，也可能没有鞍点，或者不止一个鞍点

#include<stdio.h>
#define ROW 	3
#define COLUMN 	3
int main()
{
	int array[ROW][COLUMN];		//保存数据 
	int flag[ROW][COLUMN]={0}; 	//记录鞍点 
	
	int i,j;
	for(i=0;i<ROW;i++)
	{
		printf("输入第%d行的%d个数: ",i,COLUMN);
		for(j=0;j<COLUMN;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	
	int min,max;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			/*判断一个数是不是该行的最大值*/
			int k,flagmax=1;
			for(k=0;k<COLUMN;k++) 
			{
				if(j!=k && array[i][j]<array[i][k]) flagmax=0;//不是最大值 
			}
			if(flagmax == 1)//是最大值 
			{
				/*判断一个数是不是该列的最小值*/
				int flagmin = 1;
				for(k=0;k<ROW;k++)
				{
					if(i!=k && array[i][j]>array[k][j]) flagmin=0;
				}
					/*记录鞍点*/
				if(flagmin == 1) flag[i][j] = 1;
			}
		}
	}
	//判断一个数是不是该行的最小值
		//判断一个数是不是该列的最大值
			//记录鞍点
			
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			/*判断一个数是不是该行的最小值*/
			int k,flagmin=1;
			for(k=0;k<COLUMN;k++) 
			{
				if(j!=k && array[i][j]>array[i][k]) flagmin=0;//不是最小值 
			}
			if(flagmin == 1)//是最小值 
			{
				/*判断一个数是不是该列的最大值*/
				int flagmax = 1;
				for(k=0;k<ROW;k++)
				{
					if(i!=k && array[i][j]<array[k][j]) flagmax=0;
				}
					/*记录鞍点*/
				if(flagmax == 1) flag[i][j] = 1;
			}
		}
	}
				
	//打印鞍点数组
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			if(flag[i][j] == 1) 	printf("%-5d",array[i][j]);
			else				printf("NOT  ");
		}
		puts("");
	}
}





