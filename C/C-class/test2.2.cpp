/*��������һ����ά���飬�������İ��㡣*/
//���㣺
//�������ĳ������ĳ��ĳ�У��������������е����ֵ��ͬʱҲ�������е���Сֵ��
//��֮�������������е���Сֵ��ͬʱҲ�������е����ֵ��
//�Ը�����������а��㣬Ҳ����û�а��㣬���߲�ֹһ������

#include<stdio.h>
#define ROW 	3
#define COLUMN 	3
int main()
{
	int array[ROW][COLUMN];		//�������� 
	int flag[ROW][COLUMN]={0}; 	//��¼���� 
	
	int i,j;
	for(i=0;i<ROW;i++)
	{
		printf("�����%d�е�%d����: ",i,COLUMN);
		for(j=0;j<COLUMN;j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	
	int min,max;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			/*�ж�һ�����ǲ��Ǹ��е����ֵ*/
			int k,flagmax=1;
			for(k=0;k<COLUMN;k++) 
			{
				if(j!=k && array[i][j]<array[i][k]) flagmax=0;//�������ֵ 
			}
			if(flagmax == 1)//�����ֵ 
			{
				/*�ж�һ�����ǲ��Ǹ��е���Сֵ*/
				int flagmin = 1;
				for(k=0;k<ROW;k++)
				{
					if(i!=k && array[i][j]>array[k][j]) flagmin=0;
				}
					/*��¼����*/
				if(flagmin == 1) flag[i][j] = 1;
			}
		}
	}
	//�ж�һ�����ǲ��Ǹ��е���Сֵ
		//�ж�һ�����ǲ��Ǹ��е����ֵ
			//��¼����
			
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			/*�ж�һ�����ǲ��Ǹ��е���Сֵ*/
			int k,flagmin=1;
			for(k=0;k<COLUMN;k++) 
			{
				if(j!=k && array[i][j]>array[i][k]) flagmin=0;//������Сֵ 
			}
			if(flagmin == 1)//����Сֵ 
			{
				/*�ж�һ�����ǲ��Ǹ��е����ֵ*/
				int flagmax = 1;
				for(k=0;k<ROW;k++)
				{
					if(i!=k && array[i][j]<array[k][j]) flagmax=0;
				}
					/*��¼����*/
				if(flagmax == 1) flag[i][j] = 1;
			}
		}
	}
				
	//��ӡ��������
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			if(flag[i][j] == 1) 	printf("%-5d",array[i][j]);
			else				printf("NOT  ");
		}
		puts("");
	}
}





