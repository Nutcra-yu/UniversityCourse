/*L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
函数Merge要将L1和L2合并为一个非递减的整数序列。
应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/*第一次
List Merge(List L1, List L2)
{
    // // A B 用于存放待操作的下一个元素
    // List A = L1, B = L2;

    // end 用于存放生成链表的末尾
    // L用于记录形成的链表
    List end, L;

    //初始头节点
    if (L1->Data < L2->Data)
    {
        end = L1;
        L = L1;
        L1 = L1->Next;
    }
    else
    {
        end = L2;
        L = L2;
        L2 = L2->Next;
    }

    //进行判定
    while (L1->Next != NULL && L2->Next != NULL)
    {
        if (L1->Data < L2->Data)
        {
            //连接下一个节点
            end->Next = L1;
            // L1递增
            L1 = L1->Next;
            // end指向尾端
            end = end->Next;
        }
        else
        {
            //连接下一个节点
            end->Next = L2;
            // L2递增
            L2 = L2->Next;
            // end指向尾端
            end = end->Next;
        }
    }

    //连接剩下的链表
    if (L1 == NULL)
        end->Next = L2;
    else
        end->Next = L1;

    L1->Next = NULL;
    L2->Next = NULL;

    return L;
}
*/

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    //创建链表
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    PtrToNode end = L;

    PtrToNode A = L1->Next, B = L2->Next;
    while (A && B)
    {
        if (A->Data < B->Data)
        {
            end->Next = A;
            A = A->Next;
        }
        else
        {
            end->Next = B;
            B = B->Next;
        }
        end = end->Next;
    }

    if (A)
        end->Next = A;
    else if (B)
        end->Next = B;
    else
        end->Next = NULL;

    L1->Next = NULL;
    L2->Next = NULL;

    return L;
}
