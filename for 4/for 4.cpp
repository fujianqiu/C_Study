// for 4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*��Ŀ����һ���������ֽ������������磺����90,��ӡ��90=2*3*3*5��*/

int main()
{
	int n, k;
	scanf("%d", &n);
	printf("%d=",n);
	loop:for (k = 2; k < n; k++)
		if (n%k == 0)
		{
			n = n / k;
			printf("%d*",k);
			goto loop;
		}
	printf("%d",n);
	getchar();
	getchar();
    return 0;
}

