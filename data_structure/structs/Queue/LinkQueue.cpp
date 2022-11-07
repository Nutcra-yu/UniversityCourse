// c3-2.h 单链队列－－队列的链式存储结构
typedef struct QNode // (见图312)
{
    QElemType data;
    QNode *next;
} * QueuePtr;
struct LinkQueue // (见图313)
{
    QueuePtr front, rear; // 队头、队尾指针
};
// bo3-2.cpp 链队列(存储结构由c3-2.h定义)的基本操作(9个)
void InitQueue(LinkQueue &Q)
{ // 构造一个空队列Q(见图315)
    if (!(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))))
        exit(OVERFLOW);
    Q.front->next = NULL;
}
void DestroyQueue(LinkQueue &Q)
{ // 销毁队列Q(无论空否均可)(见图316)
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}
void ClearQueue(LinkQueue &Q)
{ // 将Q清为空队列
    QueuePtr p, q;
    Q.rear = Q.front;
    p = Q.front->next;
    Q.front->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
}
Status QueueEmpty(LinkQueue Q)
{ // 若Q为空队列，则返回TRUE；否则返回FALSE
    if (Q.front->next == NULL)
        return TRUE;
    else
        return FALSE;
}
int QueueLength(LinkQueue Q)
{ // 求队列的长度
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while (Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}
Status GetHead(LinkQueue Q, QElemType &e)
{ // 若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    e = p->data;
    return OK;
}
void EnQueue(LinkQueue &Q, QElemType e)
{ // 插入元素e为Q的新的队尾元素(见图317)
    QueuePtr p;
    if (!(p = (QueuePtr)malloc(sizeof(QNode))))
        // 存储分配失败
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}
Status DeQueue(LinkQueue &Q, QElemType &e)
{ // 若队列不空，删除Q的队头元素，用e返回其值，
    // 并返回OK；否则返回ERROR(见图318)
    QueuePtr p;
    if (Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return OK;
}
void QueueTraverse(LinkQueue Q, void (*vi)(QElemType))
{ // 从队头到队尾依次对队列Q中每个元素调用函数vi()
    QueuePtr p;
    p = Q.front->next;
    while (p)
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}
// main3-2.cpp 检验bo3-2.cpp的主程序
#include "c1.h"
typedef int QElemType;
#include "c3-2.h"
#include "bo3-2.cpp"
void print(QElemType i)
{
    printf("%d ", i);
}
void main()
{
    int i;
    QElemType d;
    LinkQueue q;
    InitQueue(q);
    printf("成功地构造了一个空队列!\n");
    printf("是否空队列？%d(1:空 0:否) ", QueueEmpty(q));
    printf("队列的长度为%d\n", QueueLength(q));
    EnQueue(q, -5);
    EnQueue(q, 5);
    EnQueue(q, 10);
    printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));
    printf("是否空队列？%d(1:空 0:否) ", QueueEmpty(q));
    printf("队列的元素依次为");
    QueueTraverse(q, print);
    i = GetHead(q, d);
    if (i == OK)
        printf("队头元素是：%d\n", d);
    DeQueue(q, d);
    printf("删除了队头元素%d\n", d);
    i = GetHead(q, d);
    if (i == OK)
        printf("新的队头元素是：%d\n", d);
    ClearQueue(q);
    printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
    DestroyQueue(q);
    printf("销毁队列后,q.front=%u q.rear=%u\n", q.front, q.rear);
}