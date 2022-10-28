#include <stdio.h>
#include <stdlib.h>
typedef int coefficient; //ϵ��
typedef int exponent;    //ָ��
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
    //�ô�ͷ����
    int m, n; //����ÿһ������ʽ�ж�����
    //�����һ������ʽ
    scanf("%d", &m);
    getchar();
    List list1 = (node *)malloc(sizeof(node)); //����list1��ָ��ͷ���
    list1->next = NULL;
    CreatList(list1, m);

    //����ڶ�������ʽ
    scanf("%d", &n);
    getchar();
    List list2 = (node *)malloc(sizeof(node)); //����list2��ָ��ͷ���
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
        //�����
        List mullist, mul;
        mullist = Multiplication(list1, list2, m, n);
        mul = mullist->next;

        //�����
        List addlist, add;
        addlist = Add(list1, list2, n);
        add = addlist->next;

        while (mul != NULL)
        { //��˵�û��ϵ��Ϊ0�����
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


//������������ĺ���
List CreatList(List list, int num) //ָ�뺯��
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
    return list; //����������׵�ַ
}

//����������˵ĺ���
List Multiplication(List l1, List l2, int num1, int num2)
{
    //�õ�һ�����ӳ˵ڶ�������
    //��һ������m���ڶ���������γ�m��������
    //ÿ�����������������ɵڶ�������n�������
    //��ָ��������ָ����������
    List temp1, temp2, Child[num1];
    temp1 = l1->next;
    temp2 = l2->next;
    //ÿ�������ͷ���
    for (int i = 0; i < num1; i++)
    {
        Child[i] = (node *)malloc(sizeof(node));
        Child[i]->next = NULL;
    }
    //��ʼ��һ������ÿ��ֱ���ڶ��������������
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

    //�����������������µ���
    //�����ϲ��������ͷָ�벢ָ��ͷ���
    List temp, multemp;
    int flag;
    List mulLink = (node *)malloc(sizeof(node));
    mulLink->next = Child[0]->next; //���ϲ�����ͷ���ָ���һ������
    //�����е�һ�������ĺϲ�����ʣ�µ������ϲ�
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

//��Ӻ���
List Add(List l1, List l2, int num2)
{
    List addList = (node *)malloc(sizeof(node)); //������Ӻ�������ͷָ�벢ָ��ͷ���
    addList->next = l1->next;                    //����һ������ӵ�������

    List temp2, addtemp, last;
    //�ڶ�����ÿ��ֱ���������������Ƚϣ�ָ���������ӣ����Աȴ�С���ɴ�С��
    for (int i = 0; i < num2; i++)
    {
        temp2 = l2->next;        //����2����ʱָ��ָ��ͷ����ĵ�һ��
        addtemp = addList->next; //�������ӵ���ʱָ��ָ��ͷ����ĵ�һ�����
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
