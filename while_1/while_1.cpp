// while_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()  //��Ŀ������һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
{
	int letters = 0; int blank = 0; int figure = 0; int others = 0;
	char A;
	while ((A = getchar()) != '\n')
	{
		if (A >= 'A'&&A <= 'Z' || A >= 'a'&&A <= 'z')
			letters++;
		else if (A >= '0'&&A <= '9')
			figure++;
		else if (A ==' ')
			blank++;
		else others++;
	}
	printf("ͳ�Ƹ���\n");
	printf("letter:%d\nblank:%d\nfigure:%d\nothers:%d\n", letters, blank, figure, others);
	getchar();
    return 0;
}

