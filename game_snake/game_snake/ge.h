#ifndef __GE_H__
#define __GE_H__


typedef struct
{
	int width;
	int height;
	int pointSize;
	unsigned char *frameBuf;
}BitmapInfo, *PBitmapInfo;

bool clean_canvas(PBitmapInfo pBitmapHandle);
bool display_canvas(PBitmapInfo pBitmapHandle);
void cls(void);
PBitmapInfo init_ge(unsigned width, unsigned height);
#endif