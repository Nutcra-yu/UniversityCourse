#include<stdio.h>

#define NUMBER 80

int main()
{
	int i,j;
	int num;
	int score[NUMBER];
	int distri[11]={0};
	
	printf("学生人数");
	scanf("%d",&num);
	printf("所有分数\n");
	
	for(i=0;i<num;i++)
	{
		scanf("%d",&score[i]);
		distri[score[i]/10]++;	 
	}
	
	puts("\n---分布图---");
	printf("     100:");
	
	for(j=0 ; j< distri[10] ; j++)
		putchar('*');
	putchar('\n');
	
	for(i=9 ; i>=0 ; i--)
	{
		printf("%3d - %2d:", i*10 ,i*10+9);
		for(j=0 ; j<distri[i] ; j++)
			putchar('*');
		putchar('\n');
	}
	
	return 0;
	
}
