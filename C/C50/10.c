/*假设一个班有n(n<=50)个学生，每人考m(m<=5)门课
求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量*/


//Input
/*输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数。
然后是n行数据，每行包括m个整数（即：考试分数）*/



//Output
/*对于每个测试实例，输出3行数据
第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；
第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；
第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。*/

#include<stdio.h>
int main()
{
	printf("输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数\n" 
	"然后是n行数据，每行包括m个整数\n");
	
	/*需要的变量*/
	int a[50][5]={0};					//定义一个50*5的数组 
	int i,j; 
	int n;								//学生人数 n
	int m; 								// 课程数  m
	scanf("%d",&n); scanf("%d",&m);		//输入n，m 
	int     sum_stu ; 				//每名学生的总分 
	double aver_stu ; 				//每名学生的平均成绩 stu_aver 
	int		sum_class[5]={0} ;				//每门课的总分 
	double aver_class[5]={0} ;				//每门课的平均成绩
	int 	 num=0	  ;				//各科成绩均大于等于平均成绩的学生数量
	int pass;						//判断学生是否过平均分 
	 
	//标头 
	printf("    	"); 
	for(j=1;j<=m;j++)
	{
		printf("第%d门课程	",j);
	}
	printf("\n");
	
	/*存储数据*/
	//学生 
	for(i=0;i<n;i++)
	{
		printf("第%d名学生：",i+1); 
		
	//课程 
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\n");
	
	
	
	/*求数据*/
	
	//每名学生的平均成绩
	printf("每名学生的平均成绩\n");
	for(i=0;i<n;i++) 
	{
		sum_stu  = 0;
		aver_stu = 0;
		for(j=0;j<m;j++)
		{
			sum_stu  += a[i][j];
			aver_stu = 1.0*sum_stu/m;
		}
		printf("学生%d:%.2f\n",i+1,aver_stu);
	}
	printf("\n");
	
	//每门课的平均成绩
	printf("每门课的平均成绩\n");
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++) 	sum_class[j] += a[i][j];
		aver_class[j]  = 1.0*sum_class[j]/n;
		printf("课程%d：%.2f",j+1,aver_class[j]); 
		printf("	"); 
	}
	
	printf("\n");
	printf("\n");
	
	//各科成绩均大于等于平均成绩的学生数量
	for(i=0;i<n;i++) 
	{
		pass=1;
		for(j=0;j<m;j++)
		{
			if(a[i][j]<aver_class[j])
			{
				pass=0;
				break;
			}
		}
		if(pass == 1)
			num++;
	}
	printf("各科成绩均大于等于平均成绩的学生数量:\n");
	printf("%d",num);
		
}






