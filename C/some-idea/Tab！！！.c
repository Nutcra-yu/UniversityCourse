#include<stdio.h>

int main()
{
	puts("�ҷ����ˣ�����\n"
		 "�����м���tab���Բ����У���Enter�ͻ�\n"
		 "���������ԣ�����Ҫ����������\n"); 
		  
	int i;
	int a[3];
	
	for(i=1;i<=3;i++)
	{
		scanf("%d",&a[i-1]);
	}
	
	putchar('\n');
	puts("come baby\n");
	
	for(i=1;i<=3;i++)
	{
		printf("a[%d]=%d ",i-1,a[i-1]);
	}
	
	return 0;
	
}
