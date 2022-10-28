#include<stdio.h>
#include<malloc.h>

struct NODE
	{
		int x;
		struct NODE *next;
	};

NODE *Create_LinkedList();

int main()
{
	
	Create_LinkedList();
	
}

NODE *Create_LinkedList()
{
	NODE *head,*tail; 	//Í·Î²Ö¸Õë 
	NODE *pnew;			//
	
	head = (NODE *)malloc(sizeof(NODE));
	head -> next = NULL;
	tail = head; 
	
	int x;
	while(1)
	{
		scanf("%d",&x);
		if(x<0) break;
		
		pnew = (NODE *)malloc(sizeof(NODE));
		pnew -> x;
	}
}

