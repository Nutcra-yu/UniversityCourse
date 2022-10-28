#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

int i;	
/*
	//初始化一个arr数组
	int arr[10];
	int i;
	for(i=0; i<10; i++)
		arr[i] = i;



	//普通指针
	int *p = arr;
	for(i=0; i<10; i++)
		printf("%d:%d ",arr[i],*(arr+i));

	puts("");

	//数组指针
	int (*pp)[10];
	for(i=0; i<10; i++)
		printf("%d:%d ",arr[i],*arr+i);

	system("cls");
*/
	
//	char (*name1)[10];// == char[10] *name
		

	int number = 3;
	
	char **course;
	
	course = (char**)malloc(number*sizeof(char));
	
	for(i=0;i<number;i++)
	{
		printf("%d门科目是:",i);
		char a[10];
		gets(a);
		*(course+i) = (char*)malloc(strlen(a)* sizeof(char));
		strcpy( *(course+i) , a );
	}
	
	puts("");
	
	for(i=0;i<number;i++)
	{
		printf("%d门科目是:%s\n",i,*(course+i));
	}
	
/*
	char *p = "123456";
	
	p = "4569";
	
	printf("%s",p);
*/
}
