#include "opusframework-private-pch.h"

void init_detours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
}

void end_detours()
{
	DetourTransactionCommit();
}

const char* GetDetourResultStr(LONG detourAttachResult)
{
	switch (detourAttachResult)
	{
	case ERROR_INVALID_BLOCK:
		return "ERROR_INVALID_BLOCK";
	case ERROR_INVALID_HANDLE:
		return "ERROR_INVALID_BLOCK";
	case ERROR_INVALID_OPERATION:
		return "ERROR_INVALID_BLOCK";
	case ERROR_NOT_ENOUGH_MEMORY:
		return "ERROR_INVALID_BLOCK";
	case NO_ERROR:
		return "NO_ERROR";
	default:
		return "ERROR_UNKNOWN";
	}
}

void memcpy_virtual(
	const void* dst,
	const void* src,
	size_t size
)
{
	if (dst && src && size)
	{
		DWORD oldProtect;
		VirtualProtect(const_cast<void*>(dst), size, PAGE_EXECUTE_READWRITE, &oldProtect);
		memcpy(const_cast<void*>(dst), src, size);
		VirtualProtect(const_cast<void*>(dst), size, oldProtect, &oldProtect);
	}
	else
	{
		WriteLineVerbose("dst must not be null");
		assert(dst);
	}
}

void nop_address(HaloGameID id, intptr_t offset, size_t count)
{
	char* pBeginning = (char*)GetLoadedHaloModule(id);
	char* pNopAttack = pBeginning + (offset - 0x180000000);

	char nop = 0x90i8;
	for (int i = 0; i < count; i++)
	{
		memcpy_virtual(pNopAttack + i, &nop, 1);
	}
}

void copy_to_address(HaloGameID id, intptr_t offset, void* data, size_t length)
{
	char* pBeginning = (char*)GetLoadedHaloModule(id);
	char* pDataAttack = pBeginning + (offset - 0x180000000);

	memcpy_virtual(pDataAttack, data, length);
}