#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#define INITSIZE 5
#define INCRSIZE 3

typedef int ElemType;

struct SequenceStack
{
	ElemType *bottom;
	ElemType *top;
	int      size;
};

typedef struct SequenceStack Stack;

#define SUCCESS  0
#define FAILURE -1
#define TRUE     0
#define FALSE   -1

extern int InitStack(Stack *S);
extern int StackEmpty(const Stack *S);
extern int StackLength(const Stack *S);
extern int Push(Stack *S, ElemType e);
extern void StackTraverse(Stack *S, void (*visit)(ElemType), int flag);
extern int Pop(Stack *S, ElemType *e);
extern void ClearStack(Stack *S);
extern void DestroyStack(Stack *S);
extern int GetTop(const Stack *S, ElemType *e);

#endif
