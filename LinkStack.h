#ifndef LINKSTACK_H
#define LINKSTACK_H


typedef int ElemType;

struct node
{
	ElemType     data;
	struct node* next;
};

typedef struct node Node;

typedef Node* LinkStack;

typedef LinkStack Stack;

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
