// for 2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	int num, a, b, c;
	for (a = 1; a < 10;a++)
	{
		for (b = 0; b < 10; b++)
		{
			for (c = 0; c < 10;c++)
			{
				num = 100 * a + 10 * b + c;
				if (num == a*a*a + b*b*b + c*c*c)
				{
					printf("ˮ�ɻ�����%d\n", num);
				}
			}
		}
	}
	getchar();
    return 0;
}

