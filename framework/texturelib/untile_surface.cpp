#include <texturelib-private-pch.h>

static uint32_t Log2TexelPitch(uint32_t a1)
{
	return (a1 >> 1 >> (a1 >> 2)) + (a1 >> 2);
}

static uint32_t Log2MicroTileWidth(uint32_t a1)
{
	return 3 - ((a1 >> 2) - (a1 >> 4));
}

static unsigned char* TiledTexelAddress2D(unsigned char* a1, uint32_t a2, int32_t a3, int32_t a4, uint32_t a5, uint32_t a6, uint32_t a7, uint32_t a8, uint32_t a9)
{
	int32_t v9; // ecx
	uint32_t v10; // edx

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

static unsigned char* LinearTexelAddress(unsigned char* a1, int32_t a2, uint32_t a3, uint32_t a4)
{
	return &a1[a2 + (a3 << a4)];
}

// local variable allocation has failed, the output may be wrong!
static void UntileSurface(unsigned char* pDestination, uint32_t RowPitch, POINT* pPoint, void* pSource, uint32_t Width, uint32_t Height, RECT* pRect, uint32_t TexelPitch)
{
	uint32_t v8; // al
	uint32_t v9; // [rsp+50h] [rbp-B8h]
	uint32_t v10; // [rsp+54h] [rbp-B4h]
	uint32_t v11; // [rsp+58h] [rbp-B0h]
	int32_t v12; // [rsp+5Ch] [rbp-ACh]
	int32_t v13; // [rsp+60h] [rbp-A8h]
	RECT rect; // [rsp+70h] [rbp-98h] BYREF
	uint32_t i; // [rsp+80h] [rbp-88h]
	uint32_t j; // [rsp+84h] [rbp-84h]
	unsigned char* pTempDestination; // [rsp+88h] [rbp-80h]
	int32_t v18; // [rsp+90h] [rbp-78h]
	uint32_t v19; // [rsp+94h] [rbp-74h]
	uint32_t v20; // [rsp+98h] [rbp-70h]
	void* Src; // [rsp+A0h] [rbp-68h]
	uint32_t v22; // [rsp+A8h] [rbp-60h]
	uint32_t v23; // [rsp+ACh] [rbp-5Ch]
	uint32_t v24; // [rsp+B0h] [rbp-58h]
	uint32_t v25; // [rsp+B4h] [rbp-54h]
	uint32_t v26; // [rsp+B8h] [rbp-50h]
	void* v27; // [rsp+C0h] [rbp-48h]
	uint32_t v28; // [rsp+C8h] [rbp-40h] OVERLAPPED
	uint32_t v29; // [rsp+CCh] [rbp-3Ch]
	uint32_t v30; // [rsp+D0h] [rbp-38h]
	uint32_t v31; // [rsp+D4h] [rbp-34h]
	POINT polong; // [rsp+D8h] [rbp-30h] BYREF
	uint32_t v33; // [rsp+E0h] [rbp-28h]
	uint32_t v34; // [rsp+E4h] [rbp-24h] OVERLAPPED
	uint32_t v35; // [rsp+E8h] [rbp-20h]
	int32_t v36; // [rsp+ECh] [rbp-1Ch]
	uint32_t v37; // [rsp+F0h] [rbp-18h]

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
		pTempDestination = (unsigned char*)tracked_malloc(v34);
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
		v33 = RowPitch * (i + static_cast<unsigned long>(pPoint->y));
		Src = TiledTexelAddress2D(pTempDestination, v19, v13, v30, v26, v22, 2 * v13, v11, pRect->left);
		v27 = LinearTexelAddress(pDestination, v33, static_cast<unsigned long>(pPoint->x), v23);
		memcpy(v27, Src, v28);
		for (j = v10; (long)j < v12; j += v18)
		{
			Src = TiledTexelAddress2D(pTempDestination, v19, v13, v30, v26, v22, v29, v11, j + pRect->left);
			v27 = LinearTexelAddress(pDestination, v33, j + static_cast<unsigned long>(pPoint->x), v23);
			memcpy(v27, Src, (unsigned long)(v18 << v23));
		}
		if (j < v9)
		{
			Src = TiledTexelAddress2D(pTempDestination, v19, v13, v30, v26, v22, v29, v11, j + pRect->left);
			v27 = LinearTexelAddress(pDestination, v33, j + static_cast<unsigned long>(pPoint->x), v23);
			memcpy(v27, Src, (v9 - j) << v23);
		}
	}
	if (pSource == pDestination)
		tracked_free(pTempDestination);
}

void UntileSurface(
	void* pDestination,
	uint32_t RowPitch,
	POINT* pPoint,
	void* pSource,
	uint32_t Width,
	uint32_t Height,
	RECT* pRect,
	uint32_t TexelPitch)
{
	ASSERT(
		!pRect ||
		(pRect->left >= 0 &&
		pRect->top >= 0 &&
		pRect->right <= static_cast<int>(Width) &&
		pRect->bottom <= static_cast<int>(Height)) &&
		Width <= 32 &&
		Height <= 32,
		"Source rectangle out of bounds (rectangle must be entirely contained within the source surface).");
	UntileSurface((unsigned char*)pDestination, RowPitch, pPoint, pSource, Width, Height, pRect, TexelPitch);
}
