#include "stdafx.h"
#include "Initlist.h"
bool Initlist_Sq(SqList **L)
{
	(*L)->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if ((*L)->elem == NULL)
		return false;
	(*L)->length = 0;
	(*L)->listsize = LIST_INIT_SIZE;
	return true;
}
bool ListInsert_Sq(SqList **L, int i, ElemType e)
{
	if (i<1 || i>(*L)->length + 1)
		return false;
	if ((*L)->length >= LIST_INIT_SIZE)
	{
		(*L)->elem = (ElemType *)realloc((*L)->elem,((*L)->listsize + LSITINCREMENT)*sizeof(ElemType));
		if ((*L)->elem == NULL)
			return false;
		(*L)->listsize += LSITINCREMENT;
	}
	ElemType *q = &((*L)->elem[i - 1]);
	for (ElemType *p = &(*L)->elem[(*L)->length - 1]; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++(*L)->length;
	return true;
}
