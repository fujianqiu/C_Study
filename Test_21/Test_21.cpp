// Test_21.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int getPeachNumber(int n)
{
	int num;    //������ʣ������
	if (n == 10)
	{
		return 1;
	}
	else
	{
		num = (getPeachNumber(n + 1) + 1) * 2;
		printf("��%d����ʣ����%d��\n", n, num);//��Ŀ�����ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬����񫣬�ֶ����һ��
	}                                          //�ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ�����Ժ�ÿ�����϶�����ǰһ��ʣ��
	return num;                                //��һ����һ��������10���������ٳ�ʱ����ֻʣ��һ�������ˡ����һ�칲ժ�˶��١�
}
int main()
{
	int num = getPeachNumber(1);
	printf("���ӵ�һ��ժ��:%d�����ӡ�\n", num);
	getchar();
    return 0;
}

