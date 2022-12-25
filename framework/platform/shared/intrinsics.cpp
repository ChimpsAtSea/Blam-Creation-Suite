#include "platform-private-pch.h"

#if defined(BCS_WIN32) || defined(_WIN32)

bool bit_scan_forward32(int32_t* index, int32_t mask)
{
	return _BitScanForward(reinterpret_cast<DWORD*>(index), static_cast<DWORD>(mask));
}

bool bit_scan_forwardu32(uint32_t* index, uint32_t mask)
{
	return _BitScanForward(reinterpret_cast<DWORD*>(index), static_cast<DWORD>(mask));
}

bool bit_scan_reverse32(int32_t* index, int32_t mask)
{
	return _BitScanReverse(reinterpret_cast<DWORD*>(index), static_cast<DWORD>(mask));
}

bool bit_scan_reverseu32(uint32_t* index, uint32_t mask)
{
	return _BitScanReverse(reinterpret_cast<DWORD*>(index), static_cast<DWORD>(mask));
}

bool bit_scan_forward64(int32_t* index, int64_t mask)
{
#ifdef _M_IX86
	return _InlineBitScanForward64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#else
	return _BitScanForward64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#endif
}

bool bit_scan_forwardu64(uint32_t* index, uint64_t mask)
{
#ifdef _M_IX86
	return _InlineBitScanForward64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#else
	return _BitScanForward64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#endif
}

bool bit_scan_reverse64(int32_t* index, int64_t mask)
{
#ifdef _M_IX86
	return _InlineBitScanReverse64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#else
	return _BitScanReverse64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#endif
}

bool bit_scan_reverseu64(uint32_t* index, uint64_t mask)
{
#ifdef _M_IX86
	return _InlineBitScanReverse64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#else
	return _BitScanReverse64(reinterpret_cast<DWORD*>(index), static_cast<DWORD64>(mask));
#endif
}

#endif
