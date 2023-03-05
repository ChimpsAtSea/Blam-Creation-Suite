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

#define BCS_FAIL_RETURN_CONDITIONAL_DEBUG_BREAK(expression, should_debug_break) \
	do { \
		BCS_RESULT COMBINE(__bcs_result_, __LINE__) = (expression); \
		if (BCS_FAILED(COMBINE(__bcs_result_, __LINE__))) \
		{ \
			if (should_debug_break) debug_break; \
			return COMBINE(__bcs_result_, __LINE__); \
		} \
	} while (false)

#define BCS_FAIL_RETURN_DEBUG_BREAK(expression) BCS_FAIL_RETURN_CONDITIONAL_DEBUG_BREAK(expression, true)

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

template<typename t_result, typename t_class, typename t_argument>
t_result bcs_result_wrapper_throw(t_class & _class, BCS_RESULT(t_class:: * function)(t_argument result))
{
	t_result result;
	BCS_RESULT bcs_result = (_class.*function)(result);
	if (BCS_FAILED(bcs_result))
	{
		throw bcs_result;
	}
	return result;
}

template<typename t_result, typename t_class, typename t_argument>
t_result bcs_result_wrapper_throw(t_class const& _class, BCS_RESULT(t_class:: * function)(t_argument) const)
{
	t_result result;
	BCS_RESULT bcs_result = (_class.*function)(result);
	if (BCS_FAILED(bcs_result))
	{
		throw bcs_result;
	}
	return result;
}
