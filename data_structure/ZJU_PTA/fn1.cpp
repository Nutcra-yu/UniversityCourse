#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

Position BinarySearch(List L, ElementType X)
{
    Position low = 1;
    Position mid;
    Position high = L->Last;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (L->Data[mid] < X)
            low = mid;
        else if (L->Data[mid] > X)
            high = mid;
        else
            return mid;
    }
    return NotFound;
}

Position BinarySearch(List L, ElementType X)
{
    Position low = 1, high = L->Last;
    Position mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L->Data[mid] == X)
            return mid;
        else if (L->Data[mid] < X)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return NotFound;
}