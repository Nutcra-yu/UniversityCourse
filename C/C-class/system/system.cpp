#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*�༶*/
void Analyze(int classnumber); /*�����ͷ� ƽ���� ��������������*/
/*��Analyze()����ʹ��*/
void Max(int classnumber);	   //�༶��߷�
void Min(int classnumber);	   //�༶��ͷ�
void Average(int classnumber); //�༶ƽ����
void Pass(int classnumber);	   //�༶���������뼰����

/*�꼶*/
void Analyze(); /*�����ͷ� ƽ���� ��������������*/
/*��Analyze()����ʹ��*/
void Max();		//�꼶��߷�
void Min();		//�꼶��ͷ�
void Average(); //�꼶ƽ����
void Pass();	//�꼶���������뼰����

void PrintAll(int classnumber); //��ӡ�ɼ���ȫ�ࣩ
void PrintAll();				//��ӡ�ɼ���ȫ����

void PrintLowToHigh(int classnumber); //�Ӹߵ��ʹ�ӡ
void PrintLowToHigh();				  //�Ӹߵ��ʹ�ӡ(�꼶)

/*��������*/
int ChooseClass();												  //ѡ��༶
float ClassAverage(int classnumber, int coursenumber);			  //�༶ƽ���֣��������༶�ţ���Ŀ��
int ChooseCourse();												  //ѡ���Ŀ
void LowToHigh(struct student *array, int coursenumber, int len); //������ӵ͵�������
int SumGrade();													  //�꼶������

struct student
{
	char *id;		 //ѧ��
	char *name;		 //����
	int classnumber; //�༶
	float *scores;	 //���ڴ洢��������
	float total;	 //�����ܷ�
};

char **Course;	  //�洢��Ŀ����
int CourseNumber; //��Ŀ����

int ClassTotal;			//�ܹ��İ༶��
int *ClassContain;		//�洢ÿ���༶����
struct student **Class; //�洢����

int main()
{
	
	int i, j, k;			 //����ѭ��
	int classnumber;		 //�༶��
	int dosth;				 //���ܲ���
	struct student *stutemp; //ָ��ǰ������ѧ��

	/*�@ѧ��ѧ�˶��ٿ�Ŀ*/
	printf("�@ѧ��ѧ�˶��ٿ�Ŀ��");
	scanf("%d", &CourseNumber);
	Course = (char **)malloc(CourseNumber * sizeof(char *));
	for (i = 0; i < CourseNumber; i++)
	{
		printf("��%d�ſ�Ŀ��:", i + 1);
		char a[10];
		scanf("%s", a);
		*(Course + i) = (char *)malloc(strlen(a) * sizeof(char));
		strcpy(*(Course + i), a);
	}

	system("cls");

	/*�꼶�ж��ٰ�*/
	printf("�꼶�ж��ٰࣺ");
	scanf("%d", &ClassTotal);
	Class = (struct student **)malloc(ClassTotal * sizeof(struct student));
	ClassContain = (int *)malloc(ClassTotal * sizeof(int));

	/*ÿ�����ж�����*/
	for (i = 0; i < ClassTotal; i++) 
	{
		int contain;
		printf("%d�ж�����:", i + 1);
		scanf("%d", &contain);
		ClassContain[i] = contain;
		*(Class + i) = (struct student *)malloc(contain * sizeof(struct student));
	}

	/*ÿ���˵ĳɼ�*/
	for (i = 0; i < ClassTotal; i++) //�꼶��İ�ѭ��
	{
		system("cls");
		printf("%d��:(%d��)\n", i + 1, ClassContain[i]);

		//�༶�����ѭ��
		for (j = 0; j < ClassContain[i]; j++)
		{
			stutemp = (*(Class + i) + j);

			stutemp->scores = (float *)malloc(CourseNumber * sizeof(float));

			char a[20];
			printf("%d��ĵ�%d����:\n", i + 1, j + 1);

			printf("ѧ�ţ�");
			scanf("%s", a);
			stutemp->id = (char *)malloc(strlen(a) * sizeof(char));
			strcpy(stutemp->id, a);

			printf("������");
			scanf("%s", a);
			stutemp->name = (char *)malloc(strlen(a) * sizeof(char));
			strcpy(stutemp->name, a);

			stutemp->classnumber = i + 1;

			puts("���Ƴɼ���");
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

	/*ѡ���������  �꼶 or �༶*/
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
		puts("ѡ��������棺");
		puts("0:�꼶 1:�༶ (-1:�˳�) ");
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
				puts("���꼶���в�����");
				puts("1:�����ɼ� 2:��ӡ���гɼ� 3:�ӵ͵��� (-1:����) ");
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
					//��ûд	PrintHighToLow();
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
				printf("��%d��Ĳ���:\n", classnumber + 1);
				puts("0:����ѡ�� 1:�����ɼ� 2:��ӡ���� 3:�ӵ͵��� (-1:����) ");
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

/*����*/
int ChooseClass() //ѡ��༶ ����ʱ���һ�����������飩
{
	int classnumber;
Choose:
	printf("ѡ��༶����%d����:", ClassTotal);
	scanf("%d", &classnumber);
	if (classnumber <= 0 || ClassTotal < classnumber)
	{
		printf("������Χ ");
		goto Choose;
	}
	return classnumber - 1;
}

void PrintAll(int classnumber) //��ӡȫ��(�༶)
{
	int i, j;
	struct student *temp;
	float tempscore;

	/*��ӡ������Ϣ*/
	printf("\n%d��:\n", classnumber + 1);
	printf("%-7s %-7s :", "����", "ѧ��");
	for (i = 0; i < CourseNumber; i++)
		printf("%-8s ", *(Course + i));
	puts("");

	//����ѭ��
	for (i = 0; i < ClassContain[classnumber]; i++)
	{
		temp = (*(Class + classnumber) + i); // tempָ��ǰѧ��
		printf("%-7s %-7s :", temp->name, temp->id);
		//��Ŀѭ��
		for (j = 0; j < CourseNumber; j++)
		{
			tempscore = *(temp->scores + j);

			printf("%-8.1f ", tempscore);
		}
		puts("");
	}
}
void PrintAll() //��ӡȫ�����꼶��()
{
	int i;

	//�༶ѭ��
	for (i = 0; i < ClassTotal; i++)
	{
		PrintAll(i);
	}
}

void Analyze(int classnumber) //���ݷ������༶��
{
	printf("\n%d��:\n", classnumber + 1);
	printf("\n������:%d\n", ClassContain[classnumber]);
	Max(classnumber);
	Min(classnumber);
	Average(classnumber);
	Pass(classnumber);
}
void Analyze() //���ݷ������꼶��
{
	printf("\n������:%d\n", SumGrade());
	Max();
	Min();
	Average();
	Pass();
}

void Max(int classnumber) //��߷֣��༶��
{
	int i, j;
	struct student *temp;
	char id[10], name[10];
	float tempscore;
	float max;

	printf("\n�༶��߷�\n");

	//��Ŀѭ��
	for (i = 0; i < CourseNumber; i++)
	{
		printf(" %s:\n", *(Course + i));

		/*�����ݳ�ʼ��Ϊ��һ��ѧ��*/
		temp = (*(Class + classnumber) + 0); // tempָ���һ��ѧ��
		tempscore = *(temp->scores + i);
		max = tempscore;
		strcpy(id, temp->id);
		strcpy(name, temp->name);

		//����ѭ��
		for (j = 0; j < ClassContain[classnumber]; j++)
		{

			temp = (*(Class + classnumber) + j); // tempָ��ǰѧ��
			tempscore = *(temp->scores + i);	 // tempscoreΪ��ǰѧ���ĳɼ�

			if (max < tempscore)
			{
				max = tempscore;
				strcpy(id, temp->id);
				strcpy(name, temp->name);
			}
		}
		printf("  %4.2f (%s,%s)\n", max, id, name);

		/*����߷��ظ� �ٱ���һ��*/

		char maxid[10]; //����һ��id���ڴ洢��һ�α�����ֵ �����ظ�
		strcpy(maxid, id);

		//����ѭ��
		for (j = 0; j < ClassContain[classnumber]; j++)
		{
			temp = (*(Class + classnumber) + j); // tempָ��ǰѧ��
			tempscore = *(temp->scores + i);	 // tempscoreΪ��ǰѧ���ĳɼ�
			strcpy(id, temp->id);

			if (tempscore == max && strcmp(maxid, id) != 0)
			{
				strcpy(name, temp->name);
				printf("  %4.2f (%s,%s)\n", max, id, name);
			}
		}
	}
}
void Max() //��߷֣��꼶��
{
	int i, j, k;
	struct student *temp;
	float tempscore;

	/*��ӡ����Ϣ*/
	float max;			   //��߷�
	int classnumber;	   //�༶
	char name[10], id[10]; //ѧ��������

	printf("\n�꼶��߷�:\n");

	//��Ŀѭ��
	for (i = 0; i < CourseNumber; i++)
	{
		printf(" %s:\n", *(Course + i));

		classnumber = 0;

		/*�����ݳ�ʼ��Ϊ��һ��ѧ��*/
		temp = (*(Class + classnumber) + 0); //��tempָ���һ��ѧ��
		max = *(temp->scores + i);
		strcpy(name, temp->name);
		strcpy(id, temp->id);

		//�༶ѭ��
		for (j = 0; j < ClassTotal; j++)
		{
			//����ѭ��
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = (*(Class + j) + k);		 // tempָ��ǰѧ��
				tempscore = *(temp->scores + i); // tempscoreΪ��ǰѧ���ĳɼ�
				if (max < tempscore)
				{
					max = tempscore;
					strcpy(name, temp->name);
					strcpy(id, temp->id);
				}
			}
		}

		printf("  %5.1f (%d��,%s,%s)\n", max, classnumber + 1, id, name);

		//����߷��ظ� �ٱ���һ��

		char maxid[10]; //����һ��id���ڴ洢��һ�α�����ֵ �����ظ�
		strcpy(maxid, id);

		//�༶ѭ��
		for (j = 0; j < ClassTotal; j++)
		{
			//����ѭ��
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = (*(Class + j) + k);		 // tempָ��ǰѧ��
				tempscore = *(temp->scores + i); // tempscoreΪ��ǰѧ���ĳɼ�
				strcpy(id, temp->id);

				if (max == tempscore && strcmp(maxid, id) != 0)
				{
					classnumber = j;
					strcpy(name, temp->name);

					printf("  %5.1f (%d��,%s,%s)\n", max, classnumber + 1, id, name);
				}
			}
		}
	}
}
void Min(int classnumber) //��ͷ֣��༶��
{
	int i, j;
	struct student *temp;
	float tempscore;
	float min;

	printf("\n�༶��ͷ�\n");

	//��Ŀѭ��
	for (i = 0; i < CourseNumber; i++)
	{
		temp = (*(Class + classnumber) + 0); // tempָ��ǰѧ��
		tempscore = *(temp->scores + i);	 // tempscoreΪ��ǰѧ���ĳɼ�
		min = tempscore;

		//����ѭ��
		for (j = 0; j < ClassContain[classnumber]; j++)
		{

			temp = (*(Class + classnumber) + j); // tempָ��ǰѧ��
			tempscore = *(temp->scores + i);	 // tempscoreΪ��ǰѧ���ĳɼ�

			if (min > tempscore)
				min = tempscore;
		}

		printf(" %-8s:%4.1f\n", *(Course + i), min);
	}
}
void Min() //��ͷ֣��꼶��
{
	int i, j, k;
	struct student *temp;
	float tempscore;

	/*��ӡ����Ϣ*/
	float min; //��ͷ�

	printf("\n�꼶��ͷ�:\n");

	/*��Ŀѭ��*/
	for (i = 0; i < CourseNumber; i++)
	{

		temp = (*(Class + 0) + 0); //��tempָ���һ��ѧ��

		//�����ݳ�ʼ��Ϊ��һ��ѧ��
		min = *(temp->scores + i);

		/*�༶ѭ��*/
		for (j = 0; j < ClassTotal; j++)
		{
			/*����ѭ��*/
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = (*(Class + j) + k);		 // tempָ��ǰѧ��
				tempscore = *(temp->scores + i); // tempscoreΪ��ǰѧ���ĳɼ�
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
void Average(int classnumber) //ƽ���֣��༶��
{
	int i, j;
	float average;

	printf("\n�༶ƽ����\n");

	//��Ŀѭ��
	for (i = 0; i < CourseNumber; i++)
	{
		average = ClassAverage(classnumber, i);

		printf(" %-8s:%4.2f\n", *(Course + i), average);
	}
}
void Average() //ƽ���֣��꼶��
{

	int i, j, k;
	struct student *temp;
	float tempscore;

	float sum;
	float average;

	printf("\n�꼶ƽ����:\n");

	//��Ŀѭ��
	for (i = 0; i < CourseNumber; i++)
	{
		sum = 0;

		//�༶ѭ��
		for (j = 0; j < ClassTotal; j++)
		{
			sum += ClassAverage(j, i);
		}

		average = sum / ClassTotal;
		printf(" %-8s: %6.2f\n", *(Course + i), average);
	}
}
void Pass(int classnumber) //���������������ʣ��༶��
{
	int i, j;
	struct student *temp;
	float tempscore;

	int count;
	float passpercent;

	printf("\n�༶�������\n", classnumber + 1);

	//��Ŀѭ��
	for (i = 0; i < CourseNumber; i++)
	{
		count = 0;

		//����ѭ��
		for (j = 0; j < ClassContain[classnumber]; j++)
		{
			temp = (*(Class + classnumber)) + j;
			tempscore = *(temp->scores + i);
			if (tempscore >= 60)
				count++;
		}

		passpercent = 100.0 * count / ClassContain[classnumber];

		printf("");
		printf(" %-8s:��������:%d ������:%4.2f%%\n", *(Course + i), count, passpercent);
	}
}
void Pass() //���������������ʣ��꼶��
{
	int i, j, k;
	struct student *temp;
	float tempscore;

	int count;
	float passpercent;

	printf("\n�꼶�������:\n");

	//��Ŀѭ��
	for (i = 0; i < CourseNumber; i++)
	{
		count = 0;
		//�༶ѭ��
		for (j = 0; j < ClassTotal; j++)
		{
			//����ѭ��
			for (k = 0; k < ClassContain[j]; k++)
			{
				temp = *(Class + j) + k;		 // tempָ��ǰѧ��
				tempscore = *(temp->scores + i); // tempΪѧ���ɼ�
				if (tempscore >= 60)
					count++;
			}
		}

		passpercent = 100.0 * count / SumGrade();

		printf(" %-8s:", *(Course + i));
		printf(" ��������:%-2d ������:%6.2f%%\n", count, passpercent);
	}
}

void PrintLowToHigh(int classnumber) //�ӵ͵��ߴ�ӡ���༶��
{
	int i;
	int coursechoose;
	float tempscore;
	struct student *temp;	 //���ڴ������
	struct student *tempstu; //���ڼĴ�ѧ��ָ��

	/*ѡ��γ�*/
	coursechoose = ChooseCourse();

	//���������ڴ�
	temp = (struct student *)malloc(ClassContain[classnumber] * sizeof(struct student));
	//�洢����
	for (i = 0; i < ClassContain[classnumber]; i++)
	{
		tempstu = *(Class + classnumber) + i; // tempstuָ��ǰѧ��
		*(temp + i) = *tempstu;				  //��ѧ�����ݽ���temp
	}

	//������ӵ͵�������
	LowToHigh(temp, coursechoose, ClassContain[classnumber]);

	system("cls");
	printf("%d�� %s\n", classnumber + 1, *(Course + coursechoose));

	printf("%-8s %-8s : �ɼ�\n", "ѧ��", "����");
	//��ӡ
	for (i = 0; i < ClassContain[classnumber]; i++)
	{
		tempstu = temp + i;
		tempscore = *(tempstu->scores + coursechoose);
		printf("%d�� %-8s %-8s : %5.1f\n", tempstu->classnumber, tempstu->id, tempstu->name, tempscore);
	}
}
void PrintLowToHigh() //�ӵ͵��ߴ�ӡ���꼶������
{
	int i, j;
	int coursechoose;
	float tempscore;
	struct student *temp;	 //�洢����
	struct student *tempstu; //��¼��ǰѧ��

	/*ѡ��γ�*/
	coursechoose = ChooseCourse();

	system("cls");

	/*�������*/
	temp = (struct student *)malloc(SumGrade() * sizeof(student)); //�����ڴ�

	int n = 0;
	for (i = 0; i < ClassTotal; i++) //�༶ѭ��
	{
		for (j = 0; j < ClassContain[i]; j++) //����ѭ��
		{
			tempstu = *(Class + i) + j;
			*(temp + n) = *tempstu;
			n++;
		}
	}

	/*��������*/
	LowToHigh(temp, coursechoose, SumGrade());

	/*��ӡ����*/
	printf("%-8s %-8s : �ɼ�\n", "ѧ��", "����");
	for (i = 0; i < SumGrade(); i++)
	{
		tempstu = temp + i;
		tempscore = *(tempstu->scores + coursechoose);
		printf("%d�� %-8s %-8s : %5.1f\n", tempstu->classnumber, tempstu->id, tempstu->name, tempscore);
	}
}

/*��������*/
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
int ChooseCourse() //ѡ��γ�
{
	int i;
	int coursechoose;

	//��ӡ��Ϣ
	printf("ѡ��γ�:\n");
	for (i = 0; i < CourseNumber; i++)
		printf("%d:%s ", i, *(Course + i));
	puts("");
	//��ȡ�γ�
	scanf("%d", &coursechoose);

	return coursechoose;
}
void LowToHigh(struct student *array, int coursenumber, int len) //��һ������Ӹߵ������� �������� ѧ������ָ�� ����γ̱�� ���鳤�ȣ�
{
	//ѡ������
	int i, j, minIndex;
	float min;
	struct student x;

	for (i = 0; i < len; i++)
	{
		min = *(array + i)->scores; //*((array+i)->scores+0)
		minIndex = i;
		//�ҵ���С������
		for (j = i; j < len; j++)
		{
			if (*(array + j)->scores <= min)
			{
				min = *(array + j)->scores;
				minIndex = j;
			}
		}
		//����
		x = *(array + i);
		*(array + i) = *(array + minIndex);
		*(array + minIndex) = x;
	}
}
int SumGrade() //�꼶������
{
	int sum = 0, i;
	for (i = 0; i < ClassTotal; i++)
		sum += ClassContain[i];

	return sum;
}









