#include "tagfileserialization-private-pch.h"

c_tag_reference_chunk::c_tag_reference_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	group_tag(blofeld::INVALID_TAG),
	tag_filepath_without_extension()
{
}

c_tag_reference_chunk::~c_tag_reference_chunk()
{
	delete[] tag_filepath_without_extension;
}

BCS_RESULT c_tag_reference_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	read_data();

	return rs;
}

void c_tag_reference_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("'%s'", tag_filepath_without_extension);
}

BCS_RESULT c_tag_reference_chunk::set_reference(tag group_tag, const char* tag_filepath_without_extension)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = set_data(&group_tag, sizeof(group_tag))))
	{
		return rs;
	}
	if (BCS_FAILED(rs = append_data(tag_filepath_without_extension, static_cast<unsigned long>(strlen(tag_filepath_without_extension)))))
	{
		return rs;
	}
	return rs;
}

BCS_RESULT c_tag_reference_chunk::set_data(const void* data, uint32_t data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = c_chunk::set_data(data, data_size)))
	{
		return rs;
	}

	is_big_endian = false;
	read_data();

	return rs;
}

void c_tag_reference_chunk::read_data()
{
	if (tag_filepath_without_extension)
	{
		delete[] tag_filepath_without_extension;
	}

	const char* chunk_data_start = get_chunk_data_start();
	intptr_t data_length = chunk_size;
	if (data_length >= 4)
	{
		intptr_t string_length = data_length - 4;
		group_tag = chunk_byteswap(*reinterpret_cast<const tag*>(chunk_data_start));
		tag_filepath_without_extension = new() char[string_length + 1];
		memcpy(tag_filepath_without_extension, chunk_data_start + sizeof(tag), string_length);
		tag_filepath_without_extension[string_length] = 0;
	}
}
