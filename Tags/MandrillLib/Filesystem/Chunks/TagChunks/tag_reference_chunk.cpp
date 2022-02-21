#include "mandrilllib-private-pch.h"

c_tag_reference_chunk::c_tag_reference_chunk(const void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(chunk_data, parent, reader),
	group_tag(blofeld::INVALID_TAG),
	tag_filepath_without_extension()
{
	intptr_t data_length = chunk_data_end - chunk_data_begin;
	if (data_length >= 4)
	{
		intptr_t string_length = data_length - 4;
		group_tag = chunk_byteswap(*reinterpret_cast<const tag*>(chunk_data_begin));
		tag_filepath_without_extension = new() char[string_length + 1];
		memcpy(tag_filepath_without_extension, chunk_data_begin + sizeof(tag), string_length);
		tag_filepath_without_extension[string_length] = 0;
	}
	debug_point;

	log_pad();
	log_signature();
	console_write_line_verbose("'%s'", tag_filepath_without_extension);
}

c_tag_reference_chunk::~c_tag_reference_chunk()
{
	delete[] tag_filepath_without_extension;
}

void c_tag_reference_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("'%s'", tag_filepath_without_extension);
}