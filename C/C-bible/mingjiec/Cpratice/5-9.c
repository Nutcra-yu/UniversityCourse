#include<stdio.h>
int main()
{
	int score[80];
	int num,max=0;
	int dis[11]={0};
	int i;
	
	puts("请输入学生人数");
	scanf("%d",&num);
	puts("请输入学生分数"); 
	
	for(i=0;i<num;i++)
	{
		scanf("%d",&score[i]);
		dis[score[i]/10]++;
		if(dis[score[i]/10]>max)
			max = dis[score[i]/10];
	}
	
	int j;
	int t=max;
	for(j=1;j<=t;j++)
	{
		for(i=0;i<11;i++)
		{
			if(dis[i]<max)
				printf("       ");
			else
				printf("  *    ");
		}
		max--;
		putchar('\n');
	}

	for(i=0;i<=75;i++)
		printf("-");
	
	putchar('\n');
	
	for(i=0;i<=9;i++)
	{
		printf("%2d-%2d  ",i*10,i*10+9);
	}
	
	printf(" 100");
	
	 return 0;
}
