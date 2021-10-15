#pragma once

struct s_tag_block_chunk_header
{
	unsigned long count;
	unsigned long struct_index;
};

class c_single_tag_file_reader;
class s_block_definition_entry;
class s_struct_definition_entry;

class c_tag_block_chunk : public c_typed_single_tag_file_reader_chunk<'tgbl'>
{
public:
	char* blockdata_pos;
	char* metadata_pos;
	s_block_definition_entry* block_entry;
	s_struct_definition_entry* structure_entry;
	char* block_name;
	char* struct_name;
	s_tag_block_chunk_header tag_block_chunk_header;
	unsigned long block_data_size;
	unsigned long struct_size;

	c_tag_block_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_block_chunk();
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;
	void read_structure_metadata(s_struct_definition_entry& structure_entry);
	void read_structure_metadata_impl(s_struct_definition_entry& structure_entry, std::stack<unsigned long>& metadata_stack) const;
	void read_structure_data(s_struct_definition_entry& structure_entry, const char* structure_data_pos, c_tag_struct_chunk* tag_struct_chunk);
};
