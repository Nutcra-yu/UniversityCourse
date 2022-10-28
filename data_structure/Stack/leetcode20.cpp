#include <malloc.h>

bool isValid(char *s)
{
    //����ʵ��ջ
    typedef struct
    {
        struct Node *pre;
        char si;
        struct Node *next;
    } Node;

    Node *Stack = (Node *)malloc(sizeof(Node)); //����ջ
    Stack->pre = NULL;
    Node *end = Stack; //����β�˲���

    int i = 1;          // i����s��λ��
    char ch = *(s + i); //��ȡch
    while (ch != '\"')  //�жϲ���
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
        {
            Node *NewNode = (Node *)malloc(sizeof(Node)); //�½��ڵ�
            NewNode->si = ch;                             //�����ַ�
            NewNode->next = NULL;
            end->next = NewNode; //β��nextָ��
            NewNode->pre = end;  //�½�ָ��
            end = end->next;     // end�ƶ�
            break;
        }
        case ')':
        {
            if (end->si == '(')
                end = end->pre; // pop()
            else
                return false;
            break;
        }
        case '}':
        {
            if (end->si == '{')
                end = end->pre;
            else
                return false;
            break;
        }
        case ']':
        {
            if (end->si == '[')
                end = end->pre;
            else
                return false;
            break;
        }
        }
        ch = *(s + ++i); //����ch
    }
    return true;
}