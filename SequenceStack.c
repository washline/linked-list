#include "SequenceStack.h"
#include <stdlib.h>
#include <string.h>

int InitStack(Stack *S)
{
	S->bottom = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);
	if (!S->bottom)
	{
		return FAILURE;
	}
	
	S->top  = S->bottom;
	S->size = INITSIZE;
	
	return SUCCESS;
}

int StackEmpty(const Stack *S)
{
	return (S->bottom == S->top) ? TRUE : FALSE;
}

int StackLength(const Stack *S)
{
	return S->top - S->bottom;
}

static int StackFull(const Stack *S)
{
	return (S->top - S->bottom == S->size) ? TRUE : FALSE;
}

int Push(Stack *S, ElemType e)
{
	if (TRUE == StackFull(S))
	{
		S->bottom = (ElemType *)realloc(S->bottom, sizeof(ElemType) * (S->size + INCRSIZE));
		if (!S->bottom)
		{
			return FAILURE;
		}
		
		S->top  = S->bottom + S->size;
		S->size += INCRSIZE;
	}
	
	memcpy(S->top, &e, sizeof(ElemType));
	S->top++;
	
	return SUCCESS;
}

void StackTraverse(Stack *S, void (*visit)(ElemType), int flag)
{
	int i;

	if (0 == flag)
	{
		for (i = 0; S->bottom + i < S->top;i++)
		{
			visit(S->bottom[i]);
		}
	}
	else
	{
		for (i = StackLength(S) - 1; i >= 0;i--)
		{
			visit(S->bottom[i]);
		}
	}
}

int Pop(Stack *S, ElemType *e)
{
	if (TRUE == StackEmpty(S))
	{
		return FAILURE;
	}
	
	S->top--;
	memcpy(e, S->top, sizeof(ElemType));
	
	return SUCCESS;
}

void ClearStack(Stack *S)
{
	S->top = S->bottom;
}

void DestroyStack(Stack *S)
{
	free(S->bottom);
	S->bottom = NULL;
	S->top = NULL;
	S->size = 0;
}

/* 鐢╡杩斿洖S鐨勬爤椤舵暟鎹厓绱?*/
int GetTop(const Stack *S, ElemType *e)
{
	if (TRUE == StackEmpty(S))
	{
		return FAILURE;
	}
	
	memcpy(e, S->top-1, sizeof(ElemType));

	return SUCCESS;
}

