#include "platform-private-pch.h"

uint64_t c_callback::next_unique_id = 1;

intptr_t s_callback::operator()(...)
{
	throw; // #TODO: Make this function naked
#ifdef __clang__
#if defined(__x86_64__) || defined(_M_X64)
	//x86_64
	__asm__("jmp %0" : : "r"(execute_callback_list));
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
	//x86_32
	__asm__("jmp %0" : : "r"(execute_callback_list));
#elif defined(__ARM_ARCH_2__)
	#error ARM2 Unsupported
#elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
	#error ARM3 Unsupported
#elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
	#error ARM4T Unsupported
#elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
	#error ARM5 Unsupported
#elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
	#error ARM6T2 Unsupported
#elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
	#error ARM6 Unsupported
#elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	// ARM7
	__asm__("bx %0" : : "r"(execute_callback_list));
#elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	#error ARM7A Unsupported
#elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	#error ARM7R Unsupported
#elif defined(__ARM_ARCH_7M__)
	#error ARM7M Unsupported
#elif defined(__ARM_ARCH_7S__)
	#error ARM7S Unsupported
#elif defined(__aarch64__) || defined(_M_ARM64)
	// ARM64
	__asm__("bx %0" : : "r"(execute_callback_list));
#elif defined(mips) || defined(__mips__) || defined(__mips)
	#error MIPS Unsupported
#elif defined(__sh__)
	#error SUPERH Unsupported
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
	#error POWERPC Unsupported
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
	#error POWERPC64 Unsupported
#elif defined(__sparc__) || defined(__sparc)
	#error SPARC Unsupported
#elif defined(__m68k__)
	#error M68K Unsupported
#else
	#error UNKNOWN Unsupported
#endif
#else

#endif
}

c_callback::c_callback() :
	s_callback()
{

}

c_callback::~c_callback()
{
	while (entry)
	{
		s_callback_entry* next_entry = entry->next_entry;
		delete entry;
		entry = next_entry;
	}
}

BCS_RESULT c_callback::add_callback(void* callback, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 0;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 1;
	new_entry->userdata[0] = userdata;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata0, void* userdata1, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 2;
	new_entry->userdata[0] = userdata0;
	new_entry->userdata[1] = userdata1;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 3;
	new_entry->userdata[0] = userdata0;
	new_entry->userdata[1] = userdata1;
	new_entry->userdata[2] = userdata2;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 4;
	new_entry->userdata[0] = userdata0;
	new_entry->userdata[1] = userdata1;
	new_entry->userdata[2] = userdata2;
	new_entry->userdata[3] = userdata3;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 5;
	new_entry->userdata[0] = userdata0;
	new_entry->userdata[1] = userdata1;
	new_entry->userdata[2] = userdata2;
	new_entry->userdata[3] = userdata3;
	new_entry->userdata[4] = userdata4;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 6;
	new_entry->userdata[0] = userdata0;
	new_entry->userdata[1] = userdata1;
	new_entry->userdata[2] = userdata2;
	new_entry->userdata[3] = userdata3;
	new_entry->userdata[4] = userdata4;
	new_entry->userdata[5] = userdata5;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 7;
	new_entry->userdata[0] = userdata0;
	new_entry->userdata[1] = userdata1;
	new_entry->userdata[2] = userdata2;
	new_entry->userdata[3] = userdata3;
	new_entry->userdata[4] = userdata4;
	new_entry->userdata[5] = userdata5;
	new_entry->userdata[6] = userdata6;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::add_callback(void* callback, void* userdata0, void* userdata1, void* userdata2, void* userdata3, void* userdata4, void* userdata5, void* userdata6, void* userdata7, t_callback_handle& callback_handle)
{
	s_callback_entry* new_entry = new() s_callback_entry{};
	new_entry->num_userdata = 8;
	new_entry->userdata[0] = userdata0;
	new_entry->userdata[1] = userdata1;
	new_entry->userdata[2] = userdata2;
	new_entry->userdata[3] = userdata3;
	new_entry->userdata[4] = userdata4;
	new_entry->userdata[5] = userdata5;
	new_entry->userdata[6] = userdata6;
	new_entry->userdata[7] = userdata7;
	new_entry->callback = callback;
	new_entry->unique_id = next_unique_id++;
	new_entry->next_entry = entry;

	entry = new_entry;

	callback_handle = static_cast<t_callback_handle>(new_entry->unique_id);
	return BCS_S_OK;
}

BCS_RESULT c_callback::remove_callback(t_callback_handle callback_handle)
{
	s_callback_entry** current_entry = &entry;
	while (*current_entry)
	{
		if ((*current_entry)->unique_id == callback_handle)
		{
			s_callback_entry* delete_entry = (*current_entry);
			(*current_entry) = delete_entry->next_entry;
			delete delete_entry;
			return BCS_S_OK;
		}
		current_entry = &(*current_entry)->next_entry;
	}
	return BCS_E_NOT_IMPLEMENTED;
}
