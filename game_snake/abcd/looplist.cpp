#include <stdio.h>
void list(node *head)
{
	if (head == NULL)
	{
		printf("��ѭ��\n");
		return;
	}
	int i = 0;
	int j = 1;
	node *p1, *p2;
	p1 = p2 = head;
	if (head->next == NULL)
	{
		printf("��ѭ��\n");
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
			printf("ѭ��")��
				return;
		}
	}
	printf("��ѭ��")��
		return;
}