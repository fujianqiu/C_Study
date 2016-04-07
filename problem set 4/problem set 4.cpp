// problem set 4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int n;
	int y;
	int r;
	int s;
	int l;
	printf("please input year,month,day\n");
	scanf("%d%d%d",&n,&y,&r);
	switch(y)
	{
	case 1:s = 0; break;
	case 2:s = 31; break;
	case 3:s = 59; break;
	case 4:s = 90; break;
	case 5:s = 120; break;
	case 6:s = 151; break;
	case 7:s = 181; break;
	case 8:s = 212; break;
	case 9:s = 243; break;
	case 10:s = 273; break;
	case 11:s = 304; break;
	case 12:s = 334; break;
	default:printf("data error"); break;
	}
   if (n % 400 == 0||(n%4==0&&n%100!=0))
	{
		if (y < 3)
		{
			l=0;
		}
		else
		{
			l=1;
		}
	}
	else
	{
			l=0;
	}
	
	s = s + r+l;
	printf("今天是今年的第%d天", s);
	getchar();
	getchar();
    return 0;
}

