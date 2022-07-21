#pragma once

typedef struct tagRECT RECT;
typedef struct tagPOINT POINT;

extern void UntileSurface(
	void* pDestination, 
	uint32_t RowPitch, 
	POINT* pPoint, 
	void* pSource, 
	uint32_t Width, 
	uint32_t Height, 
	RECT* pRect, 
	uint32_t TexelPitch);
