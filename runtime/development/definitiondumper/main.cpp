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

	c_runtime_tag_definitions* runtime_tag_definitions = new c_runtime_tag_definitions();

	unsigned int struct_definition_count = tag_file_reader->get_struct_definition_count();
	for (unsigned int struct_definition_index = 0; struct_definition_index < struct_definition_count; struct_definition_index++)
	{
		s_tag_persist_struct_definition& tag_persist_struct_definition = tag_file_reader->get_struct_definition_by_index(struct_definition_index);

		runtime_tag_definitions->enqueue_tag_struct_definition(*tag_file_reader, tag_persist_struct_definition);
	}

	const wchar_t* tag_definitions_output_directory = nullptr;
	if (BCS_SUCCEEDED(command_line_get_argument(L"tag-definitions-output-directory", tag_definitions_output_directory)))
	{
		const wchar_t* tag_groups_output_directory = nullptr;
		if (BCS_SUCCEEDED(command_line_get_argument(L"tag-groups-output-directory", tag_groups_output_directory)))
		{
			s_engine_platform_build engine_platform_build = { _engine_type_not_set, _platform_type_not_set };

			const char* engine_namespace = nullptr;
			const char* platform_namespace = nullptr;
			ASSERT(BCS_SUCCEEDED(get_engine_type_namespace(engine_platform_build.engine_type, engine_namespace)));
			ASSERT(BCS_SUCCEEDED(get_platform_type_namespace(engine_platform_build.platform_type, platform_namespace)));
			blamtoozle_generate_source(
				*runtime_tag_definitions,
				tag_definitions_output_directory,
				tag_groups_output_directory,
				engine_namespace,
				platform_namespace,
				nullptr);
		}
	}

	delete runtime_tag_definitions;
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
