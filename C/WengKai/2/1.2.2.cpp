#include<stdio.h>
#include<stdlib.h>

int main()
{
	int cnt;
	int *p;
	
	while(p = (int*)malloc(100*1024*1024))
	{
		cnt++;
	}
	printf("������%d00M�Ŀռ�",cnt);
	
	free(NULL);
	free(1);
}
