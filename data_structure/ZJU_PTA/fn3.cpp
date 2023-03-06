/*本题要求实现给定二叉搜索树的5种常用操作。*/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

//将X插入二叉搜索树BST并返回结果树的根结点指针；
BinTree Insert(BinTree BST, ElementType X);
//将X从二叉搜索树BST中删除，并返回结果树的根结点指针；
//如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
BinTree Delete(BinTree BST, ElementType X);
//在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
Position Find(BinTree BST, ElementType X);
//返回二叉搜索树BST中最小元结点的指针
Position FindMin(BinTree BST);
//返回二叉搜索树BST中最大元结点的指针。
Position FindMax(BinTree BST);

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;
    /*part1*/
    //一个一个读入并创建二叉树
    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");

    /*part2*/
    //寻找最大最小
    MinP = FindMin(BST);
    MaxP = FindMax(BST);

    //寻找读取并判断是否最大最小
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL)
            printf("%d is not found\n", X);
        else
        {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP)
                printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP)
                printf("%d is the largest key\n", Tmp->Data);
        }
    }

    /*part3*/
    //删除元素
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */

BinTree Insert(BinTree BST, ElementType X)
{
    //是否比根节点大(大于等于)
    if (X >= BST->Data)
    {
        //右子树为空 插入
        if (BST->Right == NULL)
        {
            BST->Right = (TNode *)malloc(sizeof(TNode));
            BST->Right->Data = X;
            BST->Right->Left = NULL;
            BST->Right->Right = NULL;
        }
        //右子树不为空 递归
        else
            BST->Right = Insert(BST->Right, X);
    }
    //比根结点小
    else
    {
        //左子树为空 插入
        if (BST->Left == NULL)
        {
            BST->Left = (TNode *)malloc(sizeof(TNode));
            BST->Left->Data = X;
            BST->Left->Left = NULL;
            BST->Left->Right = NULL;
        }
        //左子树不为空 递归
        else
            BST->Left = Insert(BST->Left, X);
    }

    return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
    //找不到
    if (Find(BST, X) == NULL)
    {
        printf("Not Found\n");
        return BST;
    }
    //找到
    else
    {
        if (X.Position->Left != NULL)
        {
        }
    }
}

Position Find(BinTree BST, ElementType X)
{
    Position xPosition = BST;

    //小于结点 搜索左节点
    if (X < BST->Data)
    {
        //左节点为空 找不到 返回空
        if (BST->Left == NULL)
            xPosition = NULL;
        //左节点不为空 递归
        else
            xPosition = Find(BST->Left, X);
    }
    //大于等于结点 搜索右节点
    else if (X >= BST->Data)
    {
        //右节点为空 找不到 返回空
        if (BST->Right == NULL)
            xPosition = NULL;
        //右节点不为空 递归
        else
            xPosition = Find(BST->Right, X);
    }

    //等于
    return xPosition;
}

Position FindMin(BinTree BST)
{
    Position min = BST;
    while (BST->Left != NULL)
        min = BST->Left;
    return min;
}

Position FindMax(BinTree BST)
{
    Position max = BST;
    while (BST->Right != NULL)
        max = BST->Right;
    return max;
}
