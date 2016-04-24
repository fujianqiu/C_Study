// while_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()  //题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
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
	printf("统计个数\n");
	printf("letter:%d\nblank:%d\nfigure:%d\nothers:%d\n", letters, blank, figure, others);
	getchar();
    return 0;
}

