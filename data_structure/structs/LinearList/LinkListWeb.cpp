//β�巨��������
#include <stdio.h>
#include <stdlib.h> //���������malloc����
struct LinkList     //�����ṹ��
{
    int data;              //�����������������ݡ�
    struct LinkList *next; //ָ������������������㡣
};
int main(void)
{
    struct LinkList *head = (struct LinkList *)malloc(sizeof(struct LinkList)); //����ͷ��㣬�������ڴ棬��Ҫ���ڴ��С���ǽṹ��Ĵ�С����������mallocǰ����ǿ������ת������struct LinkList*��
    head->next = NULL;                                                          //ͷ���ָ���ʼ��F
    struct LinkList *p;                                                         //����p��� p�����β�巨�����ڼ�¼����β��㣬�����������ʱ��ֻ��Ҫ��p������뼴�ɡ�
    p = head;                                                                   // p���ָ�븳ֵΪͷ���
    int n;                                                                      //���������ȣ������ĸ�����
    printf("�����������ȣ�\n");
    scanf("%d", &n);
    printf("�������ݣ�\n");
    for (int i = 0; i < n; i++) //ѭ���������
    {
        struct LinkList *s = (struct LinkList *)malloc(sizeof(struct LinkList)); //����s��㣬�������ڴ�
        scanf("%d", &s->data);                                                   //��s��㸳ֵ��
                                                                                 //β�巨��������
        p->next = s;                                                             //��Ϊ�����һ��������p��������һ����㣬�����ٲ���ʱӦ�ò���p�ڵ���棬�����β�塣
        s->next = NULL;                                                          //�������ò���β����s����ָ��ָ��NULL��
        p = s;                                                                   // p��㱣��ղŵ�s��㣻�Ա�֤pʼ��Ϊ��������һ���ڵ�
    }                                                                            //���ˣ�����Ĵ����Ѿ�����ˡ�

    p = head;               //��pָ���"ͷ"��ʼ��
    while (p->next != NULL) //���p����һ����㲻ΪNULL��Ҳ����˵���p�����нڵ���ڣ��Ǿ����p�������б�������ݡ�
    {
        printf("%-5d", p->next->data);
        p = p->next; // p������
    }
    printf("\n");
    system("pause");
    return 0;
} //�������������ı��������
