#include<stdio.h>

int take[5],n=0; 
int like[5][5] = { {0,0,1,1,0},{1,1,0,0,1},{0,1,1,0,1},{0,0,0,1,0},{0,1,0,0,1} };
int book[5] = {0,0,0,0,0};

void Try(int i);

int main()
{
	Try(0);
	return 0;
}

void Try(int i)
{
	
	int j,k;
	for(j=0;j<=4;j++)
	{
		//i同学是否喜欢j书  
		if(like[i][j]>0 && book[j]==0)
		{
			take[i] = j; // i同学拿到了j书 
			book[j] = 1; 
			if(i == 4)
			{
				n++;
				printf("======第%d个方案======\n",n);
				for(k=0;k<=4;k++)
					printf("%d书分给%c\n",take[k],'A'+k);
				printf("\n");
			}
			else
				Try(i+1);
			book[j] = 0;
		}
	}
}
