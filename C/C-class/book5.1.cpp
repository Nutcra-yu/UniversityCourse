/*�ж����������������Ժ���ż��*/
#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	
	//������
	if(x<0) puts("����");
	else if(x>0) puts("����");
	else puts("0");
	
	//��ż��
	switch(x%2)
	{
		case 1: puts("����"); break; 
		case 0: puts("ż��"); break; 
	}
	
 
}
