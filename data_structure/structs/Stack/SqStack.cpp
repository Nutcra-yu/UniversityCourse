// c3-1.h 栈的顺序存储结构(见图31)

#include <iostream>
#include <malloc.h>
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define INFEASIBLE -1
#define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
#define LIST_INCREMENT 2  // 线性表存储空间的分配增量
typedef int SElemType;
typedef int Status;


#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACK_INCREMENT 2  // 存储空间分配增量
struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top;	 // 栈顶指针
	int stacksize;	 // 当前已分配的存储空间，以元素为单位
};					 // 顺序栈
// bo3-1.cpp 顺序栈(存储结构由c3-1.h定义)的基本操作(9个)
void InitStack(SqStack &S)
{
	// 构造一个空栈S(见图32)
	if (!(S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType))))
		exit(OVERFLOW); // 存储分配失败
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void DestroyStack(SqStack &S)
{
	// 销毁栈S，S不再存在(见图33)
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
}
void ClearStack(SqStack &S)
{
	// 把S置为空栈
	S.top = S.base;
}
Status StackEmpty(SqStack S)
{
	// 若栈S为空栈，则返回TRUE；否则返回FALSE
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}
int StackLength(SqStack S)
{
	// 返回S的元素个数，即栈的长度
	return S.top - S.base;
}
Status GetTop(SqStack S, SElemType &e)
{
	// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top > S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
		return ERROR;
}
void Push(SqStack &S, SElemType e)
{
	// 插入元素e为新的栈顶元素(见图34)
	if (S.top - S.base >= S.stacksize)
	{ // 栈满，追加存储空间
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW); // 存储分配失败
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREMENT;
	}
	*(S.top)++ = e;
}
Status Pop(SqStack &S, SElemType &e)
{
	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；
	// 否则返回ERROR(见图35)
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
void StackTraverse(SqStack S, void (*visit)(SElemType))
{
	// 从栈底到栈顶依次对栈中每个元素调用函数visit()
	while (S.top > S.base)
		visit(*S.base++);
	printf("\n");
}
