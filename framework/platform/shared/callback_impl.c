#include <stdint.h>
#include "callback.h"

#include "platformspecific/platform-specific-define-platform.h"
#include "base/bcs_api.h"

#ifdef _WIN64
#pragma comment(linker, "/export:??R_callback@@QEAAXZZ=execute_callback_list") // void s_callback::operator()(...)
#pragma comment(linker, "/export:??R_callback@@QEAA_JZZ=execute_callback_list") // intptr_t s_callback::operator()(...)
#else
#pragma comment(linker, "/export:??R_callback@@QAAXZZ=_execute_callback_list") // void s_callback::operator()(...)
#endif

BCS_SHARED_EXPORT intptr_t execute_callback_list(
	s_callback* callback,
	void* arg0,
	void* arg1,
	void* arg2,
	void* arg3,
	void* arg4,
	void* arg5,
	void* arg6,
	void* arg7)
{
	intptr_t result = 0;

	s_callback_entry* entry = callback->entry;
	while (entry)
	{
		intptr_t (*callback_procedure)(void*, ...) = entry->callback;

#define execute_callback()				\
		result = callback_procedure(	\
		arg0, arg1, arg2, arg3,			\
		arg4, arg5, arg6, arg7)
#define execute_userdata_callback(...)				\
		result = callback_procedure(__VA_ARGS__,	\
		arg0, arg1, arg2, arg3,						\
		arg4, arg5, arg6, arg7)

#define userdata entry->userdata

		switch (entry->num_userdata)
		{
			case 0: execute_callback(); break;
			case 1: execute_userdata_callback(userdata[0]); break;
			case 2: execute_userdata_callback(userdata[0], userdata[1]); break;
			case 3: execute_userdata_callback(userdata[0], userdata[1], userdata[2]); break;
			case 4: execute_userdata_callback(userdata[0], userdata[1], userdata[2], userdata[3]); break;
			case 5: execute_userdata_callback(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4]); break;
			case 6: execute_userdata_callback(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4], userdata[5]); break;
			case 7: execute_userdata_callback(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4], userdata[5], userdata[6]); break;
			case 8: execute_userdata_callback(userdata[0], userdata[1], userdata[2], userdata[3], userdata[4], userdata[5], userdata[6], userdata[7]); break;
		}

		entry = entry->next_entry;
	}

#undef execute_callback
#undef userdata

	return result;
}
