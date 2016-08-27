#include <stdio.h>
void list(node *head)
{
	if (head == NULL)
	{
		printf("不循环\n");
		return;
	}
	int i = 0;
	int j = 1;
	node *p1, *p2;
	p1 = p2 = head;
	if (head->next == NULL)
	{
		printf("不循环\n");
		return;
	}
	p1 = p1->next;
	while (p1)
	{
		p1 = p1->next;
		i = j - i;
		if (i)
		{
			p2 = p2->next;
		}
		if (p1 == p2)
		{
			printf("循环")；
				return;
		}
	}
	printf("不循环")；
		return;
}