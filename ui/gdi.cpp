#include "stdafx.h"
#include "gdi.h"
#include <windows.h>
#include <malloc.h>
#include <string.h>

struct gdi_object {
	HWND wnd;
	HDC dc;
	BITMAPINFO bi;
	RGBQUAD pal[2];
};
struct gdi_object * aaa = NULL;
static void gdi_flip(pixel *ptr, int pitch, void *object, int x, int y)
{
	struct gdi_object *obj = (struct gdi_object *)object;
	SetDIBitsToDevice(obj->dc,
		x, y, 640, 480,
		x, 0,
		0, 480,
		ptr-x, &(obj->bi), DIB_RGB_COLORS
		);
}
#if 0
void flip(int xDest,int yDest,DWORD w,DWORD h,  int xSrc,
	 int ySrc,  UINT StartScan,  UINT cLines,CONST VOID * lpvBits)
{
	if (aaa)
	{
		SetDIBitsToDevice(aaa->dc,
			xDest, yDest, w, h,
			xSrc, ySrc,
			StartScan, cLines,
			lpvBits, &(aaa->bi), DIB_RGB_COLORS
			);
	}
}
#endif

void gdi_create(struct gdi *g, void *wnd, int w, int h)
{
	struct gdi_object *obj;
	BITMAPINFOHEADER *bh;
	g->pitch = (w*sizeof(pixel)+3)&(~3);
	g->flip = gdi_flip;
	g->buffer = (pixel*)malloc(h*g->pitch);
	memset(g->buffer, 0, h*g->pitch);
	g->object = obj = aaa = (struct gdi_object *)malloc(sizeof(struct gdi_object));
	g->width = w;
	g->height = h;
	obj->wnd = (HWND)wnd;
	obj->dc = GetDC(obj->wnd);
	bh = &(obj->bi.bmiHeader);
	memset(bh, 0, sizeof(*bh));
	bh->biSize = sizeof(*bh);
	bh->biWidth =g->width;
	bh->biHeight = -480;
	bh->biPlanes = 1;
	bh->biBitCount = sizeof(pixel)* 8;
	bh->biCompression = BI_BITFIELDS;
	*(int*)(obj->bi.bmiColors + 0) = 0xf800 ; //1111 1000 00000000 R   .. 1111 1000 
	*(int*)(obj->bi.bmiColors + 1) = 0x7e0; //      11111100000 G
	*(int*)(obj->bi.bmiColors + 2) = 0x1f; //             11111 B
}

void gdi_release(struct gdi *g)
{
	struct gdi_object *obj = (struct gdi_object *)g->object;
	ReleaseDC(obj->wnd, obj->dc);
	free(g->buffer);
	free(g->object);
}
