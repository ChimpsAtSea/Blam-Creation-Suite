#pragma once

enum BCS_RESULT
{
	BCS_E_NOT_SUPPORTED = -16,
	BCS_E_PROCEDURE_NOT_FOUND = -15,
	BCS_E_MODULE_NOT_FOUND = -14,
	BCS_E_CLEANUP_FAIL = -13,
	BCS_E_COMMAND_LINE_MISSING = -12,
	BCS_E_DATA_ALREADY_MAPPED = -11,
	BCS_E_DATA_NOT_MAPPED = -10,
	BCS_E_MISSING_RESOURCE = -9,
	BCS_E_FATAL = -8,
	BCS_E_OUT_OF_RANGE = -7,
	BCS_E_NOT_FOUND = -6,
	BCS_E_UNSUPPORTED = -5,
	BCS_E_NOT_IMPLEMENTED = -4,
	BCS_E_UNEXPECTED = -3,
	BCS_E_INVALID_ARGUMENT = -2,
	BCS_E_FAIL = -1,
	BCS_S_OK = 0,
	BCS_S_SEARCH_STOP = 1,
	BCS_S_NO_CHANGES_MADE = 2,
	BCS_S_CONTINUE = 3,
};

BCS_DEBUG_API const char* bcs_result_get_string(BCS_RESULT result);

//#define BCS_VALIDATE_ARGUMENT_THROW(expression) \
//	if(!(expression)) \
//	{ \
//		console_write_line("BCSAPI> %s '" #expression "'", __func__); \
//		throw(BCS_E_INVALID_ARGUMENT); \
//	}
//
//#define BCS_VALIDATE_ARGUMENT(expression) \
//	if(!(expression)) \
//	{ \
//		console_write_line("BCSAPI> %s '" #expression "'", __func__); \
//		return BCS_E_INVALID_ARGUMENT; \
//	}

#define IS_INVALID_BOOLEAN(value) (static_cast<unsigned __int8>(value) > 1ui8)
#define IS_VALID_BOOLEAN(value) (static_cast<unsigned __int8>(value) <= 1ui8)

#define BCS_FAILED(result) (static_cast<BCS_RESULT>(result) < 0)
#define BCS_SUCCEEDED(result) (static_cast<BCS_RESULT>(result) >= 0)

#define BCS_VALIDATE_ARGUMENT_THROW(expression) \
	if(!(expression)) \
	{ \
		throw(BCS_E_INVALID_ARGUMENT); \
	}

#define BCS_VALIDATE_ARGUMENT(expression) \
	if(!(expression)) \
	{ \
		return BCS_E_INVALID_ARGUMENT; \
	}

#define BCS_FAIL_RETURN(expression) \
	do { \
		BCS_RESULT COMBINE(__bcs_result_, __LINE__) = (expression); \
		if (BCS_FAILED(COMBINE(__bcs_result_, __LINE__))) \
		{ \
			return COMBINE(__bcs_result_, __LINE__); \
		} \
	} while (false)

#define BCS_FAIL_THROW(expression) \
	BCS_RESULT COMBINE(__bcs_result_, __LINE__) = (expression); \
	if (BCS_FAILED(COMBINE(__bcs_result_, __LINE__))) \
	{ \
		throw COMBINE(__bcs_result_, __LINE__); \
	}

#define BCS_FAIL_THROW_DBG(expression) \
	BCS_RESULT COMBINE(__bcs_result_, __LINE__) = (expression); \
	if (BCS_FAILED(COMBINE(__bcs_result_, __LINE__))) \
	{ \
		debug_break; \
		throw COMBINE(__bcs_result_, __LINE__); \
	}
