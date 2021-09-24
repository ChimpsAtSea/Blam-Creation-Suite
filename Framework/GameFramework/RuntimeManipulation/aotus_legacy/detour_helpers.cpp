#include "gameframework-private-pch.h"

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
		return "ERROR_INVALID_HANDLE";
	case ERROR_INVALID_OPERATION:
		return "ERROR_INVALID_OPERATION";
	case ERROR_NOT_ENOUGH_MEMORY:
		return "ERROR_NOT_ENOUGH_MEMORY";
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
		console_write_line("dst must not be null");
		ASSERT(dst != nullptr);
	}
}

void nop_address_legacy(s_engine_platform_build engine_platform_build, intptr_t offset, size_t count)
{
	uintptr_t virtual_base_address;
	ASSERT(BCS_SUCCEEDED(get_engine_base_address(engine_platform_build, &virtual_base_address)));

	void* runtime_base_address;
	ASSERT(BCS_SUCCEEDED(get_engine_runtime_base_address(engine_platform_build, &runtime_base_address)));

	char* pBeginning = (char*)runtime_base_address;
	char* pNopAttack = pBeginning + (offset - virtual_base_address);

	char nop = 0x90i8;
	for (size_t i = 0; i < count; i++)
	{
		memcpy_virtual(pNopAttack + i, &nop, 1);
	}
}

void nop_address(void* pointer, size_t count)
{
	char* pNopAttack = reinterpret_cast<char*>(pointer);

	size_t bytes_written = 0;

	static char nop_data[] = { 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8, 0x90i8 };

	while (bytes_written < count)
	{
		size_t remaining_bytes = count - bytes_written;
		size_t bytes_to_write = __min(remaining_bytes, _countof(nop_data));

		memcpy_virtual(pNopAttack, nop_data, bytes_to_write);

		bytes_written += bytes_to_write;
	}
}

void copy_to_address(void* pointer, void* data, size_t length)
{
	char* pDataAttack = reinterpret_cast<char*>(pointer);
	memcpy_virtual(pDataAttack, data, length);
}