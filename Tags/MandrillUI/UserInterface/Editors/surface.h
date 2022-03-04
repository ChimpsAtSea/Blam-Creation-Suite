#pragma once

typedef struct tagRECT RECT;
typedef struct tagPOINT POINT;

extern void UntileSurface(
	void* pDestination, 
	unsigned long RowPitch, 
	POINT* pPoint, 
	void* pSource, 
	unsigned long Width, 
	unsigned long Height, 
	RECT* pRect, 
	unsigned long TexelPitch);
