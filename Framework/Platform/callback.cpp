#include "platform-private-pch.h"

unsigned long long c_callback::next_unique_id = 1;

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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
	s_callback_entry* new_entry = new s_callback_entry{};
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
