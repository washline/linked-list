#include "LinkStack.h"
#include <stdlib.h>
#include <string.h>

int InitStack(Stack *S)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (!p)
	{
		return FAILURE;
	}
	p->next = NULL;
	
	*S = p;
	
	return SUCCESS;
}

int StackEmpty(const Stack *S)
{
	return (NULL == (*S)->next) ? TRUE : FALSE;
}

int StackLength(const Stack *S)
{
	int i = 0;
	Node *p = (*S)->next;
	
	while (p)
	{
		i++;
		p = p->next;
	}
	
	return i;
}

int Push(Stack *S, ElemType e)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (!p)
	{
		return FAILURE;
	}
	memcpy(&p->data, &e, sizeof(ElemType));
	
	p->next = (*S)->next;
	(*S)->next = p;
	
	
	return SUCCESS;
}

static void InverseLink(Node *head)
{
	Node *p, *pb, *pa;	// pa(after)鎸囧悜鍚庝竴涓粨鐐癸紝pb(before)鎸囧悜鍓嶄竴涓粨鐐?	
	pb = head->next;
	p = pb->next;
	pb->next = NULL;
	while (p)
	{
		pa = p->next;
		p->next = pb;
		pb = p;
		p = pa;
	}
	head->next = pb;
}

void StackTraverse(Stack *S, void (*visit)(ElemType), int flag)
{
	Node *p = (*S)->next;

	if (0 == flag)
	{
		InverseLink((*S));
		p = (*S)->next;
		while (p)
		{
			visit(p->data);
			p = p->next;
		}
		InverseLink((*S));
	}
	else
	{
		while (p)
		{
			visit(p->data);
			p = p->next;
		}
	}
}

int Pop(Stack *S, ElemType *e)
{
	Node *p = (*S)->next;
	if (TRUE == StackEmpty(S))
	{
		return FAILURE;
	}
	
	memcpy(e, &p->data, sizeof(ElemType));
	
	(*S)->next = p->next;
	free(p);
	
	return SUCCESS;
}

void ClearStack(Stack *S)
{
	Node *p = (*S)->next;
	Node *q;
	
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	
	(*S)->next = NULL;
}

void DestroyStack(Stack *S)
{
	ClearStack(S);
	free(*S);
}

/* 鐢╡杩斿洖S鐨勬爤椤舵暟鎹厓绱?*/
int GetTop(const Stack *S, ElemType *e)
{
	if (TRUE == StackEmpty(S))
	{
		return FAILURE;
	}
	
	memcpy(e, &(*S)->next->data, sizeof(ElemType));

	return SUCCESS;
}
