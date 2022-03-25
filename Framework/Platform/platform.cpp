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
