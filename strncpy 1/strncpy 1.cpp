// strncpy 1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>


int main()
{
	char string[10];
	char *str1 = "abcdefghi";
	strncpy(string, str1, 3);
	string[3] = '\0';          //�ַ����������ͼ�鶼������0������
	printf("%s\n", string);
	getchar();
    return 0;
}

