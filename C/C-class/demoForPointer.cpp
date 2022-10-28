#include <stdio.h>
#include <stdlib.h>
//输出数组元素
void printStrArr(char **arr,int len)
{
	if (arr==NULL||len==0)
	{
		return;
	}
	for (int i = 0; i < len;i++)
	{
		printf("%s\n", *(arr + i));
		//printf("%s\n", arr[i]);
	}
	return;
}

//排序
void sortStrArr(char **arr, int len)
{
	int i = 0, j = 0;
	char *tmp = NULL;
	if (arr == NULL || len == 0)
	{
		return;
	}

	for (i = 0; i < len; i++)
	{
		for (j = i; j < len;j++)
		{
			if (strcmp(arr[i],arr[j])>0)
			{
				//这里交换的式指针的值，不是指针指向的数据。只是改变了数组元素指针的指向
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}



int main(void)
{
	char *strArr[] = { "asdfr", "cccccc", "bnnnn", "322222" };
	int num = 0;

	num = sizeof(strArr) / sizeof(strArr[0]);//求数组中元素个数

	printStrArr(strArr, num);

	sortStrArr(strArr, num);

	printf("\n\n排序之后\n\n");

	printStrArr(strArr, num);


	system("pause");
	return 0;
}

