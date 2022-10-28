#include<stdio.h>
//���ƺ���� 
unsigned rrotate(unsigned x,int n)
{
	unsigned rro= x>>n;
	return rro;	
}

//���ƺ���� 
unsigned lrotate(unsigned x,int n)
{
	unsigned lro= x<<n;
	return lro;	
}

//uint �����Ƶ�λ�� 
int count_bits(void)
{
	unsigned int i=~0U;
	int bits=0;
	while(i)
	{
		if(i & 1U) bits++;
		i>>=1;
	}
	return bits;
}

//���һ�����Ķ����� 
int printf_bits(unsigned x)
{
	int i=count_bits();
	for(i -= 1;i>=0;i--)
	{
		printf("%d",(x>>i & 1U));
	}
}

int main()
{
	unsigned int x,n;
	printf("�Ǹ�������"); 	scanf("%u",&x); 
	printf("�ƶ�λ����"); 	scanf("%u",&n);
	 
	printf("ԭ �� :");printf_bits(x);
	printf("\n");
	
	printf("���ƺ�:");printf_bits(lrotate(x,n));
	printf("\n");
	
	printf("���ƺ�:"); printf_bits(rrotate(x,n));
	printf("\n");
}
