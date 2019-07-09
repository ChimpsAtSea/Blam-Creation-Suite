#include "opus-private-pch.h"



#include <Windows.h>

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