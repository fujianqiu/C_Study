// problem set 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int num,n=1;
	int gewei, shiwei, baiwei;
	for (baiwei = 1; baiwei <= 4; baiwei++)
	{
		for (shiwei = 1; shiwei <= 4; shiwei++)
		{
			for (gewei = 1;gewei <= 4; gewei++)
			{
				if (gewei == shiwei||gewei == baiwei||shiwei == baiwei)
				{
					printf("\0");
				}
				else
				{
					num = 100 * baiwei + 10 * shiwei + gewei;
					printf("%d  %d\n", num, n++);
				}
			}
		}
	}
	getchar();
    return 0;
}

