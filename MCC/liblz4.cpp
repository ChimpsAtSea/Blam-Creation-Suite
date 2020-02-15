#include <Shared\shared-public-pch.h>

//typedef int(__fastcall LZ4_compress_fast_Func)(const char* src, char* dst, int srcSize, int dstCapacity, int acceleration);
//LZ4_compress_fast_Func* LZ4_compress_fast_FuncPtr = nullptr;
//extern "C" __declspec(dllexport) int __fastcall LZ4_compress_fast(const char* src, char* dst, int srcSize, int dstCapacity, int acceleration)
//{
//	//return LZ4_compress_fast_FuncPtr(src, dst, srcSize, dstCapacity, acceleration);
//}
//
//typedef int(__fastcall LZ4_decompress_fast_Func)(const char* src, char* dst, int originalSize);
//LZ4_decompress_fast_Func* LZ4_decompress_fast_FuncPtr = nullptr;
//extern "C" __declspec(dllexport) int __fastcall LZ4_decompress_fast(const char* src, char* dst, int originalSize)
//{
//	//return LZ4_decompress_fast_FuncPtr(src, dst, originalSize);
//}
//
//HMODULE LibLZ4; //SimpleNetworkLibrary-x64-Release.dll

void init_lz4lib()
{
//	LibLZ4 = LoadLibraryA("LibLZ4.dll");
//	assert(LibLZ4);
//
//	LZ4_compress_fast_FuncPtr = (LZ4_compress_fast_Func*)GetProcAddress(LibLZ4, "LZ4_compress_fast");;
//	LZ4_decompress_fast_FuncPtr = (LZ4_decompress_fast_Func*)GetProcAddress(LibLZ4, "LZ4_decompress_fast");
//
//	assert(LZ4_compress_fast_FuncPtr);
//	assert(LZ4_decompress_fast_FuncPtr);
}

void deinit_lz4lib()
{
//	assert(LZ4_compress_fast_FuncPtr);
//	assert(LZ4_decompress_fast_FuncPtr);
//
//	LZ4_compress_fast_FuncPtr = nullptr;
//	LZ4_decompress_fast_FuncPtr = nullptr;
//
//	BOOL freeLibraryResult = FreeLibrary(LibLZ4);
//	assert(freeLibraryResult);
}