// chenfabiao 5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int a,b,c,d;
	for (a = 9; a >= 1; a--)
		{
			for (b = 1; b <= 10; b++)
			{
				if (b < a)
				{
					printf(" ");
				}
				else if (b <= 9)
				{
					c = a*b % 10;
					if (a*b>=10)
					{
						printf("%d", c);
					}
					else
					{
						printf(" ");
					}
				}
				else
				{
					printf("\n");
				}
			}
			for (b = 1; b <= 10; b++)
			{
				if (b<a)
				{
					printf(" ");
				}
				else if (b <= 9)
				{
					c = a*b % 10;
					d = (a*b - c) / 10;
					if (a*b >= 10)
					{
						printf("%d", d);
					}
					else
					{
						printf("%d", c);
					}
				}
				else
				{
					printf("\n");
				}
			}
			for (b = 1; b <= 10; b++)
			{
				if (b<a)
				{
					printf(" ");
				}
				else if (b <= 9)
				{
					printf("=");
				}
				else
				{
					printf("\n");
				}
			}
			for (b = 1; b <= 10; b++)
			{
				if (b<a)
				{
					printf(" ");
				}
				else if (b <= 9)
				{
					printf("%d", a);
				}
				else
				{
					printf("\n");
				}
			}
			for (b = 1; b <= 10; b++)
			{
				if (b<a)
				{
					printf(" ");
				}
				else if (b <= 9)
				{
					printf("*");
				}
				else
				{
					printf("\n");
				}
			}
			for (b = 1; b <= 10; b++)
			{
				if (b<a)
				{
					printf(" ");
				}
				else if (b <= 9)
				{
					printf("%d", b);
				}
				else
				{
					printf("\n");
				}
			}
			printf("\n");
		}
	getchar();
    return 0;
}

