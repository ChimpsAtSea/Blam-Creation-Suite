#pragma once

struct t_tag_file_reader_metadata_stack
{
public:
	struct t_entries_array
	{
		t_entries_array* next_array;
		t_entries_array* previous_array;
		int32_t entry_count;
		t_tag_file_reader_metadata_entry metadata_entries[4096];
	};

	t_entries_array* stack_head;
	int32_t stack_length;
	t_entries_array stack_base;

	t_tag_file_reader_metadata_stack();
	~t_tag_file_reader_metadata_stack();
	t_tag_file_reader_metadata_entry& _top();
	t_tag_file_reader_metadata_entry& _push();
	t_tag_file_reader_metadata_entry& _push(t_tag_file_reader_metadata_entry& value);
	void _pop(t_tag_file_reader_metadata_entry& value);
	t_tag_file_reader_metadata_entry& _pop_unsafe();
	void copy_from(t_tag_file_reader_metadata_stack& stack);
};
