#include "platform-private-pch.h"

BCS_RESULT bcs_result_to_string(BCS_RESULT bcs_result, const char*& bcs_result_string_mb, const wchar_t*& bcs_result_string_wc)
{
#define BCS_RESULT_TO_STRING(bcs_result) case bcs_result: bcs_result_string_mb = #bcs_result; bcs_result_string_wc = L"" #bcs_result; return BCS_S_OK
	switch (bcs_result)
	{
		BCS_RESULT_TO_STRING(BCS_E_NOT_RUN);
		BCS_RESULT_TO_STRING(BCS_E_FILE_NOT_FOUND);
		BCS_RESULT_TO_STRING(BCS_E_OUT_OF_MEMORY);
		BCS_RESULT_TO_STRING(BCS_E_GRAPHICS_HRESULT_ERROR);
		BCS_RESULT_TO_STRING(BCS_E_GRAPHICS_DEVICE_LOST);
		BCS_RESULT_TO_STRING(BCS_E_NOT_SUPPORTED);
		BCS_RESULT_TO_STRING(BCS_E_PROCEDURE_NOT_FOUND);
		BCS_RESULT_TO_STRING(BCS_E_MODULE_NOT_FOUND);
		BCS_RESULT_TO_STRING(BCS_E_CLEANUP_FAIL);
		BCS_RESULT_TO_STRING(BCS_E_COMMAND_LINE_MISSING);
		BCS_RESULT_TO_STRING(BCS_E_DATA_ALREADY_MAPPED);
		BCS_RESULT_TO_STRING(BCS_E_DATA_NOT_MAPPED);
		BCS_RESULT_TO_STRING(BCS_E_MISSING_RESOURCE);
		BCS_RESULT_TO_STRING(BCS_E_FATAL);
		BCS_RESULT_TO_STRING(BCS_E_OUT_OF_RANGE);
		BCS_RESULT_TO_STRING(BCS_E_NOT_FOUND);
		BCS_RESULT_TO_STRING(BCS_E_UNSUPPORTED);
		BCS_RESULT_TO_STRING(BCS_E_NOT_IMPLEMENTED);
		BCS_RESULT_TO_STRING(BCS_E_UNEXPECTED);
		BCS_RESULT_TO_STRING(BCS_E_INVALID_ARGUMENT);
		BCS_RESULT_TO_STRING(BCS_E_FAIL);
		BCS_RESULT_TO_STRING(BCS_S_OK);
		BCS_RESULT_TO_STRING(BCS_S_SEARCH_STOP);
		BCS_RESULT_TO_STRING(BCS_S_NO_CHANGES_MADE);
		BCS_RESULT_TO_STRING(BCS_S_CONTINUE);
		BCS_RESULT_TO_STRING(BCS_S_GRAPHICS_HRESULT_OK);
	}
	return BCS_E_FAIL;
#undef BCS_RESULT_TO_STRING
}

BCS_RESULT bcs_result_to_string_mb(BCS_RESULT bcs_result, const char*& bcs_result_string)
{
	const wchar_t* bcs_result_string_wc;
	return bcs_result_to_string(bcs_result, bcs_result_string, bcs_result_string_wc);
}

BCS_RESULT bcs_result_to_string_wc(BCS_RESULT bcs_result, const wchar_t*& bcs_result_string)
{
	const char* bcs_result_string_mb;
	return bcs_result_to_string(bcs_result, bcs_result_string_mb, bcs_result_string);
}
