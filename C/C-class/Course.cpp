#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
	int i, j, k;
	char **Course;	  //�洢��Ŀ����
	int CourseNumber; //��Ŀ����

	/*�@ѧ��ѧ�˶��ٿ�Ŀ*/
	printf("�@ѧ��ѧ�˶��ٿ�Ŀ��");
	scanf("%d", &CourseNumber);
	Course = (char **)malloc(CourseNumber * sizeof(char*));
	
	for (i = 0; i < CourseNumber; i++) {
		printf("��%d�ſ�Ŀ��:", i + 1);
		char a[20];
		scanf("%s", a);
		*(Course + i) = (char *)malloc(strlen(a) * sizeof(char));
		strcpy(*(Course + i), a);
	}


	puts("���Ƴɼ���");
	for (k = 0; k < CourseNumber; k++) {
		printf(" %-8s:\n", *(Course + k));
	}
	
//	free(Course);
}
