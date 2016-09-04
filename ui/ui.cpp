#include "stdafx.h"
#include <windows.h>
#include "gdi.h"
#include "canvas.h"
#include "box.h"
#include "stdio.h"
#define WIDTH 640
#define HEIGHT 480

struct gdi g_gdi;
struct canvas *g_canvas;
struct box b;
struct box a;
int  i = 0;
HWND hWnd;
HINSTANCE hInst;								// current instance
//BITMAPINFO bi;
BITMAPINFO bi;
char *p = NULL;
ATOM				MyRegisterClass();
BOOL				InitInstance();
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	int i=0;
	MSG msg;

	hInst = GetModuleHandle(0); // Store instance handle in our global variable
	MyRegisterClass();

	if (!InitInstance()) {
		return FALSE;
	}
	b.kx = 0;
	b.ky = 0;
	b.width = 64;
	b.height = 32;
	b.color = 0xfF;
	//b.dirty = DIRTY;
	a.kx = 0;
	a.ky = 0;
	a.width = 100;
	a.height =100;
	a.color = 0xfF;
	a.dirty = DIRTY;
	
	// Main message loop:

	for (;;) 
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) 
		{
			if (!GetMessage(&msg, NULL, 0, 0))
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		{

			//box_draw(g_canvas, &a, 20, 20);
			//canvas_update(g_canvas);
			//Sleep(3300);
			//flip(25, 25, 100,100, 
			//	-50,-50, 
			//	0,100, p);
			//Sleep(3300);
		
#if 0
			SetDIBitsToDevice(GetDC(hWnd),
				0,0,
				465,465,
				0, 0,
				0,400,
				p, &bi, DIB_RGB_COLORS
				);
#endif
		}
	}
	gdi_release(&g_gdi);
	canvas_release(g_canvas);
	return msg.wParam;
}

ATOM MyRegisterClass()
{
	WNDCLASS	wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"TEST";

	return RegisterClass(&wc);
}

BOOL InitInstance()
{
	
	DWORD style = WS_OVERLAPPEDWINDOW&~WS_SIZEBOX&~WS_MAXIMIZEBOX;
	RECT rect = { 0, 0, WIDTH, HEIGHT };
	AdjustWindowRect(&rect, style, FALSE);

	hWnd = CreateWindow(L"TEST", L"test",
		style, CW_USEDEFAULT, 0,
		rect.right - rect.left, rect.bottom - rect.top,
		0, 0, hInst, 0);


	if (!hWnd)
	{
		return FALSE;
	}
	{
		HDC dc = GetDC(hWnd);

#if 0
		FILE * fp = fopen("D:\\11.bmp", "rb+");
		fseek(fp,18L, SEEK_SET);
		unsigned long buffer1[3];
		long buffer2[3];
		unsigned short buffer3[3];
		fread(buffer2, 4, 2, fp);
		long _w = buffer2[0];
		long _h = buffer2[1];
	//	bi = (BITMAPINFO *)malloc(sizeof(BITMAPINFO)-sizeof(BITMAPINFOHEADER)+_w*_h*sizeof(RGBQUAD));
		fseek(fp, -12L, SEEK_CUR);
		fread(buffer1, 4, 1, fp);
		bi.bmiHeader.biSize = buffer1[0];
		fread(buffer2, 4, 2, fp);
		bi.bmiHeader.biWidth = buffer2[0];
		bi.bmiHeader.biHeight =-buffer2[1];
		fread(buffer3, 2, 2, fp);
		bi.bmiHeader.biPlanes = buffer3[0];
		bi.bmiHeader.biBitCount = buffer3[1];
		fread(buffer1, 4, 2, fp);
		bi.bmiHeader.biCompression = buffer1[0];
		bi.bmiHeader.biSizeImage = buffer1[1];
		fread(buffer2, 4, 2, fp);
		bi.bmiHeader.biXPelsPerMeter = buffer2[0];
		bi.bmiHeader.biYPelsPerMeter = buffer2[1];
		fread(buffer1, 4, 2, fp);
		bi.bmiHeader.biClrUsed = buffer1[0];
		bi.bmiHeader.biClrImportant = buffer1[1];
		int temp;
		p = (char *)malloc(_h*((_w * (bi.bmiHeader.biBitCount / 8) + 3)&(~3)));
		fread(p, 1, _h*((_w * (bi.bmiHeader.biBitCount / 8) + 3)&(~3)), fp);
		//p = p +200*((bi.bmiHeader.biWidth * (bi.bmiHeader.biBitCount / 8) + 3)&(~3));
		fclose(fp);
#if 0
		bi.bmiHeader.biSize = buffer1[0];
		fread(buffer2, 4, 2, fp);
		bi.bmiHeader.biWidth = buffer2[0];
		bi.bmiHeader.biHeight = buffer2[1];
		fread(buffer3, 2, 2, fp);
		bi.bmiHeader.biPlanes = buffer3[0];
		bi.bmiHeader.biBitCount = buffer3[1];
		fread(buffer1, 4, 2, fp);
		bi.bmiHeader.biCompression = buffer1[0];
		bi.bmiHeader.biSizeImage = buffer1[1];
		fread(buffer2, 4, 2, fp);
		bi.bmiHeader.biXPelsPerMeter = buffer2[0];
		bi.bmiHeader.biYPelsPerMeter = buffer2[1];
		fread(buffer1, 4, 2, fp);
		bi.bmiHeader.biClrUsed = buffer1[0];
		bi.bmiHeader.biClrImportant = buffer1[1];
#endif
#endif
		
#if 0
		BITMAPINFOHEADER *bh = &(bi->bmiHeader);
		memset(bh, 0, sizeof(*bh));
		bh->biSize = sizeof(*bh);
		bh->biWidth = 100;
		bh->biHeight = -100;
		bh->biPlanes = 1;
		bh->biBitCount = 3* 8;
		bh->biCompression = BI_RGB;
#endif
		//bi.bmiColors[]
		//*(int*)(obj->bi.bmiColors[0].) = 0xf800;
		//*(int*)(obj->bi.bmiColors + 1) = 0x7e0;
	//	*(int*)(obj->bi.bmiColors + 2) = 0x1f;
	}
	gdi_create(&g_gdi, hWnd, WIDTH, HEIGHT);
	g_canvas = canvas_create(g_gdi.width, g_gdi.height, g_gdi.buffer, g_gdi.pitch, g_gdi.flip, g_gdi.object);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		//canvas_redraw(g_canvas);
#if 1
		a.color = 0xaaaa;
		a.dirty = DIRTY;
		box_draw(g_canvas,&a,100+i,100+i);
		canvas_update(g_canvas);
		i+=10;
		//Sleep(10);
		if (i > 380)
			i = -100;
#endif
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
