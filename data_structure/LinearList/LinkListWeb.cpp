//尾插法建立链表：
#include <stdio.h>
#include <stdlib.h> //里面包含了malloc函数
struct LinkList     //创建结构体
{
    int data;              //数据域，用来保存数据。
    struct LinkList *next; //指针域，用来连接其他结点。
};
int main(void)
{
    struct LinkList *head = (struct LinkList *)malloc(sizeof(struct LinkList)); //创建头结点，并分配内存，需要的内存大小就是结构体的大小。别忘了在malloc前进行强制类型转换。（struct LinkList*）
    head->next = NULL;                                                          //头结点指针初始化F
    struct LinkList *p;                                                         //创建p结点 p结点在尾插法中用于记录链表尾结点，将来插入结点的时候只需要向p结点后插入即可。
    p = head;                                                                   // p结点指针赋值为头结点
    int n;                                                                      //保存链表长度，即结点的个数。
    printf("请输入链表长度：\n");
    scanf("%d", &n);
    printf("输入数据：\n");
    for (int i = 0; i < n; i++) //循环创建结点
    {
        struct LinkList *s = (struct LinkList *)malloc(sizeof(struct LinkList)); //创建s结点，并分配内存
        scanf("%d", &s->data);                                                   //给s结点赋值。
                                                                                 //尾插法建立链表
        p->next = s;                                                             //因为插完第一个结点后用p保存了上一个结点，所以再插结点时应该插在p节点后面，这就是尾插。
        s->next = NULL;                                                          //别忘了让插在尾部的s结点的指针指向NULL。
        p = s;                                                                   // p结点保存刚才的s结点；以保证p始终为链表的最后一个节点
    }                                                                            //至此，链表的创建已经完成了。

    p = head;               //让p指针从"头"开始。
    while (p->next != NULL) //如果p的下一个结点不为NULL，也就是说如果p结点后还有节点存在，那就输出p后面结点中保存的数据。
    {
        printf("%-5d", p->next->data);
        p = p->next; // p结点后移
    }
    printf("\n");
    system("pause");
    return 0;
} //至此完成了链表的遍历输出。
