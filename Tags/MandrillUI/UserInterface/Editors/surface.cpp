#include <mandrillui-private-pch.h>

#include <Windows.h>

#include "surface.h"

static long long Log2TexelPitch(unsigned long a1)
{
	return (a1 >> 1 >> (a1 >> 2)) + (a1 >> 2);
}

static long long Log2MicroTileWidth(unsigned long a1)
{
	return 3 - ((a1 >> 2) - (a1 >> 4));
}

static unsigned char* TiledTexelAddress2D(unsigned char* a1, char a2, long a3, long a4, unsigned long a5, unsigned long a6, unsigned long a7, unsigned long a8, unsigned long a9)
{
	long v9; // ecx
	unsigned long v10; // edx

	v9 = a3 << a2;
	v10 = ((8 * ((a4 + (a9 >> 5)) << a2)) >> 2)
		+ 32 * ((a5 + (a9 & 7)) << a2 >> 10)
		+ a6
		+ (((a5 + (a9 & 7)) << a2 >> 6) & 0xF);
	return &a1[2048 * (((unsigned char)a8 + 2 * (((unsigned char)a7 + (unsigned char)(a9 >> 3)) & 3)) & 1)
		+ 256 * (((long)(v10 + v9) >> 6) & 7)
		+ 64 * ((long)(a8 + 2 * (((unsigned char)a7 + (unsigned char)(a9 >> 3)) & 3)) >> 1)
		+ (((unsigned char)v10 + (unsigned char)v9) & 0x3F)
		+ ((8 * (v10 + v9)) & 0xFFFFF000)];
}

static unsigned char* LinearTexelAddress(unsigned char* a1, long a2, long a3, char a4)
{
	return &a1[a2 + (a3 << a4)];
}

// local variable allocation has failed, the output may be wrong!
static void UntileSurface(unsigned char* pDestination, unsigned long RowPitch, POINT* pPoint, void* pSource, unsigned long Width, unsigned long Height, RECT* pRect, unsigned long TexelPitch)
{
	char v8; // al
	unsigned long v9; // [rsp+50h] [rbp-B8h]
	unsigned long v10; // [rsp+54h] [rbp-B4h]
	unsigned long v11; // [rsp+58h] [rbp-B0h]
	long v12; // [rsp+5Ch] [rbp-ACh]
	long v13; // [rsp+60h] [rbp-A8h]
	RECT rect; // [rsp+70h] [rbp-98h] BYREF
	unsigned long i; // [rsp+80h] [rbp-88h]
	unsigned long j; // [rsp+84h] [rbp-84h]
	unsigned char* pTempDestination; // [rsp+88h] [rbp-80h]
	long v18; // [rsp+90h] [rbp-78h]
	unsigned long v19; // [rsp+94h] [rbp-74h]
	unsigned long v20; // [rsp+98h] [rbp-70h]
	void* Src; // [rsp+A0h] [rbp-68h]
	unsigned long v22; // [rsp+A8h] [rbp-60h]
	unsigned long v23; // [rsp+ACh] [rbp-5Ch]
	unsigned long v24; // [rsp+B0h] [rbp-58h]
	unsigned long v25; // [rsp+B4h] [rbp-54h]
	unsigned long v26; // [rsp+B8h] [rbp-50h]
	void* v27; // [rsp+C0h] [rbp-48h]
	unsigned long v28; // [rsp+C8h] [rbp-40h] OVERLAPPED
	unsigned long v29; // [rsp+CCh] [rbp-3Ch]
	unsigned long v30; // [rsp+D0h] [rbp-38h]
	unsigned long v31; // [rsp+D4h] [rbp-34h]
	POINT polong; // [rsp+D8h] [rbp-30h] BYREF
	unsigned long v33; // [rsp+E0h] [rbp-28h]
	unsigned long v34; // [rsp+E4h] [rbp-24h] OVERLAPPED
	unsigned long v35; // [rsp+E8h] [rbp-20h]
	long v36; // [rsp+ECh] [rbp-1Ch]
	unsigned long v37; // [rsp+F0h] [rbp-18h]

	if (!pRect)
	{
		rect.left = 0;
		rect.top = 0;
		rect.right = Width;
		rect.bottom = Height;
		pRect = &rect;
	}
	v9 = pRect->right - pRect->left;
	v24 = pRect->bottom - pRect->top;
	if (!pPoint)
	{
		polong.x = 0;
		polong.y = 0;
		pPoint = &polong;
	}
	ASSERT(pSource);
	ASSERT(pDestination);
	ASSERT(Width <= 8192, "The width of the surface must be less than or equal to 8K texels/blocks.");
	ASSERT(TexelPitch <= 16, "The number of bytes per texel/block of a surface must be less than or equal to 16.");
	ASSERT(((TexelPitch - 1) & TexelPitch) == 0, "The number of bytes per texel/block of a surface must be a power of 2.");
	ASSERT(pRect->right >= pRect->left || pRect->bottom >= pRect->top, "Invalid source rectangle dimensions.");
	ASSERT(pPoint->x >= 0 && pPoint->y >= 0 && TexelPitch * (v9 + pPoint->x) <= RowPitch, "Destination rectangle out of bounds (rectangle must be entirely contained within the destination surface).");

	v20 = (Width + 31) & 0xFFFFFFE0;
	v25 = (Height + 31) & 0xFFFFFFE0;
	if (pSource == pDestination)
	{
		v34 = (TexelPitch * v25 * v20 + 4095) & 0xFFFFF000;
		pTempDestination = (unsigned char*)tracked_malloc(_library_tracked_memory, v34);
		ASSERT(pTempDestination, "Failed to allocate source data buffer for in-place surface untiling.");
		memcpy(pTempDestination, (unsigned char*)pSource, v34);
	}
	else
	{
		pTempDestination = (unsigned char*)pSource;
	}
	v23 = Log2TexelPitch(TexelPitch);
	v35 = TexelPitch >> 1;
	v19 = (TexelPitch >> 2) + (TexelPitch >> 1 >> (TexelPitch >> 2)) + 6;
	v8 = Log2MicroTileWidth(TexelPitch);
	v36 = 1;
	v18 = 1 << v8;
	v10 = (~((1 << v8) - 1) & ((1 << v8) + pRect->left)) - pRect->left;
	v12 = (~((1 << v8) - 1) & (v9 + pRect->left)) - pRect->left;
	if (v10 <= v9)
		v37 = (~((1 << v8) - 1) & ((1 << v8) + pRect->left)) - pRect->left;
	else
		v37 = v9;
	v28 = v37 << v23;
	for (i = 0; i < v24; ++i)
	{
		v31 = i + pRect->top;
		v13 = (v31 >> 3) & 1;
		v30 = (v20 >> 5) * (v31 >> 5);
		v26 = 8 * ((unsigned char)(v31 & 7) >> 1);
		v22 = 16 * (v31 & 1);
		v29 = 2 * v13;
		v11 = (v31 >> 4) & 1;
		v33 = RowPitch * (i + pPoint->y);
		Src = TiledTexelAddress2D(pTempDestination, v19, v13, v30, v26, v22, 2 * v13, v11, pRect->left);
		v27 = LinearTexelAddress(pDestination, v33, pPoint->x, v23);
		memcpy(v27, Src, v28);
		for (j = v10; (long)j < v12; j += v18)
		{
			Src = TiledTexelAddress2D(pTempDestination, v19, v13, v30, v26, v22, v29, v11, j + pRect->left);
			v27 = LinearTexelAddress(pDestination, v33, j + pPoint->x, v23);
			memcpy(v27, Src, (unsigned long)(v18 << v23));
		}
		if (j < v9)
		{
			Src = TiledTexelAddress2D(pTempDestination, v19, v13, v30, v26, v22, v29, v11, j + pRect->left);
			v27 = LinearTexelAddress(pDestination, v33, j + pPoint->x, v23);
			memcpy(v27, Src, (v9 - j) << v23);
		}
	}
	if (pSource == pDestination)
		tracked_free(pTempDestination);
}

void UntileSurface(
	void* pDestination,
	unsigned long RowPitch,
	POINT* pPoint,
	void* pSource,
	unsigned long Width,
	unsigned long Height,
	RECT* pRect,
	unsigned long TexelPitch)
{
	ASSERT(
		!pRect ||
		(pRect->left >= 0 &&
		pRect->top >= 0 &&
		pRect->right <= Width &&
		pRect->bottom <= Height) &&
		Width <= 32 &&
		Height <= 32,
		"Source rectangle out of bounds (rectangle must be entirely contained within the source surface).");
	UntileSurface((unsigned char*)pDestination, RowPitch, pPoint, pSource, Width, Height, pRect, TexelPitch);
}
