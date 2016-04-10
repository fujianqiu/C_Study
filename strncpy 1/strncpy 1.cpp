// strncpy 1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>


int main()
{
	char string[10];
	char *str1 = "abcdefghi";
	strncpy(string, str1, 3);
	string[3] = '\0';          //字符串输出输出和检查都是遇到0结束的
	printf("%s\n", string);
	getchar();
    return 0;
}

