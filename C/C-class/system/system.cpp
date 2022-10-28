#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*班级*/
void Analyze(int classnumber); /*最高最低分 平均分 及格人数及格率*/
/*与Analyze()搭配使用*/
void Max(int classnumber);	   //班级最高分
void Min(int classnumber);	   //班级最低分
void Average(int classnumber); //班级平均分
void Pass(int classnumber);	   //班级及格人数与及格率

/*年级*/
void Analyze(); /*最高最低分 平均分 及格人数及格率*/
/*与Analyze()搭配使用*/
void Max();		//年级最高分
void Min();		//年级最低分
void Average(); //年级平均分
void Pass();	//年级及格人数与及格率

void PrintAll(int classnumber); //打印成绩（全班）
void PrintAll();				//打印成绩（全级）

void PrintLowToHigh(int classnumber); //从高到低打印
void PrintLowToHigh();				  //从高到低打印(年级)

/*辅助函数*/
int ChooseClass();												  //选择班级
float ClassAverage(int classnumber, int coursenumber);			  //班级平均分（参数：班级号，科目号
int ChooseCourse();												  //选择科目
void LowToHigh(struct student *array, int coursenumber, int len); //将数组从低到高排序
int SumGrade();													  //年级总人数

struct student
{
	char *id;		 //学号
	char *name;		 //名字
	int classnumber; //班级
	float *scores;	 //用于存储各科数据
	float total;	 //个人总分
};

char **Course;	  //存储科目名字
int CourseNumber; //科目数量

int ClassTotal;			//总共的班级数
int *ClassContain;		//存储每个班级人数
struct student **Class; //存储数据

int main()
{
	
	int i, j, k;			 //用于循环
	int classnumber;		 //班级号
	int dosth;				 //接受操作
	struct student *stutemp; //指向当前操作的学生

	/*這学期学了多少科目*/
	printf("這学期学了多少科目：");
	scanf("%d", &CourseNumber);
	Course = (char **)malloc(CourseNumber * sizeof(char *));
	for (i = 0; i < CourseNumber; i++)
	{
		printf("第%d门科目是:", i + 1);
		char a[10];
		scanf("%s", a);
		*(Course + i) = (char *)malloc(strlen(a) * sizeof(char));
		strcpy(*(Course + i), a);
	}

	system("cls");

	/*年级有多少班*/
	printf("年级有多少班：");
	scanf("%d", &ClassTotal);
	Class = (struct student **)malloc(ClassTotal * sizeof(struct student));
	ClassContain = (int *)malloc(ClassTotal * sizeof(int));

	/*每个班有多少人*/
	for (i = 0; i < ClassTotal; i++) 
	{
		int contain;
		printf("%d有多少人:", i + 1);
		scanf("%d", &contain);
		ClassContain[i] = contain;
		*(Class + i) = (struct student *)malloc(contain * sizeof(struct student));
	}

	/*每个人的成绩*/
	for (i = 0; i < ClassTotal; i++) //年级里的班循环
	{
		system("cls");
		printf("%d班:(%d人)\n", i + 1, ClassContain[i]);

		//班级里的人循环
		for (j = 0; j < ClassContain[i]; j++)
		{
			stutemp = (*(Class + i) + j);

			stutemp->scores = (float *)malloc(CourseNumber * sizeof(float));

			char a[20];
			printf("%d班的第%d个人:\n", i + 1, j + 1);

			printf("学号：");
			scanf("%s", a);
			stutemp->id = (char *)malloc(strlen(a) * sizeof(char));
			strcpy(stutemp->id, a);

			printf("姓名：");
			scanf("%s", a);
			stutemp->name = (char *)malloc(strlen(a) * sizeof(char));
			strcpy(stutemp->name, a);

			stutemp->classnumber = i + 1;

			puts("各科成绩：");
			for (k = 0; k < CourseNumber; k++)
			{
				printf(" %-8s:", *(Course + k));
				scanf("%f", ((stutemp->scores) + k));
				stutemp->total = 0;
				stutemp->total += *(stutemp->scores + k);
			}

			puts("");
		}
	}
	system("cls");

	/*选择操作层面  年级 or 班级*/
mainChoose:
	while (1)
	{
		system("cls");
		enum Grade_or_Class
		{
			EXIT = -1,
			GRADE = 0,
			CLASSES = 1
		};
		puts("选择操作层面：");
		puts("0:年级 1:班级 (-1:退出) ");
		scanf("%d", &dosth);
		switch (dosth)
		{
		default:
			goto mainChoose;

		case EXIT:
			return 0;

GradeChoose:
		case GRADE:
			while (1)
			{
				system("cls");
				enum DO
				{
					AnalyzeScore = 1,
					PrintGradeAll = 2,
					PrintLowtoHigh = 3,
					PrintHightoLow = 4,
					BACK = -1
				};
				puts("对年级进行操作：");
				puts("1:分析成绩 2:打印所有成绩 3:从低到高 (-1:返回) ");
				scanf("%d", &dosth);
				switch (dosth)
				{
				case BACK:
					goto mainChoose;

				case AnalyzeScore:
					system("cls");
					Analyze();
					puts("");
					system("pause");
					goto GradeChoose;

				case PrintGradeAll:
					system("cls");
					PrintAll();
					puts("");
					system("pause");
					goto GradeChoose;

				case PrintLowtoHigh:
					system("cls");
					PrintLowToHigh();
					system("pause");
					goto GradeChoose;

				case PrintHightoLow:
					system("cls");
					//还没写	PrintHighToLow();
					system("pause");
					goto GradeChoose;

				default:
					goto GradeChoose;
				}
			}

		case CLASSES:
			system("cls");
			classnumber = ChooseClass();
ClassesChoose:
			while (1)
			{
				system("cls");
				enum DO
				{
					Choose = 0,
					AnalyzeScore = 1,
					PrintClassAll = 2,
					PrintFromLowToHigh = 3,
					BACK = -1
				};
				printf("对%d班的操作:\n", classnumber + 1);
				puts("0:重新选班 1:分析成绩 2:打印所有 3:从低到高 (-1:返回) ");
				scanf("%d", &dosth);
				switch (dosth)
				{
				default:
					goto ClassesChoose;

				case Choose:
					classnumber = ChooseClass();
					goto ClassesChoose;

				case AnalyzeScore:
					system("cls");
					Analyze(classnumber);
					puts("");
					system("pause");
					goto ClassesChoose;

				case PrintClassAll:
					system("cls");
					PrintAll(classnumber);
					puts("");
					system("pause");
					goto ClassesChoose;

				case PrintFromLowToHigh:
					system("cls");
					PrintLowToHigh(classnumber);
					puts("");
					system("pause");
					goto ClassesChoose;

				case BACK:
					goto mainChoose;
				}
			}
		}
	}

	free(Class);
	free(Course);
	free(ClassContain);
}

/*函数*/
int ChooseClass() //选择班级 返回时候减一（适用于数组）
{
	int classnumber;
Choose:
	printf("选择班级（共%d个）:", ClassTotal);
	scanf("%d", &classnumber);
	if (classnumber <= 0 || ClassTotal < classnumber)
	{
		printf("超出范围 ");
		goto Choose;
	}
	return classnumber - 1;
}

void PrintAll(int classnumber) //打印全部(班级)
{
	int i, j;
	struct student *temp;
	float tempscore;

	/*打印基本信息*/
	printf("\n%d班:\n", classnumber + 1);
	printf("%-7s %-7s :", "姓名", "学号");
	for (i = 0; i < CourseNumber; i++)
		printf("%-8s ", *(Course + i));
	puts("");

	//个人循环
	for (i = 0; i < ClassContain[classnumber]; i++)
	{
		temp = (*(Class + classnumber) + i); // temp指向当前学生
		printf("%-7s %-7s :", temp->name, temp->id);
		//科目循环
		for (j = 0; j < CourseNumber; j++)
		{
			tempscore = *(temp->scores + j);

			printf("%-8.1f ", tempscore);
		}
		puts("");
	}
}
void PrintAll() //打印全部（年级）()
{
	int i;

	//班级循环
	for (i = 0; i < ClassTotal; i++)
	{
		PrintAll(i);
	}
}

void Analyze(int classnumber) //数据分析（班级）
{
	printf("\n%d班:\n", classnumber + 1);
	printf("\n总人数:%d\n", ClassContain[classnumber]);
	Max(classnumber);
	Min(classnumber);
	Average(classnumber);
	Pass(classnumber);
}
void Analyze() //数据分析（年级）
{
	printf("\n总人数:%d\n", SumGrade());
	Max();
	Min();
	Average();
	Pass();
}

void Max(int classnumber) //最高分（班级）
{
	int i, j;
	struct student *temp;
	char id[10], name[10];
	float tempscore;
	float max;

	printf("\n班级最高分\n");

	//科目循环
	for (i = 0; i < CourseNumber; i++)
	{
		printf(" %s:\n", *(Course + i));

		/*将数据初始化为第一个学生*/
		temp = (*(Class + classnumber) + 0); // temp指向第一个学生
		tempscore = *(temp->scores + i);
		max = tempscore;
		strcpy(id, temp->id);
		strcpy(name, temp->name);

		//个人循环
		for (j = 0; j < ClassContain[classnumber]; j++)
		{

			temp = (*(Class + classnumber) + j); // temp指向当前学生
			tempscore = *(temp->scores + i);	 // tempscore为当前学生的成绩

			if (max < tempscore)
			{
				max = tempscore;
				strcpy(id, temp->id);
				strcpy(name, temp->name);
			}
		}
		printf("  %4.2f (%s,%s)\n", max, id, name);

		/*避免高分重复 再遍历一次*/

		char maxid[10]; //创建一个id用于存储第一次遍历的值 避免重复
		strcpy(maxid, id);

		//个人循环
		for (j = 0; j < ClassContain[classnumber]; j++)
		{
			temp = (*(Class + classnumber) + j); // temp指向当前学生
			tempscore = *(temp->scores + i);	 // tempscore为当前学生的成绩
			strcpy(id, temp->id);

			if (tempscore == max && strcmp(maxid, id) != 0)
			{
				strcpy(name, temp->name);
				printf("  %4.2f (%s,%s)\n", max, id, name);
			}
		}
	}
}
void Max() //最高分（年级）
{
	int i, j, k;
	struct student *temp;
	float tempscore;

	/*打印的信息*/
	float max;			   //最高分
	int classnumber;	   //班级
	char name[10], id[10]; //学号与姓名

	printf("\n年级最高分:\n");

	//科目循环
	for (i = 0; i < CourseNumber; i++)
	{
		printf(" %s:\n", *(Course + i));

		classnumber = 0;

		/*将数据初始化为第一个学生*/
		temp = (*(Class + classnumber) + 0); //将temp指向第一个学生
		max = *(temp->scores + i);
		strcpy(name, temp->name);
		strcpy(id, temp->id);

		//班级循环
		for (j = 0; j < ClassTotal; j++)
		{
			//个人循环
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = (*(Class + j) + k);		 // temp指向当前学生
				tempscore = *(temp->scores + i); // tempscore为当前学生的成绩
				if (max < tempscore)
				{
					max = tempscore;
					strcpy(name, temp->name);
					strcpy(id, temp->id);
				}
			}
		}

		printf("  %5.1f (%d班,%s,%s)\n", max, classnumber + 1, id, name);

		//避免高分重复 再遍历一次

		char maxid[10]; //创建一个id用于存储第一次遍历的值 避免重复
		strcpy(maxid, id);

		//班级循环
		for (j = 0; j < ClassTotal; j++)
		{
			//个人循环
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = (*(Class + j) + k);		 // temp指向当前学生
				tempscore = *(temp->scores + i); // tempscore为当前学生的成绩
				strcpy(id, temp->id);

				if (max == tempscore && strcmp(maxid, id) != 0)
				{
					classnumber = j;
					strcpy(name, temp->name);

					printf("  %5.1f (%d班,%s,%s)\n", max, classnumber + 1, id, name);
				}
			}
		}
	}
}
void Min(int classnumber) //最低分（班级）
{
	int i, j;
	struct student *temp;
	float tempscore;
	float min;

	printf("\n班级最低分\n");

	//科目循环
	for (i = 0; i < CourseNumber; i++)
	{
		temp = (*(Class + classnumber) + 0); // temp指向当前学生
		tempscore = *(temp->scores + i);	 // tempscore为当前学生的成绩
		min = tempscore;

		//个人循环
		for (j = 0; j < ClassContain[classnumber]; j++)
		{

			temp = (*(Class + classnumber) + j); // temp指向当前学生
			tempscore = *(temp->scores + i);	 // tempscore为当前学生的成绩

			if (min > tempscore)
				min = tempscore;
		}

		printf(" %-8s:%4.1f\n", *(Course + i), min);
	}
}
void Min() //最低分（年级）
{
	int i, j, k;
	struct student *temp;
	float tempscore;

	/*打印的信息*/
	float min; //最低分

	printf("\n年级最低分:\n");

	/*科目循环*/
	for (i = 0; i < CourseNumber; i++)
	{

		temp = (*(Class + 0) + 0); //将temp指向第一个学生

		//将数据初始化为第一个学生
		min = *(temp->scores + i);

		/*班级循环*/
		for (j = 0; j < ClassTotal; j++)
		{
			/*个人循环*/
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = (*(Class + j) + k);		 // temp指向当前学生
				tempscore = *(temp->scores + i); // tempscore为当前学生的成绩
				if (min > tempscore)
				{
					min = tempscore;
				}
			}
		}

		printf(" %-8s:  %5.1f \n", *(Course + i), min);
	}

	puts("");
}
void Average(int classnumber) //平均分（班级）
{
	int i, j;
	float average;

	printf("\n班级平均分\n");

	//科目循环
	for (i = 0; i < CourseNumber; i++)
	{
		average = ClassAverage(classnumber, i);

		printf(" %-8s:%4.2f\n", *(Course + i), average);
	}
}
void Average() //平均分（年级）
{

	int i, j, k;
	struct student *temp;
	float tempscore;

	float sum;
	float average;

	printf("\n年级平均分:\n");

	//科目循环
	for (i = 0; i < CourseNumber; i++)
	{
		sum = 0;

		//班级循环
		for (j = 0; j < ClassTotal; j++)
		{
			sum += ClassAverage(j, i);
		}

		average = sum / ClassTotal;
		printf(" %-8s: %6.2f\n", *(Course + i), average);
	}
}
void Pass(int classnumber) //及格人数及及格率（班级）
{
	int i, j;
	struct student *temp;
	float tempscore;

	int count;
	float passpercent;

	printf("\n班级及格情况\n", classnumber + 1);

	//科目循环
	for (i = 0; i < CourseNumber; i++)
	{
		count = 0;

		//个人循环
		for (j = 0; j < ClassContain[classnumber]; j++)
		{
			temp = (*(Class + classnumber)) + j;
			tempscore = *(temp->scores + i);
			if (tempscore >= 60)
				count++;
		}

		passpercent = 100.0 * count / ClassContain[classnumber];

		printf("");
		printf(" %-8s:及格人数:%d 及格率:%4.2f%%\n", *(Course + i), count, passpercent);
	}
}
void Pass() //及格人数及及格率（年级）
{
	int i, j, k;
	struct student *temp;
	float tempscore;

	int count;
	float passpercent;

	printf("\n年级及格情况:\n");

	//科目循环
	for (i = 0; i < CourseNumber; i++)
	{
		count = 0;
		//班级循环
		for (j = 0; j < ClassTotal; j++)
		{
			//个人循环
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = *(Class + j) + k;		 // temp指向当前学生
				tempscore = *(temp->scores + i); // temp为学生成绩
				if (tempscore >= 60)
					count++;
			}
		}

		passpercent = 100.0 * count / SumGrade();

		printf(" %-8s:", *(Course + i));
		printf(" 及格人数:%-2d 及格率:%6.2f%%\n", count, passpercent);
	}
}

void PrintLowToHigh(int classnumber) //从低到高打印（班级）
{
	int i;
	int coursechoose;
	float tempscore;
	struct student *temp;	 //用于存放数据
	struct student *tempstu; //用于寄存学生指针

	/*选择课程*/
	coursechoose = ChooseCourse();

	//分配数组内存
	temp = (struct student *)malloc(ClassContain[classnumber] * sizeof(struct student));
	//存储数据
	for (i = 0; i < ClassContain[classnumber]; i++)
	{
		tempstu = *(Class + classnumber) + i; // tempstu指向当前学生
		*(temp + i) = *tempstu;				  //将学生数据交给temp
	}

	//将数组从低到高排序
	LowToHigh(temp, coursechoose, ClassContain[classnumber]);

	system("cls");
	printf("%d班 %s\n", classnumber + 1, *(Course + coursechoose));

	printf("%-8s %-8s : 成绩\n", "学号", "名字");
	//打印
	for (i = 0; i < ClassContain[classnumber]; i++)
	{
		tempstu = temp + i;
		tempscore = *(tempstu->scores + coursechoose);
		printf("%d班 %-8s %-8s : %5.1f\n", tempstu->classnumber, tempstu->id, tempstu->name, tempscore);
	}
}
void PrintLowToHigh() //从低到高打印（年级）（）
{
	int i, j;
	int coursechoose;
	float tempscore;
	struct student *temp;	 //存储数据
	struct student *tempstu; //记录当前学生

	/*选择课程*/
	coursechoose = ChooseCourse();

	system("cls");

	/*数据填充*/
	temp = (struct student *)malloc(SumGrade() * sizeof(student)); //分配内存

	int n = 0;
	for (i = 0; i < ClassTotal; i++) //班级循环
	{
		for (j = 0; j < ClassContain[i]; j++) //个人循环
		{
			tempstu = *(Class + i) + j;
			*(temp + n) = *tempstu;
			n++;
		}
	}

	/*数据排序*/
	LowToHigh(temp, coursechoose, SumGrade());

	/*打印数据*/
	printf("%-8s %-8s : 成绩\n", "学号", "名字");
	for (i = 0; i < SumGrade(); i++)
	{
		tempstu = temp + i;
		tempscore = *(tempstu->scores + coursechoose);
		printf("%d班 %-8s %-8s : %5.1f\n", tempstu->classnumber, tempstu->id, tempstu->name, tempscore);
	}
}

/*辅助函数*/
float ClassAverage(int classnumber, int coursenumber)
{
	int i;
	struct student *tempstu;
	float tempscore;
	float sum = 0;

	for (i = 0; i < ClassContain[classnumber]; i++)
	{
		tempstu = (*(Class + classnumber) + i);
		tempscore = *(tempstu->scores + coursenumber);
		sum += tempscore;
	}

	float average = sum / ClassContain[classnumber];
	return average;
}
int ChooseCourse() //选择课程
{
	int i;
	int coursechoose;

	//打印信息
	printf("选择课程:\n");
	for (i = 0; i < CourseNumber; i++)
		printf("%d:%s ", i, *(Course + i));
	puts("");
	//获取课程
	scanf("%d", &coursechoose);

	return coursechoose;
}
void LowToHigh(struct student *array, int coursenumber, int len) //将一个数组从高到低排序 （参数： 学生数组指针 排序课程编号 数组长度）
{
	//选择排序
	int i, j, minIndex;
	float min;
	struct student x;

	for (i = 0; i < len; i++)
	{
		min = *(array + i)->scores; //*((array+i)->scores+0)
		minIndex = i;
		//找到最小的数字
		for (j = i; j < len; j++)
		{
			if (*(array + j)->scores <= min)
			{
				min = *(array + j)->scores;
				minIndex = j;
			}
		}
		//交换
		x = *(array + i);
		*(array + i) = *(array + minIndex);
		*(array + minIndex) = x;
	}
}
int SumGrade() //年级总人数
{
	int sum = 0, i;
	for (i = 0; i < ClassTotal; i++)
		sum += ClassContain[i];

	return sum;
}









