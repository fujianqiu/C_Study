// for 2.cpp : 定义控制台应用程序的入口点。
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
					printf("水仙花数：%d\n", num);
				}
			}
		}
	}
	getchar();
    return 0;
}

