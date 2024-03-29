#pragma once

typedef struct _callback_entry s_callback_entry;
typedef struct _callback_entry
{
	void* callback;
	uint32_t num_userdata;
	void* userdata[8];
	s_callback_entry* next_entry;
	uint64_t unique_id;
} s_callback_entry;

#ifdef __cplusplus
typedef struct _callback s_callback;
extern "C" BCS_SHARED intptr_t execute_callback_list(s_callback * callback, ...);

template<typename t_result = void, typename ...t_args>
inline t_result execute_callback_list2(s_callback * callback, t_args ...args)
{
	return reinterpret_cast<t_result(*)(s_callback * callback, ...)>(execute_callback_list)(callback, args...);
}

#endif

typedef struct _callback
{
	s_callback_entry* entry;
} s_callback;

#ifdef __cplusplus

enum t_callback_handle : uint64_t {};

class c_callback :
	protected s_callback
{
public:
	BCS_SHARED c_callback();
	BCS_SHARED ~c_callback();

	template<typename t_result = void, typename ...t_args>
	t_result call(t_args ...args)
	{
		return execute_callback_list2<t_result>(this, args...);
	}

	BCS_SHARED intptr_t operator()(...);

protected:

	BCS_SHARED BCS_RESULT add_callback(void* callback, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, t_callback_handle& callback_handle);
	BCS_SHARED BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, void* userdata7, t_callback_handle& callback_handle);

public:

	template<typename t_type> BCS_RESULT add_callback(t_type* callback, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata, callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata0, void* userdata1, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata0, userdata1, callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata0, void* userdata1, void* userdata2, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata0, userdata1, userdata2, callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata0, userdata1, userdata2, userdata3, callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata0, userdata1, userdata2, userdata3, userdata4, callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata0, userdata1, userdata2, userdata3, userdata4, userdata5, callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata0, userdata1, userdata2, userdata3, userdata4, userdata5, userdata6, callback_handle);
	}
	template<typename t_type> BCS_RESULT add_callback(t_type* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, void* userdata7, t_callback_handle& callback_handle)
	{
		return add_callback(reinterpret_cast<void*>(callback), userdata0, userdata1, userdata2, userdata3, userdata4, userdata5, userdata6, userdata7, callback_handle);
	}

	BCS_SHARED BCS_RESULT remove_callback(t_callback_handle callback_handle);

protected:

	static uint64_t next_unique_id;
};

template<typename T>
using c_typed_callback = c_callback;

#endif
