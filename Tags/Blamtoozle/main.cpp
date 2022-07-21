#include "blamtoozle-private-pch.h"

#define parse_command_line_argument_ulong(argument, destination) \
if (BCS_FAILED(rs = command_line_get_argument_ulong(argument, destination))) \
{ \
	console_write_line("Get argument " argument " failed %s", bcs_result_get_string(rs)); \
	return rs; \
}

#define parse_command_line_argument_ulonglong(argument, destination) \
if (BCS_FAILED(rs = command_line_get_argument_ulonglong(argument, destination))) \
{ \
	console_write_line("Get argument " argument " failed %s", bcs_result_get_string(rs)); \
	return rs; \
}

#define parse_command_line_argument_wstring(argument, destination) \
if (BCS_FAILED(rs = command_line_get_argument(argument, destination))) \
{ \
	console_write_line("Get argument %S failed %s", argument, bcs_result_get_string(rs)); \
	return rs; \
}

#define get_namespaces(engine_type, platform_type, engine_type_destination, platform_type_destination) \
if (BCS_FAILED(rs = get_engine_type_namespace(engine_type, engine_type_destination))) \
{ \
	return rs; \
} \
if (BCS_FAILED(rs = get_platform_type_namespace(platform_type, platform_type_destination))) \
{ \
	return rs; \
}

int main()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = init_command_line()))
	{
		return rs;
	}

	const wchar_t* tag_definitions_output_directory;
	const wchar_t* tag_groups_output_directory;

	parse_command_line_argument_wstring(L"tag-definitions-output-directory", tag_definitions_output_directory);
	parse_command_line_argument_wstring(L"tag-groups-output-directory", tag_groups_output_directory);

	const wchar_t* halo1_tools_pc64_minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo1-tools-pc64-minidump", halo1_tools_pc64_minidump)))
	{
		console_write_line("Exporting Halo 1 Tools PC 64bit");

		if (BCS_FAILED(rs = filesystem_filepath_exists(halo1_tools_pc64_minidump)))
		{
			console_write_line("halo1-tools-pc64-minidump filepath missing [%S]", halo1_tools_pc64_minidump);
			return rs;
		}

		ptr64 halo1_group_table_address;
		uint32_t halo1_num_tag_layouts;
		parse_command_line_argument_ulonglong("halo1-tools-pc64-table-address", halo1_group_table_address);
		parse_command_line_argument_ulong("halo1-tools-pc64-num-tag-layouts", halo1_num_tag_layouts);

		c_halo1_tools_pc64_tag_definition_manager halo1_tools_pc64_manager(halo1_tools_pc64_minidump);
		halo1_tools_pc64_manager.traverse(halo1_group_table_address, halo1_num_tag_layouts);

		c_blamtoozle_source_generator source_generator(halo1_tools_pc64_manager, "halo1", "pc64");

		std::wstring output_header = std::wstring(tag_definitions_output_directory) + L"halo1-tools-pc64.h";
		std::wstring output_source = std::wstring(tag_definitions_output_directory) + L"halo1-tools-pc64.cpp";
		std::wstring output_tag_groups_header = std::wstring(tag_groups_output_directory) + L"halo1-tools-pc64-groups.h";
		std::wstring output_tag_groups_source = std::wstring(tag_groups_output_directory) + L"halo1-tools-pc64-groups.cpp";

		source_generator.export_single_tag_definitions_header(output_header.c_str());
		source_generator.export_single_tag_definitions_source(output_source.c_str());
		source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
		source_generator.export_tag_groups_source(output_tag_groups_source.c_str());

		debug_point;
	}

	const wchar_t* halo2_tools_pc64_minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo2-tools-pc64-minidump", halo2_tools_pc64_minidump)))
	{
		console_write_line("Exporting Halo 2 Tools PC 64bit");

		if (BCS_FAILED(rs = filesystem_filepath_exists(halo2_tools_pc64_minidump)))
		{
			console_write_line("halo2-tools-pc64-minidump filepath missing [%S]", halo2_tools_pc64_minidump);
			return rs;
		}

		ptr64 halo2_group_table_address;
		uint32_t halo2_num_tag_layouts;
		parse_command_line_argument_ulonglong("halo2-tools-pc64-table-address", halo2_group_table_address);
		parse_command_line_argument_ulong("halo2-tools-pc64-num-tag-layouts", halo2_num_tag_layouts);

		c_halo2_tools_pc64_tag_definition_manager halo2_tools_pc64_manager(halo2_tools_pc64_minidump);
		halo2_tools_pc64_manager.traverse(halo2_group_table_address, halo2_num_tag_layouts);

		const char* engine_namespace;
		const char* platform_namespace;
		get_namespaces(_engine_type_halo2, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		c_blamtoozle_source_generator source_generator(halo2_tools_pc64_manager, engine_namespace, platform_namespace);

		std::wstring output_header = std::wstring(tag_definitions_output_directory) + L"halo2-tools-pc64.h";
		std::wstring output_source = std::wstring(tag_definitions_output_directory) + L"halo2-tools-pc64.cpp";
		std::wstring output_tag_groups_header = std::wstring(tag_groups_output_directory) + L"halo2-tools-pc64-groups.h";
		std::wstring output_tag_groups_source = std::wstring(tag_groups_output_directory) + L"halo2-tools-pc64-groups.cpp";

		source_generator.export_single_tag_definitions_header(output_header.c_str());
		source_generator.export_single_tag_definitions_source(output_source.c_str());
		source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
		source_generator.export_tag_groups_source(output_tag_groups_source.c_str());

		debug_point;
	}

	const wchar_t* halo3_tools_pc64_minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo3-tools-pc64-minidump", halo3_tools_pc64_minidump)))
	{
		console_write_line("Exporting Halo 3 Tools PC 64bit");

		if (BCS_FAILED(rs = filesystem_filepath_exists(halo3_tools_pc64_minidump)))
		{
			console_write_line("halo3-tools-pc64-minidump filepath missing [%S]", halo3_tools_pc64_minidump);
			return rs;
		}

		ptr64 halo3_group_table_address;
		uint32_t halo3_num_tag_layouts;
		parse_command_line_argument_ulonglong("halo3-tools-pc64-table-address", halo3_group_table_address);
		parse_command_line_argument_ulong("halo3-tools-pc64-num-tag-layouts", halo3_num_tag_layouts);

		c_halo3_tools_pc64_tag_definition_manager halo3_manager(halo3_tools_pc64_minidump);
		halo3_manager.traverse(halo3_group_table_address, halo3_num_tag_layouts);

		const char* engine_namespace;
		const char* platform_namespace;
		get_namespaces(_engine_type_halo3, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		c_blamtoozle_source_generator source_generator(halo3_manager, engine_namespace, platform_namespace);

		std::wstring output_header = std::wstring(tag_definitions_output_directory) + L"halo3-tools-pc64.h";
		std::wstring output_source = std::wstring(tag_definitions_output_directory) + L"halo3-tools-pc64.cpp";
		std::wstring output_tag_groups_header = std::wstring(tag_groups_output_directory) + L"halo3-tools-pc64-groups.h";
		std::wstring output_tag_groups_source = std::wstring(tag_groups_output_directory) + L"halo3-tools-pc64-groups.cpp";

		source_generator.export_single_tag_definitions_header(output_header.c_str());
		source_generator.export_single_tag_definitions_source(output_source.c_str());
		source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
		source_generator.export_tag_groups_source(output_tag_groups_source.c_str());

		debug_point;
	}

	const wchar_t* halo3odst_tools_pc64_minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo3odst-tools-pc64-minidump", halo3odst_tools_pc64_minidump)))
	{
		console_write_line("Exporting Halo 3: ODST Tools PC 64bit");

		if (BCS_FAILED(rs = filesystem_filepath_exists(halo3odst_tools_pc64_minidump)))
		{
			console_write_line("halo3odst-tools-pc64-minidump filepath missing [%S]", halo3odst_tools_pc64_minidump);
			return rs;
		}

		ptr64 halo3odst_group_table_address;
		uint32_t halo3odst_num_tag_layouts;
		parse_command_line_argument_ulonglong("halo3odst-tools-pc64-table-address", halo3odst_group_table_address);
		parse_command_line_argument_ulong("halo3odst-tools-pc64-num-tag-layouts", halo3odst_num_tag_layouts);

		c_halo3_tools_pc64_tag_definition_manager halo3odst_manager(halo3odst_tools_pc64_minidump);
		halo3odst_manager.traverse(halo3odst_group_table_address, halo3odst_num_tag_layouts);

		const char* engine_namespace;
		const char* platform_namespace;
		get_namespaces(_engine_type_halo3odst, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		c_blamtoozle_source_generator source_generator(halo3odst_manager, engine_namespace, platform_namespace);

		std::wstring output_header = std::wstring(tag_definitions_output_directory) + L"halo3odst-tools-pc64.h";
		std::wstring output_source = std::wstring(tag_definitions_output_directory) + L"halo3odst-tools-pc64.cpp";
		std::wstring output_tag_groups_header = std::wstring(tag_groups_output_directory) + L"halo3odst-tools-pc64-groups.h";
		std::wstring output_tag_groups_source = std::wstring(tag_groups_output_directory) + L"halo3odst-tools-pc64-groups.cpp";

		source_generator.export_single_tag_definitions_header(output_header.c_str());
		source_generator.export_single_tag_definitions_source(output_source.c_str());
		source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
		source_generator.export_tag_groups_source(output_tag_groups_source.c_str());

		debug_point;
	}

	const wchar_t* haloreach_tagtest_xbox360_minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"haloreach-tagtest-xbox360-minidump", haloreach_tagtest_xbox360_minidump)))
	{
		console_write_line("Exporting Halo Reach Tag Test Xbox 360");

		if (BCS_FAILED(rs = filesystem_filepath_exists(haloreach_tagtest_xbox360_minidump)))
		{
			console_write_line("haloreach-tagtest-xbox360-minidump filepath missing [%S]", haloreach_tagtest_xbox360_minidump);
			return rs;
		}

		ptr32 haloreach_x360_group_table_address;
		uint32_t haloreach_x360_num_tag_layouts;
		parse_command_line_argument_ulong("haloreach-tagtest-xbox360-table-address", haloreach_x360_group_table_address);
		parse_command_line_argument_ulong("haloreach-tagtest-xbox360-num-tag-layouts", haloreach_x360_num_tag_layouts);

		c_reach_x360_tag_definition_manager reach_x360_manager(haloreach_tagtest_xbox360_minidump);
		reach_x360_manager.traverse(haloreach_x360_group_table_address, haloreach_x360_num_tag_layouts);

		const char* engine_namespace;
		const char* platform_namespace;
		get_namespaces(_engine_type_haloreach, _platform_type_xbox_360, engine_namespace, platform_namespace);
		c_blamtoozle_source_generator source_generator(reach_x360_manager, engine_namespace, platform_namespace);

		std::wstring output_header = std::wstring(tag_definitions_output_directory) + L"haloreach-tagtest-xbox360.h";
		std::wstring output_source = std::wstring(tag_definitions_output_directory) + L"haloreach-tagtest-xbox360.cpp";
		std::wstring output_tag_groups_header = std::wstring(tag_groups_output_directory) + L"haloreach-tagtest-xbox360-groups.h";
		std::wstring output_tag_groups_source = std::wstring(tag_groups_output_directory) + L"haloreach-tagtest-xbox360-groups.cpp";

		source_generator.export_single_tag_definitions_header(output_header.c_str());
		source_generator.export_single_tag_definitions_source(output_source.c_str());
		source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
		source_generator.export_tag_groups_source(output_tag_groups_source.c_str());

		debug_point;
	}

	const wchar_t* halo4_tagtest_xbox360_minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo4-tagtest-xbox360-minidump", halo4_tagtest_xbox360_minidump)))
	{
		console_write_line("Exporting Halo 4 Tag Test Xbox 360");

		if (BCS_FAILED(rs = filesystem_filepath_exists(halo4_tagtest_xbox360_minidump)))
		{
			console_write_line("halo4-tagtest-xbox360-minidump filepath missing [%S]", halo4_tagtest_xbox360_minidump);
			return rs;
		}

		ptr32 halo4_x360_group_table_address;
		uint32_t halo4_x360_num_tag_layouts;
		parse_command_line_argument_ulong("halo4-tagtest-xbox360-table-address", halo4_x360_group_table_address);
		parse_command_line_argument_ulong("halo4-tagtest-xbox360-num-tag-layouts", halo4_x360_num_tag_layouts);

		c_halo4_x360_tag_definition_manager halo4_x360_manager(halo4_tagtest_xbox360_minidump);
		halo4_x360_manager.traverse(halo4_x360_group_table_address, halo4_x360_num_tag_layouts);

		const char* engine_namespace;
		const char* platform_namespace;
		get_namespaces(_engine_type_halo4, _platform_type_xbox_360, engine_namespace, platform_namespace);
		c_blamtoozle_source_generator source_generator(halo4_x360_manager, engine_namespace, platform_namespace);

		std::wstring output_header = std::wstring(tag_definitions_output_directory) + L"halo4-tagtest-xbox360.h";
		std::wstring output_source = std::wstring(tag_definitions_output_directory) + L"halo4-tagtest-xbox360.cpp";
		std::wstring output_tag_groups_header = std::wstring(tag_groups_output_directory) + L"halo4-tagtest-xbox360-groups.h";
		std::wstring output_tag_groups_source = std::wstring(tag_groups_output_directory) + L"halo4-tagtest-xbox360-groups.cpp";

		source_generator.export_single_tag_definitions_header(output_header.c_str());
		source_generator.export_single_tag_definitions_source(output_source.c_str());
		source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
		source_generator.export_tag_groups_source(output_tag_groups_source.c_str());

		debug_point;
	}

	if (BCS_FAILED(rs = deinit_command_line()))
	{
		return rs;
	}

	return rs;
}
