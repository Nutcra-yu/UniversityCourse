#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} * LinkList;

void CreatList(LinkList &head, int n);
void ShowList(LinkList head);

int main()
{
    LinkList a;
    CreatList(a, 10);
    ShowList(a);

    system("pause");
}

void CreatList(LinkList &head, int n)
{
    head = (LinkList)malloc(sizeof(Node));
    LinkList temp = head;
    head->next = NULL;

    int i;
    for (i = 1; i <= n; i++)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = i;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
}
void ShowList(LinkList head)
{
    LinkList temp = head->next;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
