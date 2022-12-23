#pragma once

typedef struct tagRECT
{
	int    left;
	int    top;
	int    right;
	int    bottom;
} RECT;

typedef struct tagPOINT
{
	int  x;
	int  y;
} POINT;

extern void UntileSurface(
	void* pDestination, 
	uint32_t RowPitch, 
	POINT* pPoint, 
	void* pSource, 
	uint32_t Width, 
	uint32_t Height, 
	RECT* pRect, 
	uint32_t TexelPitch);
