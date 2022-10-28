#include<stdio.h>
//右移后的数 
unsigned rrotate(unsigned x,int n)
{
	unsigned rro= x>>n;
	return rro;	
}

//左移后的数 
unsigned lrotate(unsigned x,int n)
{
	unsigned lro= x<<n;
	return lro;	
}

//uint 二进制的位数 
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

//输出一个数的二进制 
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
	printf("非负整数："); 	scanf("%u",&x); 
	printf("移动位数："); 	scanf("%u",&n);
	 
	printf("原 数 :");printf_bits(x);
	printf("\n");
	
	printf("左移后:");printf_bits(lrotate(x,n));
	printf("\n");
	
	printf("右移后:"); printf_bits(rrotate(x,n));
	printf("\n");
}
