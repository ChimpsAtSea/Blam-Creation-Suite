#include "definitiondumper-private-pch.h"

BCS_RESULT dump_definition()
{
	BCS_RESULT rs = BCS_S_OK;

	const wchar_t* filepath;
	if (BCS_FAILED(rs = command_line_get_argument(L"filepath", filepath)))
	{
		return rs;
	}

	void* tag_file_data;
	uint64_t tag_file_data_size;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size)))
	{
		return rs;
	}

	if (tag_file_data_size < (sizeof(s_tag_file_header) + sizeof(tag)))
	{
		return BCS_E_FAIL;
	}

	s_tag_file_header* tag_file_header = static_cast<s_tag_file_header*>(tag_file_data);

	if (tag_file_header->blam != 'BLAM')
	{
		return BCS_E_FAIL;
	}

	c_tag_file_reader* tag_file_reader = new() c_tag_file_reader(tag_file_data);

	unsigned int struct_definition_count = tag_file_reader->get_struct_definition_count();
	for (unsigned int struct_definition_index = 0; struct_definition_index < struct_definition_count; struct_definition_index++)
	{
		s_tag_persist_struct_definition& struct_definition = tag_file_reader->get_struct_definition_by_index(struct_definition_index);

	}

	delete tag_file_reader;

	return rs;
}

extern "C" int bcs_main()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = dump_definition()))
	{
		return rs;
	}

	return rs;
}
