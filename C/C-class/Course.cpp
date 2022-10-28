#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
	int i, j, k;
	char **Course;	  //存储科目名字
	int CourseNumber; //科目数量

	/*這学期学了多少科目*/
	printf("這学期学了多少科目：");
	scanf("%d", &CourseNumber);
	Course = (char **)malloc(CourseNumber * sizeof(char*));
	
	for (i = 0; i < CourseNumber; i++) {
		printf("第%d门科目是:", i + 1);
		char a[20];
		scanf("%s", a);
		*(Course + i) = (char *)malloc(strlen(a) * sizeof(char));
		strcpy(*(Course + i), a);
	}


	puts("各科成绩：");
	for (k = 0; k < CourseNumber; k++) {
		printf(" %-8s:\n", *(Course + k));
	}
	
//	free(Course);
}
