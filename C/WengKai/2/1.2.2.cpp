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
	printf("分配了%d00M的空间",cnt);
	
	free(NULL);
	free(1);
}
