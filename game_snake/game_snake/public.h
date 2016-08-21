
#ifndef __PUBLIC__H_
#define __PUBLIC__H_
typedef struct
{
	int x;
	int y;
}coordinate;

typedef struct node_s
{
	struct node_s *next;
	coordinate coord;
}node_t;

typedef struct list_s
{
	node_t *head;
	node_t *tail;
	unsigned int number;
}list_t;

#endif
