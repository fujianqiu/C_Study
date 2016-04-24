// Test_22.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//题目：两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。已抽签决定
//比赛名单。有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出
//三队赛手的名单。
int main()
{
	int a = 1, b = 2, c = 3;
	int x, y, z;
	for (x = 1; x <= 3; x++)
	{
		for (y = 1; y <= 3; y++)
		{
			for (z = 1; z <= 3;z++)
			{
				if (a != x&&c != x&&c != z&&x!=y&&x!=z&&y!=z)
				{
					if (a == y) { printf("a-y\n"); }
					if (a == z) { printf("a-z\n"); }
					if (b == x) { printf("a-x\n"); }
					if (b == y) { printf("a-y\n"); }
					if (b == z) { printf("a-z\n"); }
					if (c == y) { printf("c-y\n"); }
				}
			}
		}
	}
	getchar();
    return 0;
}

