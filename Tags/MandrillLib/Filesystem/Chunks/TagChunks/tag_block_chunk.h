#pragma once

struct s_tag_block_chunk_header
{
	unsigned long count;
	unsigned long struct_index;
};

class c_single_tag_file_reader;
struct s_tag_persist_block_definition;
struct s_tag_persist_struct_definition;

class c_tag_block_chunk : public c_typed_single_tag_file_reader_chunk<'tgbl', true>
{
public:
	const char* block_structure_data_begin;
	const char* block_structure_data_position;
	const char* block_child_chunk_data_start;
	const char* block_child_chunk_data_position;
	s_tag_persist_block_definition* block_entry;
	s_tag_persist_struct_definition* structure_entry;
	const char* block_name;
	const char* struct_name;
	s_tag_block_chunk_header tag_block_chunk_header;
	unsigned long block_data_size;
	unsigned long struct_size;

	c_tag_block_chunk(c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_block_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);
	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;

	const char* get_sturcutre_data_by_index(unsigned long index) const;
	c_tag_struct_chunk* get_sturcutre_chunk_by_index(unsigned long index) const;

	void read_structure_metadata(s_tag_persist_struct_definition& structure_entry);
	void read_structure_metadata_impl(s_tag_persist_struct_definition& structure_entry, std::stack<unsigned long>& metadata_stack) const;
	void read_structure_data(s_tag_persist_struct_definition& structure_entry, const char* structure_data_pos, c_tag_struct_chunk* tag_struct_chunk);

};
