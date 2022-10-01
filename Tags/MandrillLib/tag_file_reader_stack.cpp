#include "mandrilllib-private-pch.h"

t_tag_file_reader_metadata_stack::t_tag_file_reader_metadata_stack()
{
	stack_head = &stack_base;
	stack_length = 0;
	stack_base.next_array = nullptr;
	stack_base.previous_array = &stack_base;
	stack_base.entry_count = 0;
}

t_tag_file_reader_metadata_stack::~t_tag_file_reader_metadata_stack()
{
	t_entries_array* entry = stack_base.next_array;
	while (entry)
	{
		t_entries_array* next_entry = entry->next_array;
		delete entry;
		entry = next_entry;
	}
}

t_tag_file_reader_metadata_entry& t_tag_file_reader_metadata_stack::_top()
{
	//ASSERT(stack_length > 0);
	//ASSERT(stack_head);
	//ASSERT(stack_head->entry_count > 0);
	return stack_head->metadata_entries[stack_head->entry_count - 1];
}

t_tag_file_reader_metadata_entry& t_tag_file_reader_metadata_stack::_push()
{
	/*if (stack_head == nullptr)
	{
		t_entries_array* next_entry = stack_head = stack_base = static_cast<t_entries_array*>(tracked_malloc(sizeof(t_entries_array)));
		memset(next_entry, 0xAA, sizeof(*next_entry));
		next_entry->entry_count = 0;
		next_entry->next_array = nullptr;
		next_entry->previous_array = next_entry;
	}
	else */if (stack_head->entry_count == _countof(t_entries_array::metadata_entries))
	{
		if (stack_head->next_array != nullptr)
		{
			stack_head = stack_head->next_array;
			
		}
		else
		{
			t_entries_array* previous_entry = stack_head;
			t_entries_array* next_entry = stack_head = stack_head->next_array = static_cast<t_entries_array*>(tracked_malloc(sizeof(t_entries_array)));
			memset(next_entry, 0xBB, sizeof(*next_entry));
			next_entry->entry_count = 0;
			next_entry->next_array = nullptr;
			next_entry->previous_array = previous_entry;
		}
	}

	int32_t entry_index = stack_head->entry_count++;
	//ASSERT(entry_index < _countof(t_entries_array::metadata_entries));

	t_tag_file_reader_metadata_entry& entry = stack_head->metadata_entries[entry_index];
	stack_length++;
	return entry;
}

t_tag_file_reader_metadata_entry& t_tag_file_reader_metadata_stack::_push(t_tag_file_reader_metadata_entry& value)
{
	/*if (stack_head == nullptr)
	{
		t_entries_array* next_entry = stack_head = stack_base = static_cast<t_entries_array*>(tracked_malloc(sizeof(t_entries_array)));
		memset(next_entry, 0xAA, sizeof(*next_entry));
		next_entry->entry_count = 0;
		next_entry->next_array = nullptr;
		next_entry->previous_array = next_entry;
	}
	else */if (stack_head->entry_count == _countof(t_entries_array::metadata_entries))
	{
		if (stack_head->next_array != nullptr)
		{
			stack_head = stack_head->next_array;
			
		}
		else
		{
			t_entries_array* previous_entry = stack_head;
			t_entries_array* next_entry = stack_head = stack_head->next_array = static_cast<t_entries_array*>(tracked_malloc(sizeof(t_entries_array)));
			memset(next_entry, 0xDD, sizeof(*next_entry));
			next_entry->entry_count = 0;
			next_entry->next_array = nullptr;
			next_entry->previous_array = previous_entry;
		}
	}

	int32_t entry_index = stack_head->entry_count++;
	//ASSERT(entry_index < _countof(t_entries_array::metadata_entries));

	t_tag_file_reader_metadata_entry& entry = stack_head->metadata_entries[entry_index];
	entry = value;
	stack_length++;
	return entry;
}

void t_tag_file_reader_metadata_stack::_pop(t_tag_file_reader_metadata_entry& value)
{
	//ASSERT(stack_length > 0);
	//ASSERT(stack_head->entry_count > 0);
	int32_t entry_index = --stack_head->entry_count;
	//ASSERT(entry_index >= 0);
	stack_length--;
	value = stack_head->metadata_entries[entry_index];
	if (entry_index == 0)
	{
		stack_head = stack_head->previous_array;
		//ASSERT(stack_head);
	}
}

t_tag_file_reader_metadata_entry& t_tag_file_reader_metadata_stack::_pop_unsafe()
{
	ASSERT(stack_length > 0);
	ASSERT(stack_head->entry_count > 0);
	int32_t entry_index = --stack_head->entry_count;
	//ASSERT(entry_index >= 0);
	stack_length--;
	t_tag_file_reader_metadata_entry& result = stack_head->metadata_entries[entry_index];
	if (entry_index == 0)
	{
		stack_head = stack_head->previous_array;
		//ASSERT(stack_head);
	}
	return result;
}

void t_tag_file_reader_metadata_stack::copy_from(t_tag_file_reader_metadata_stack& stack)
{
	uint32_t src_stack_length = stack.stack_length;
	while(src_stack_length--)
	{
		t_tag_file_reader_metadata_entry& entry = stack._pop_unsafe();
		_push(entry);
	}
}
