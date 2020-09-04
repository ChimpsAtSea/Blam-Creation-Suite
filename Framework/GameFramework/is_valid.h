#pragma once

template<find_offset_func find_offset, typename R, typename ...Args>
inline bool is_valid(const c_function_hook_ex<find_offset, R(Args...)>& functionhookex)
{
	return functionhookex.base != nullptr;
}


template<typename T>
inline bool is_valid(const T& reference)
{
	return &reference != nullptr;
}

//template<typename T>
//bool is_valid(const T* pointer) // banned use 'ptr != nullptr'
//{
//	return pointer != nullptr;
//}


