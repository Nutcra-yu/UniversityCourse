#include <malloc.h>

bool isValid(char *s)
{
    //链表实现栈
    typedef struct
    {
        struct Node *pre;
        char si;
        struct Node *next;
    } Node;

    Node *Stack = (Node *)malloc(sizeof(Node)); //建立栈
    Stack->pre = NULL;
    Node *end = Stack; //用于尾端插入

    int i = 1;          // i控制s的位置
    char ch = *(s + i); //获取ch
    while (ch != '\"')  //判断操作
    {
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
        {
            Node *NewNode = (Node *)malloc(sizeof(Node)); //新建节点
            NewNode->si = ch;                             //存入字符
            NewNode->next = NULL;
            end->next = NewNode; //尾端next指向
            NewNode->pre = end;  //新建指向
            end = end->next;     // end移动
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
        ch = *(s + ++i); //更新ch
    }
    return true;
}