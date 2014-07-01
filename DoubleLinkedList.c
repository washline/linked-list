/**
 * 鍙屽悜寰幆閾捐〃鎿嶄綔鐨勬祴璇? */

#include "DoubleLinkList.h"
#include <stdio.h>

void print(ElemType *e)
{
	printf("%-3d ", *e);
}

void mul2(ElemType *e)
{
	*e *= 2;
}

/* e1鏄『搴忚〃涓殑鍏冪礌 */
int isequal(ElemType e1, ElemType e2)
{
	return (e1 == e2) ? TRUE : FALSE;
}

int main()
{
	List list;	// 瀹氫箟涓€涓嚎鎬ц〃绫诲瀷鐨勫彉閲?	int ret;
	int i;
	ElemType e, pre_e, next_e;

	ret = InitList(&list);	// 鍒濆鍖栫嚎鎬ц〃
	if (FAILURE == ret)
	{
		printf("Init List Fail!\n");
		return -1;
	}

	ret = ListEmpty(&list);
	if (TRUE == ret)
	{
		printf("Current List Empty!\n");
	}
	else
	{
		printf("Current List Not Empty!\n");
	}

	for (i = 0; i < 10; i++)
	{
		ret = ListInsert(&list, i+1, i);
		if (FAILURE == ret)
		{
			printf("Insert %d-th Fail!\n", i+1);
			return -1;
		}
	}

	printf("Current List Length: %d\n", ListLength(&list));	

	ListTraverse(&list, print);
	putchar('\n');

	ListTraverse(&list, mul2);
	
	ListTraverse(&list, print);
	putchar('\n');

	ret = GetElem(&list, 5, &e);
	if (FAILURE == ret)
	{
		printf("Get Element Fail!\n");
		return -1;
	}
	printf("The 5-th element is: %d\n", e);

	i = LocateElem(&list, 14, isequal);
	if (0 == i)
	{
		printf("No Elements equal to 14\n");
	}
	else
	{
		printf("The %d-th is 14\n", i);
	}
	
	i = LocateElem(&list, 24, isequal);
	if (0 == i)
	{
		printf("No Elements equal to 24\n");
	}
	else
	{
		printf("The %d-th is 24\n", i);
	}

	ret = PriorElem(&list, 12, &pre_e);
	if (FAILURE == ret)
	{
		printf("12 has no prior element\n");
	}
	else
	{
		printf("The prior element of 12 is %d: \n", pre_e);
	}

	ret = PriorElem(&list, 0, &pre_e);
	if (FAILURE == ret)
	{
		printf("0 has no prior element\n");
	}
	else
	{
		printf("The prior element of 0 is %d: \n", pre_e);
	}

	ret = NextElem(&list, 12, &next_e);
	if (FAILURE == ret)
	{
		printf("12 has no next element\n");
	}
	else
	{
		printf("The next element of 12 is %d: \n", next_e);
	}

	ret = NextElem(&list, 18, &next_e);
	if (FAILURE == ret)
	{
		printf("18 has no next element\n");
	}
	else
	{
		printf("The next element of 18 is %d: \n", next_e);
	}

	ret = ListDelete(&list, 4, &e);
	if (FAILURE == ret)
	{
		printf("Delete Fail!\n");
	}
	else
	{
		printf("Delete 4-th element, it's value is: %d\n", e);
	}

	ListTraverse(&list, print);
	putchar('\n');

	ClearList(&list);
	ret = ListEmpty(&list);
	if (TRUE == ret)
	{
		printf("Current List Empty!\n");
	}
	else
	{
		printf("Current List Not Empty!\n");
	}

	return 0;
}
