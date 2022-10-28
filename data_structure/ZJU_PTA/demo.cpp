#include <stdio.h>
#include <stdlib.h>
typedef int coefficient; //系数
typedef int exponent;    //指数
typedef struct Node *LinkList;
typedef LinkList List;
typedef struct Node
{
    coefficient coe;
    exponent exp;
    struct Node *next;
} node;
List CreatList(List list, int num);
List Multiplication(List l1, List l2, int num1, int num2);
List Add(List l1, List l2, int num2);
int main(void)
{
    //用带头链表
    int m, n; //代表每一多项项式有多少项
    //输入第一个多项式
    scanf("%d", &m);
    getchar();
    List list1 = (node *)malloc(sizeof(node)); //创建list1并指向头结点
    list1->next = NULL;
    CreatList(list1, m);

    //输入第二个多项式
    scanf("%d", &n);
    getchar();
    List list2 = (node *)malloc(sizeof(node)); //创建list2并指向头结点
    list2->next = NULL;
    CreatList(list2, n);

    if (m == 0 && n != 0)
    {
        List p = list2->next;
        printf("0 0\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d %d", p->coe, p->exp);
            if (p->next != NULL)
            {
                printf(" ");
            }
            p = p->next;
        }
    }
    else if (m != 0 && n == 0)
    {
        List p = list1->next;
        printf("0 0\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d %d", p->coe, p->exp);
            if (p->next != NULL)
            {
                printf(" ");
            }
            p = p->next;
        }
    }
    else
    {
        //算相乘
        List mullist, mul;
        mullist = Multiplication(list1, list2, m, n);
        mul = mullist->next;

        //算相加
        List addlist, add;
        addlist = Add(list1, list2, n);
        add = addlist->next;

        while (mul != NULL)
        { //相乘的没有系数为0的情况
            if (mul->coe != 0)
            {
                printf("%d %d", mul->coe, mul->exp);
                if (mul->next != NULL)
                    printf(" ");
            }
            mul = mul->next;
        }
        printf("\n");
        int flag = 1;
        while (add != NULL)
        {
            if (add->coe != 0)
            {
                printf("%d %d", add->coe, add->exp);
                List b = add->next;
                flag = 0;
                if (add->next != NULL && b->coe != 0)
                    printf(" ");
            }
            add = add->next;
        }
        if (flag)
        {
            printf("0 0");
        }
    }

    return 0;
}


//创建两个链表的函数
List CreatList(List list, int num) //指针函数
{
    List temp = list;
    for (int i = 0; i < num; i++)
    {
        temp->next = (node *)malloc(sizeof(node));
        temp = temp->next;
        scanf("%d %d", &(temp->coe), &(temp->exp));
        getchar();
        temp->next = NULL;
    }
    return list; //返回链表的首地址
}

//创建连接相乘的函数
List Multiplication(List l1, List l2, int num1, int num2)
{
    //用第一条连接乘第二条连接
    //第一条链有m项，与第二条链相乘形成m个子链；
    //每个子链里的项的数量由第二条链有n项决定。
    //用指针数组来指向所有子项
    List temp1, temp2, Child[num1];
    temp1 = l1->next;
    temp2 = l2->next;
    //每个子项创建头结点
    for (int i = 0; i < num1; i++)
    {
        Child[i] = (node *)malloc(sizeof(node));
        Child[i]->next = NULL;
    }
    //开始第一条链的每项分别与第二条链所有项相乘
    for (int i = 0; i < num1; i++)
    {
        List tempSon = Child[i];
        temp2 = l2->next;
        for (int j = 0; j < num2; j++)
        {
            tempSon->next = (node *)malloc(sizeof(node));
            tempSon = tempSon->next;
            tempSon->coe = temp1->coe * temp2->coe;
            tempSon->exp = temp1->exp + temp2->exp;
            tempSon->next = NULL;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    //将所有子项相加组成新的链
    //创建合并后的链的头指针并指向头结点
    List temp, multemp;
    int flag;
    List mulLink = (node *)malloc(sizeof(node));
    mulLink->next = Child[0]->next; //将合并链的头结点指向第一个子链
    //将存有第一条子链的合并链与剩下的子链合并
    for (int i = 1; i < num1; i++)
    {
        temp = Child[i]->next;
        for (int j = 0; j < num2; j++)
        {
            multemp = mulLink->next;
            List last = multemp;
            flag = 1;
            while (multemp != NULL)
            {
                if (temp->exp == multemp->exp)
                {
                    multemp->coe = multemp->coe + temp->coe;
                    // Child[i]->next = temp->next;
                    // free(temp);
                    temp = temp->next;
                    last = multemp;
                    multemp = multemp->next;
                    flag = 0;
                    break;
                }
                else if (temp->exp > multemp->exp)
                {
                    Child[i]->next = temp->next;
                    temp->next = multemp;
                    last->next = temp;
                    temp = Child[i]->next;
                    last = multemp;
                    multemp = multemp->next;
                    flag = 0;
                    break;
                }
                else
                {
                    last = multemp;
                    multemp = multemp->next;
                }
            }
            if (flag)
            {
                Child[i]->next = temp;
                last->next = temp;
                temp->next = NULL;
                temp = Child[i]->next;
            }
        }
    }
    return mulLink;
}

//相加函数
List Add(List l1, List l2, int num2)
{
    List addList = (node *)malloc(sizeof(node)); //创建相加后的链表的头指针并指向头结点
    addList->next = l1->next;                    //将第一条链添加到新链中

    List temp2, addtemp, last;
    //第二条链每项分别与新链的所有项比较，指数相等则相加，并对比大小，由大到小排
    for (int i = 0; i < num2; i++)
    {
        temp2 = l2->next;        //让链2的临时指针指向头结点后的第一个
        addtemp = addList->next; //让新链接的临时指针指向头结点后的第一个结点
        last = addList;
        int flag = 1;
        while (addtemp != NULL)
        {
            if (temp2->exp == addtemp->exp)
            {
                addtemp->coe += temp2->coe;
                l2->next = temp2->next;
                // temp2 = l2->next;
                // last = addtemp;
                // addtemp = addtemp->next;
                flag = 0;
                break;
            }
            else if (temp2->exp > addtemp->exp)
            {
                l2->next = temp2->next;
                temp2->next = addtemp;
                last->next = temp2;
                // temp2 = l2->next;
                // last = addtemp;
                // addtemp = addtemp->next;
                flag = 0;
                break;
            }
            else
            {
                last = addtemp;
                addtemp = addtemp->next;
            }
        }
        if (flag)
        {
            l2->next = temp2->next;
            last->next = temp2;
            temp2->next = NULL;
        }
    }
    return addList;
}
