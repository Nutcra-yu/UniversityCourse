#include<stdio.h>
void hello(void)
{
	puts("hello");
}

int main(void)
{
	hello(); 	//void函数不用说类型，直接写函数头 
	//hello;	这是不可以的，一定要有括号 
}
