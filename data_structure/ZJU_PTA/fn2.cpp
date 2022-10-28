/*L1��L2�Ǹ����Ĵ�ͷ���ĵ���������洢�������ǵ�������ģ�
����MergeҪ��L1��L2�ϲ�Ϊһ���ǵݼ����������С�
Ӧֱ��ʹ��ԭ�����еĽ�㣬���ع鲢��Ĵ�ͷ��������ͷָ�롣*/

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

List Read();        /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲������������NULL */

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

/*��һ��
List Merge(List L1, List L2)
{
    // // A B ���ڴ�Ŵ���������һ��Ԫ��
    // List A = L1, B = L2;

    // end ���ڴ�����������ĩβ
    // L���ڼ�¼�γɵ�����
    List end, L;

    //��ʼͷ�ڵ�
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

    //�����ж�
    while (L1->Next != NULL && L2->Next != NULL)
    {
        if (L1->Data < L2->Data)
        {
            //������һ���ڵ�
            end->Next = L1;
            // L1����
            L1 = L1->Next;
            // endָ��β��
            end = end->Next;
        }
        else
        {
            //������һ���ڵ�
            end->Next = L2;
            // L2����
            L2 = L2->Next;
            // endָ��β��
            end = end->Next;
        }
    }

    //����ʣ�µ�����
    if (L1 == NULL)
        end->Next = L2;
    else
        end->Next = L1;

    L1->Next = NULL;
    L2->Next = NULL;

    return L;
}
*/

/* ��Ĵ��뽫��Ƕ������ */
List Merge(List L1, List L2)
{
    //��������
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
