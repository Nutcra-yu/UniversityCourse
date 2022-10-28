#include<stdio.h>
int main()
{
	int score[6][2];	//6名学生，两门课程
	int i,j;
	int person[6];
	double aver=0; 
	
	puts("请依次输入六名学生的两次分数");
	for(i=0;i<6;i++)
	{
		printf("第%d名学生的两次分数\n",i+1);
			scanf("%d",&score[i][0]);
			scanf("%d",&score[i][1]);
		person[i]=(score[i][0]+score[i][1])/2.0;
		//	person[0]=(score[0][0]+score[0][1])/2.0;
		aver += person[i];
	} 
	
	putchar('\n');
	
	for(i=1;i<=6;i++)
	{
		printf("第%d名学生的平均分是：%d\n",i,person[i-1]);
	}
	
	printf("全班同学的平均分是:%.2lf",aver/6.0);
	
	return 0;
	
}
