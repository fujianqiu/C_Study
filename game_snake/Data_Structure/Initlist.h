#include "malloc.h"
#define LIST_INIT_SIZE 100
#define LSITINCREMENT 10
typedef struct _elemType{
	struct _elemType *next;
	int data;
}ElemType;
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;