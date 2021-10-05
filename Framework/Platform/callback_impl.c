#include "callback.h"

#ifdef _WIN64
#pragma comment(linker, "/export:??R_callback@@QEAAXZZ=execute_callback_list") // s_callback::operator()(...)
#else
#pragma comment(linker, "/export:??R_callback@@QAAXZZ=_execute_callback_list") // s_callback::operator()(...)
#endif

void execute_callback_list(
	s_callback* callback_manager,
	unsigned long long register1,
	unsigned long long register2,
	unsigned long long register3,
	unsigned long long stack)
{
	s_callback_entry* entry = callback_manager->entry;
	while (entry)
	{
		void(*callback)() = entry->callback;

#define execute_callback()										\
		callback(												\
		register1, register2, register3, (&stack)[0], 			\
		(&stack)[1], (&stack)[2], (&stack)[3], (&stack)[4],		\
		(&stack)[5], (&stack)[6], (&stack)[7], (&stack)[8],		\
		(&stack)[9], (&stack)[10], (&stack)[11], (&stack)[12])
#define execute_userdata_callback(...)							\
		callback(__VA_ARGS__, 									\
		register1, register2, register3, (&stack)[0], 			\
		(&stack)[1], (&stack)[2], (&stack)[3], (&stack)[4],		\
		(&stack)[5], (&stack)[6], (&stack)[7], (&stack)[8],		\
		(&stack)[9], (&stack)[10], (&stack)[11], (&stack)[12])

#define userdata entry->userdata

		switch (entry->num_userdata)
		{
		case 0: execute_callback(); break;
		case 1: execute_userdata_callback(userdata[0]); break;
		case 2: execute_userdata_callback(userdata[0], userdata[0]); break;
		case 3: execute_userdata_callback(userdata[0], userdata[0], userdata[0]); break;
		case 4: execute_userdata_callback(userdata[0], userdata[0], userdata[0], userdata[0]); break;
		case 5: execute_userdata_callback(userdata[0], userdata[0], userdata[0], userdata[0], userdata[0]); break;
		case 6: execute_userdata_callback(userdata[0], userdata[0], userdata[0], userdata[0], userdata[0], userdata[0]); break;
		case 7: execute_userdata_callback(userdata[0], userdata[0], userdata[0], userdata[0], userdata[0], userdata[0], userdata[0]); break;
		case 8: execute_userdata_callback(userdata[0], userdata[0], userdata[0], userdata[0], userdata[0], userdata[0], userdata[0], userdata[0]); break;
		}

		entry = entry->next_entry;
	}

#undef execute_callback
#undef userdata
}

