#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H

typedef int ElemType;

struct node
{
	// 	ElemType data;
	// 	struct node *next;
	struct node *prior;
};
typedef struct node Node;

typedef struct node * DoubleLinkList;

typedef DoubleLinkList List;

#define  SUCCESS  0
#define  FAILURE -1
#define  TRUE     0
#define  FALSE   -1


extern int InitList(List *L);
extern int ListEmpty(const List *L);
extern int ListLength(const List *L);
extern int ListInsert(List *L, int i, ElemType e);
extern void ListTraverse(List *L, void (*visit)(ElemType *));
extern int GetElem(const List *L, int i, ElemType *e);
extern int LocateElem(const List *L, ElemType e, int (*compare)(ElemType, ElemType));
extern int PriorElem(const List *L, ElemType cur_e, ElemType *pre_e);
extern int NextElem(const List *L, ElemType cur_e, ElemType *next_e);
extern int ListDelete(List *L, int i, ElemType *e);
extern void ClearList(List *L);
extern void DestroyList(List *L);

#endif
