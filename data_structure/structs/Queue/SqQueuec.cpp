// c3-5.h 队列的顺序存储结构(非循环队列,队列头元素在[0]单元)
#define QUEUE_INIT_SIZE 10 // 队列存储空间的初始分配量
#define QUEUE_INCREMENT 2  // 队列存储空间的分配增量
struct SqQueue1(见图319)
{
    QElemType *base; // 初始化的动态分配存储空间
    int rear;        // 尾指针,若队列不空,指向队列尾元素的下一个位置
    int queuesize;   // 当前分配的存储容量(以sizeof(QElemType)为单位)
};
图 320 是根据 c3 - 5.h 定义的有两个元素的
                        非循环顺序队列。
    // bo3-7.cpp 顺序非循环队列(存储结构由c3-5.h定义)的基本操作(9个)
    void
    InitQueue(SqQueue1 &Q)
{ // 构造一个空队列Q(见图321)
    if (!(Q.base = (QElemType *)malloc(QUEUE_INIT_SIZE * sizeof(QElemType))))
        exit(ERROR);               // 存储分配失败
    Q.rear = 0;                    // 空队列，尾指针为0
    Q.queuesize = QUEUE_INIT_SIZE; // 初始存储容量
}
void DestroyQueue(SqQueue1 &Q)
{                 // 销毁队列Q，Q不再存在(见图322)
    free(Q.base); // 释放存储空间
    Q.base = NULL;
    Q.rear = Q.queuesize = 0;
}
void ClearQueue(SqQueue1 &Q)
{ // 将Q清为空队列
    Q.rear = 0;
}
Status QueueEmpty(SqQueue1 Q)
{ // 若队列Q为空队列，则返回TRUE；否则返回FALSE
    if (Q.rear == 0)
        return TRUE;
    else
        return FALSE;
}
int QueueLength(SqQueue1 Q)
{ // 返回Q的元素个数，即队列的长度
    return Q.rear;
}
Status GetHead(SqQueue1 Q, QElemType &e)
{ // 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
    if (Q.rear)
    {
        e = *Q.base;
        return OK;
    }
    else
        return ERROR;
}
void EnQueue(SqQueue1 &Q, QElemType e)
{                              // 插入元素e为Q的新的队尾元素(见图323)
    if (Q.rear == Q.queuesize) // 当前存储空间已满
    {                          // 增加分配
        Q.base = (QElemType *)realloc(Q.base, (Q.queuesize + QUEUE_INCREMENT) * sizeof(QElemType));
        if (!Q.base) // 分配失败
            exit(ERROR);
        Q.queuesize += QUEUE_INCREMENT; // 增加存储容量
    }
    Q.base[Q.rear++] = e; // 入队新元素，队尾指针+1
}
Status DeQueue(SqQueue1 &Q, QElemType &e)
{ // 若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR(见图324)
    int i;
    if (Q.rear) // 队列不空
    {
        e = *Q.base;
        for (i = 1; i < Q.rear; i++)
            Q.base[i - 1] = Q.base[i]; // 依次前移队列元素
        Q.rear--;                      // 尾指针前移
        return OK;
    }
    else
        return ERROR;
}
void QueueTraverse(SqQueue1 Q, void (*vi)(QElemType))
{ // 从队头到队尾依次对队列Q中每个元素调用函数vi()
    int i;
    for (i = 0; i < Q.rear; i++)
        vi(Q.base[i]);
    printf("\n");
}

// main3-7.cpp 检验bo3-7.cpp的主程序
#include "c1.h"
typedef int QElemType;
#include "c3-5.h"
#include "bo3-7.cpp"
void print(QElemType i)
{
    printf("%d ", i);
}
void main()
{
    Status j;
    int i, k = 5;
    QElemType d;
    SqQueue1 Q;
    InitQueue(Q);
    printf("初始化队列后，队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
    for (i = 1; i <= k; i++)
        EnQueue(Q, i); // 依次入队k个元素
    printf("依次入队%d个元素后,队列中的元素为", k);
    QueueTraverse(Q, print);
    printf("队列长度为%d,队列空否？%u(1:空 0:否)\n", QueueLength(Q), QueueEmpty(Q));
    DeQueue(Q, d);
    printf("出队一个元素，其值是%d\n", d);
    j = GetHead(Q, d);
    if (j)
        printf("现在队头元素是%d\n", d);
    ClearQueue(Q);
    printf("清空队列后, 队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
    DestroyQueue(Q);
}