/*����һ������ �ж��ܷ�3 5 7���� �����һ����Ϣ֮һ
��ͬʱ��3 5 7 ����
�ܱ���������������
�ܱ�����һ��������
���ܱ���һ������*/

#include<stdio.h>
#include<string.h>
int main()
{
	int x;
	scanf("%d",&x);
	
	//�洢�ܱ����������� 
	int a=0;
	//�洢�ܹ����ļ��������� 
	char b[7]; 
	
	if(x%3 == 0)
	{
		a++;
		strcat(b,"3 ");
	}
	if(x%5 == 0)
	{
		a++;
		strcat(b,"5 ");
	}
	if(x%7 == 0)
	{
		a++;
		strcat(b,"7 ");
	}	
	
	printf("%d �ܱ� %d �������� \n",x,a);
	if(a!=0)
	printf("%d �ܱ� %s����",x,b);
}
