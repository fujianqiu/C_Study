// Test_22.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//��Ŀ������ƹ����ӽ��б������������ˡ��׶�Ϊa,b,c���ˣ��Ҷ�Ϊx,y,z���ˡ��ѳ�ǩ����
//�����������������Ա����������������a˵������x�ȣ�c˵������x,z�ȣ��������ҳ�
//�������ֵ�������
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

