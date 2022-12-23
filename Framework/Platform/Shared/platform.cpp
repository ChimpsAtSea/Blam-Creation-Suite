#include "platform-private-pch.h"

BCS_RESULT init_platform()
{
	HRESULT init_com_library_result = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (FAILED(init_com_library_result))
	{
		return BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT deinit_platform()
{
	CoUninitialize();
	return BCS_S_OK;
}

#define SEGMENT_C_INIT      ".CRT$XIM"
#define SEGMENT_CPP_INIT    ".CRT$XCM"

#pragma data_seg(SEGMENT_C_INIT)
#pragma data_seg(SEGMENT_CPP_INIT)
#pragma data_seg()

static void platform_lastrun();
static void platform_firstrun()
{
	atexit(&platform_lastrun);


}

static void platform_lastrun()
{
	write_memory_allocations();
}

#pragma section(SEGMENT_C_INIT, read)
__declspec(allocate(SEGMENT_C_INIT)) void (*c_init_funcs[])(void) = { &platform_firstrun };
