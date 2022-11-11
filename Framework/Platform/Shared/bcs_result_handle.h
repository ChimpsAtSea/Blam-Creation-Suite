#pragma once

BCS_SHARED const char* bcs_result_get_string(BCS_RESULT result);

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
#define BCS_FAILED_CHAIN(previous_result, result) ( BCS_FAILED(previous_result) ? (previous_result) : (result) ) 

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
	do { \
		BCS_RESULT COMBINE(__bcs_result_, __LINE__) = (expression); \
		if (BCS_FAILED(COMBINE(__bcs_result_, __LINE__))) \
		{ \
		throw COMBINE(__bcs_result_, __LINE__); \
		} \
	} while (false)

#define BCS_FAIL_THROW_DBG(expression) \
	do { \
		BCS_RESULT COMBINE(__bcs_result_, __LINE__) = (expression); \
		if (BCS_FAILED(COMBINE(__bcs_result_, __LINE__))) \
		{ \
			debug_break; \
			throw COMBINE(__bcs_result_, __LINE__); \
		} \
	} while (false)
