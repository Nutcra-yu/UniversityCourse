/*	����һ������������ÿ����λ��ƽ����	*/

#include<stdio.h>

//���������� 
int SumInt(int a);

int main()
{
	puts("�����Ʋ��ܾ�ȷ��ʾС��������������");
	int a;
	int sum=0;
	
	//��������
	scanf("%d",&a);
	
	//���� 
	sum = SumInt(a);
	
	//������� 
	printf("%d",sum);
}


int SumInt(int a)
{
	int sum = 0;
	
	while(a != 0)
	{
		int i = a % 10;
		sum += i*i;
		a = a / 10; 
	}
	
	return sum;
}

