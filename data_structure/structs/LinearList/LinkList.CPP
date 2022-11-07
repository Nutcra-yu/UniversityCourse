/*���Ա�����ʽ��ʾ*/
#include <iostream>
#include <malloc.h>
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define FALSE 0
#define TRUE 1
#define INFEASIBLE -1
typedef int ElemType;
typedef int Status;
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode, *LinkList;

// bo2-2.cpp ���������Ա�(�洢�ṹ��c2-2.h����)�Ļ�������(12��)

// �������������һ���յ����Ա�L
Status InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode)); // ����ͷ���,��ʹLָ���ͷ���
	if (!L)								 // �洢����ʧ��
		exit(OVERFLOW);
	L->next = NULL; // ָ����Ϊ��
	return OK;
}

// ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L
Status DestroyList(LinkList &L)
{
	LinkList q;
	while (L)
	{
		q = L->next;
		free(L);
		L = q;
	}
	return OK;
}

// ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
Status ClearList(LinkList L)
{
	LinkList p, q;
	p = L->next; // pָ���һ�����
	while (p)
	{ // û����β
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL; // ͷ���ָ����Ϊ��
	return OK;
}

// ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ����򷵻�TRUE�����򷵻�FALSE
Status ListEmpty(LinkList L)
{
	if (L->next) // �ǿ�
		return FALSE;
	else
		return TRUE;
}

// ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next; // pָ���һ�����
	while (p)
	{ // û����β
		i++;
		p = p->next;
	}
	return i;
}

// LΪ��ͷ���ĵ�������ͷָ�롣����i��Ԫ�ش���ʱ,��ֵ����e������OK,���򷵻�ERROR
Status GetElem(LinkList L, int i, ElemType &e)
{
	int j = 1;			  // jΪ������
	LinkList p = L->next; // pָ���һ�����
	while (p && j < i)
	{ // ˳ָ��������,ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next;
		j++;
	}
	if (!p || j > i) // ��i��Ԫ�ز�����
		return ERROR;
	e = p->data; // ȡ��i��Ԫ��
	return OK;

}

//  ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز�����,�򷵻�ֵΪ0
int LocateElem(LinkList L, ElemType e)
{
	// ��ʼ����: ���Ա�L�Ѵ���,compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0)
	// �������:
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e) // �ҵ�����������Ԫ��
			return i;
		p = p->next;
	}
	return 0;
}

// ��cur_e��L������Ԫ��,�Ҳ��ǵ�һ��,����pre_e��������ǰ��,����OK;�������ʧ��,pre_e�޶���,����INFEASIBLE
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
	// ��ʼ����: ���Ա�L�Ѵ���
	// �������:
	LinkList q, p = L->next; // pָ���һ�����
	while (p->next)
	{				 // p��ָ����к��
		q = p->next; // qΪp�ĺ��
		if (q->data == cur_e)
		{
			pre_e = p->data;
			return OK;
		}
		p = q; // p�����
	}
	return INFEASIBLE;
}

// ��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
	// ��ʼ���������Ա�L�Ѵ���
	// ���������
	LinkList p = L->next; // pָ���һ�����
	while (p->next)
	{ // p��ָ����к��
		if (p->data == cur_e)
		{
			next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return INFEASIBLE;
}

// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
Status ListInsert(LinkList &L, int i, ElemType e)
{
	int j = 0;
	LinkList p = L, s;

	while (p && j < i - 1)
	{ // Ѱ�ҵ�i-1�����
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) // iС��1���ߴ��ڱ���
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode)); // �����½��
	s->data = e;						 // ����L��
	s->next = p->next;
	p->next = s;
	return OK;
}

// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i���ڵ��е�Ԫ��,����e������ֵ
Status ListDelete(LinkList L, int i, ElemType &e)
{
	int j = 0;
	LinkList p = L, q;
	while (p->next && j < i - 1)
	{ // Ѱ�ҵ�i�����,����pָ����ǰ��
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1) // ɾ��λ�ò�����
		return ERROR;
	q = p->next; // ɾ�����ͷŽ��
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

// ���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ��
Status ListTraverse(LinkList L, void (*vi)(ElemType))
{
	// vi���β�����ΪElemType����bo2-1.cpp����Ӧ�������β�����ElemType&��ͬ
	// ��ʼ���������Ա�L�Ѵ���
	// �������:
	LinkList p = L->next;
	while (p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}