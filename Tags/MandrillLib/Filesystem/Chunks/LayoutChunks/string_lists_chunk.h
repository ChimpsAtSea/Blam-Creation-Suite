#pragma once

struct s_tag_persist_string_list
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long string_offset_count;
	unsigned long string_offset_start_index;
};

class c_string_lists_chunk : public c_typed_chunk<'sz[]', false>
{
public:
	s_tag_persist_string_list* entries;
	unsigned long entry_count;

	c_string_lists_chunk(c_chunk& parent);
	~c_string_lists_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
