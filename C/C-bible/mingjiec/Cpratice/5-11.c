#include<stdio.h>
int main()
{
	int score[6][2];	//6��ѧ�������ſγ�
	int i,j;
	int person[6];
	double aver=0; 
	
	puts("��������������ѧ�������η���");
	for(i=0;i<6;i++)
	{
		printf("��%d��ѧ�������η���\n",i+1);
			scanf("%d",&score[i][0]);
			scanf("%d",&score[i][1]);
		person[i]=(score[i][0]+score[i][1])/2.0;
		//	person[0]=(score[0][0]+score[0][1])/2.0;
		aver += person[i];
	} 
	
	putchar('\n');
	
	for(i=1;i<=6;i++)
	{
		printf("��%d��ѧ����ƽ�����ǣ�%d\n",i,person[i-1]);
	}
	
	printf("ȫ��ͬѧ��ƽ������:%.2lf",aver/6.0);
	
	return 0;
	
}
