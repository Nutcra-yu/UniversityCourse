#include<stdio.h >

int a(int a)
{
	printf("hello"); 
} 


int main()
{
	//a() 需要int 但是给了double 
	//编译通过 不出错 
	//会自动类型转换 
	a(1.2);
	
	
}
