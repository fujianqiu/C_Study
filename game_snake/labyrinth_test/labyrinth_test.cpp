// labyrinth_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "wall.h"
#include "node_stack.h"
#include "public.h"
#include "check.h"
#include "time.h"
#include "stdlib.h"
#include<windows.h>
void cls(void)
{
	COORD coordScreen = { 0, 0 };    /* here's where we'll home the
									 cursor */
	BOOL bSuccess;
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
	DWORD dwConSize;                 /* number of character cells in
									 the current buffer */

	/* get the number of character cells in the current buffer */
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	/* fill the entire screen with blanks */

	//bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) 'A',
	//	dwConSize, coordScreen, &cCharsWritten);

	/* get the current text attribute */

	bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);

	/* now set the buffer's attributes accordingly */

	bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten);

	/* put the cursor at (0, 0) */

	bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Stack_Sq *stack;
	MapNode *map;
	coord end_xy ;
	coord start_xy;
	path_node top;
	int index=0;
	end_xy.x = WIDTH - 2;
	end_xy.y = HEIGHT - 2;
	start_xy.x = 1;
	start_xy.y = 1;
	srand(time(NULL));
	CreateEmptyStack(&stack);
	CreateMap(&map);
	CreateWall(map);
	CreateRandomWall(map);
	CreateEND(map, end_xy);

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cci);

	if (CheckEnd(start_xy, map))
	{
		DisplayMap(map);
		getchar();
		return 0;
	}
	if (CheckWalkable(start_xy, map))
	{
		InPath(stack, start_xy);
		UpdataPath(map, start_xy, true);
	}
	do
	{
		cls();
		DisplayMap(map);
		if (GetTop(stack, &top))
		{
			index = CheckRight(top, map, stack);
			if (index == 2)
			{
				break;
			}
			if (index == 1)
				continue;
			index = CheckUp(top, map, stack);
			if (index == 2)
			{
				break;
			}
			if (index == 1)
				continue;
			index = CheckLeft(top, map, stack);
			if (index == 2)
			{
				break;
			}
			if (index == 1)
				continue;
			index = CheckDown(top, map, stack);
			if (index == 2)
			{
				break;
			}
			if (index == 1)
				continue;
			OutPath(stack);
			UpdataPath(map,top.xy, false);
		}
		if (GetTop(stack, &top) == false)
			break;
	} while (1);
	getchar();
	return 0;
}

