// bo3-5.cpp 链栈(存储结构由c2-2.h定义)的基本操作(4个)
// 部分基本操作是由bo2-8.cpp中的函数改名得来
// 另一部分基本操作是由调用bo2-8.cpp中的函数(取特例)得来
typedef SElemType ElemType; // 栈结点类型和链表结点类型一致
#include "LinkList.cpp"     // 单链表存储结构
typedef LinkList LinkStack; // LinkStack是指向栈结点的指针类型
#define InitStack InitList  // InitStack()与InitList()作用相同，下同
#define DestroyStack DestroyList
#define ClearStack ClearList
#define StackEmpty ListEmpty
#define StackLength ListLength
// #include"bo2-8.cpp" // 无头结点单链表的基本操作
Status GetTop(LinkStack S, SElemType &e)
{ // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    return GetElem(S, 1, e);
}
Status Push(LinkStack &S, SElemType e)
{ // 插入元素e为新的栈顶元素
    return ListInsert(S, 1, e);
}
Status Pop(LinkStack &S, SElemType &e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    return ListDelete(S, 1, e);
}
void StackTraverse(LinkStack S, void (*visit)(SElemType))
{                          // 从栈底到栈顶依次对栈中每个元素调用函数visit()
    LinkStack temp, p = S; // p指向栈顶元素
    InitStack(temp);       // 初始化临时栈temp
    while (p)
    {
        Push(temp, p->data); // 由S栈顶到栈底，依次将栈元素入栈到temp栈
        p = p->next;
    }
    ListTraverse(temp, visit); // 遍历temp线性表
}

// main3-5.cpp 检验bo3-5.cpp的主程序
#include "c1.h"
typedef int SElemType; // 定义栈元素的类型
#include "bo3-5.cpp"
void print(SElemType c)
{
    printf("%d ", c);
}
void main()
{
    int j;
    LinkStack s;
    SElemType e;
    InitStack(s);            // 初始化栈s
    for (j = 1; j <= 5; j++) // 将2,4,6,8,10入栈
        Push(s, 2 * j);
    printf("栈中的元素从栈底到栈顶依次为");
    StackTraverse(s, print);
    Pop(s, e);
    printf("弹出的栈顶元素为%d\n", e);
    printf("栈空否: %d(1:空 0:否)\n", StackEmpty(s));
    GetTop(s, e);
    printf("当前栈顶元素为%d，栈的长度为%d\n", e, StackLength(s));
    ClearStack(s);
    printf("清空栈后，栈空否: %d(1:空 0:否)，栈的长度为%d\n", StackEmpty(s), StackLength(s));
    DestroyStack(s);
}