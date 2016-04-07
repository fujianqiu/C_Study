// problem set 5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int x, y, z, i,b,c,d;
	scanf("%d%d%d", &x, &y, &z);
	int a[3] = { x,y,z };
	for (i = 0; i < 3; i++)
	{
		if (a[i] <= x&&a[i] <= y&&a[i] <= z)
		{
			b = i;
		}
		else if (a[i] >= x&&a[i] >= y&&a[i] >= z)
		{
			c = i;
		}
		else
		{
			d=i;
		}
	}
	printf("%d %d %d",a[b], a[d],a[c]);
	getchar();
	getchar();
    return 0;
}

