#pragma once

typedef struct _callback_entry s_callback_entry;
typedef struct _callback_entry
{
	void* callback;
	unsigned long num_userdata;
	void* userdata[8];
	s_callback_entry* next_entry;
	unsigned long long unique_id;
} s_callback_entry;

typedef struct _callback
{
#ifdef __cplusplus
	void operator()(...);
protected:
#endif
	s_callback_entry* entry;
} s_callback;

#ifdef __cplusplus

enum t_callback_handle : unsigned long long {};

class c_callback :
	public s_callback
{
public:
	BCS_DEBUG_API c_callback();
	BCS_DEBUG_API ~c_callback();

	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, t_callback_handle& callback_handle);
	BCS_DEBUG_API BCS_RESULT add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, void* userdata7, t_callback_handle& callback_handle);

	BCS_DEBUG_API BCS_RESULT remove_callback(t_callback_handle callback_handle);

protected:
	static unsigned long long next_unique_id;
};

template<typename T>
using c_typed_callback = c_callback;

#endif
