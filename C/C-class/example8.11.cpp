#include<stdio.h>

int take[5],n=0; 
int like[5][5] = { {0,0,1,1,0},{1,1,0,0,1},{0,1,1,0,1},{0,0,0,1,0},{0,1,0,0,1} };
int book[5] = {0,0,0,0,0};

void Try(int i);

int main()
{
	Try(0);
	return 0;
}

void Try(int i)
{
	
	int j,k;
	for(j=0;j<=4;j++)
	{
		//iͬѧ�Ƿ�ϲ��j��  
		if(like[i][j]>0 && book[j]==0)
		{
			take[i] = j; // iͬѧ�õ���j�� 
			book[j] = 1; 
			if(i == 4)
			{
				n++;
				printf("======��%d������======\n",n);
				for(k=0;k<=4;k++)
					printf("%d��ָ�%c\n",take[k],'A'+k);
				printf("\n");
			}
			else
				Try(i+1);
			book[j] = 0;
		}
	}
}
