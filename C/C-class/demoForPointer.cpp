#include <stdio.h>
#include <stdlib.h>
//�������Ԫ��
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

//����
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
				//���ｻ����ʽָ���ֵ������ָ��ָ������ݡ�ֻ�Ǹı�������Ԫ��ָ���ָ��
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

	num = sizeof(strArr) / sizeof(strArr[0]);//��������Ԫ�ظ���

	printStrArr(strArr, num);

	sortStrArr(strArr, num);

	printf("\n\n����֮��\n\n");

	printStrArr(strArr, num);


	system("pause");
	return 0;
}

