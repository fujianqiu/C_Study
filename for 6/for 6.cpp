// for 6.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int n;
	for (n = 2; n<=100000; n++)
		if (n % 2 == 1 && n % 3 == 0 && n % 4 == 1 && n % 5 == 4 && n % 6 == 3 && n % 7 == 0 && n % 8 == 1 && n % 9 == 0)
			printf("%d\n", n);
	getchar();
    return 0;
}

