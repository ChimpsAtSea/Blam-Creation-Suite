#include "blamtoozlecmd-private-pch.h"

#define parse_command_line_argument_ulong(argument, destination) \
if (BCS_FAILED(rs = command_line_get_argument_ulong(argument, destination))) \
{ \
	console_write_line("Get argument " argument " failed %s", bcs_result_get_string(rs)); \
	return rs; \
}

#define parse_command_line_argument_long(argument, destination) \
if (BCS_FAILED(rs = command_line_get_argument_long(argument, destination))) \
{ \
	console_write_line("Get argument " argument " failed %s", bcs_result_get_string(rs)); \
	return rs; \
}

#define parse_command_line_argument_longlong(argument, destination) \
if (BCS_FAILED(rs = command_line_get_argument_longlong(argument, destination))) \
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

const wchar_t* tag_definitions_output_directory;
const wchar_t* tag_groups_output_directory;

void generate_source(
	c_blamtoozle_tag_definition_manager& tag_definition_manager, 
	ptr64 group_table_address, 
	uint32_t num_tag_layouts,
	const char* engine_namespace, 
	const char* platform_namespace,
	const char* source_suffix)
{
	tag_definition_manager.traverse(group_table_address, num_tag_layouts);

	c_blamtoozle_source_generator source_generator(tag_definition_manager, engine_namespace, platform_namespace);

	std::wstringstream output_header_stream;
	output_header_stream << std::wstring(tag_definitions_output_directory) << engine_namespace << L"-" + !source_suffix << source_suffix << "-" << platform_namespace << L".h";

	std::wstringstream output_source_stream;
	output_source_stream << std::wstring(tag_definitions_output_directory) << engine_namespace << L"-" + !source_suffix << source_suffix << "-" << platform_namespace << L".cpp";

	std::wstringstream output_tag_groups_header_stream;
	output_tag_groups_header_stream << std::wstring(tag_groups_output_directory) << engine_namespace << L"-" + !source_suffix << source_suffix << "-" << platform_namespace << L"-groups.h";

	std::wstringstream output_tag_groups_source_stream;
	output_tag_groups_source_stream << std::wstring(tag_groups_output_directory) << engine_namespace << L"-" + !source_suffix << source_suffix << "-" << platform_namespace << L"-groups.cpp";

	std::wstring output_header  = output_header_stream.str();
	std::wstring output_source = output_source_stream.str();
	std::wstring output_tag_groups_header = output_tag_groups_header_stream.str();
	std::wstring output_tag_groups_source = output_tag_groups_source_stream.str();

	source_generator.export_single_tag_definitions_header(output_header.c_str());
	source_generator.export_single_tag_definitions_source(output_source.c_str());
	source_generator.export_tag_groups_header(output_tag_groups_header.c_str());
	source_generator.export_tag_groups_source(output_tag_groups_source.c_str());
}

int main()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = init_command_line()))
	{
		return rs;
	}

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
		parse_command_line_argument_longlong("halo1-tools-pc64-table-address", halo1_group_table_address);
		parse_command_line_argument_ulong("halo1-tools-pc64-num-tag-layouts", halo1_num_tag_layouts);

		c_halo1_tools_pc64_tag_definition_manager halo1_tools_pc64_manager(halo1_tools_pc64_minidump);

		const char* engine_namespace = nullptr;
		const char* platform_namespace = nullptr;
		get_namespaces(_engine_type_halo1, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		generate_source(
			halo1_tools_pc64_manager,
			halo1_group_table_address,
			halo1_num_tag_layouts,
			engine_namespace,
			platform_namespace,
			"tools");

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
		parse_command_line_argument_longlong("halo2-tools-pc64-table-address", halo2_group_table_address);
		parse_command_line_argument_ulong("halo2-tools-pc64-num-tag-layouts", halo2_num_tag_layouts);

		c_halo2_tools_pc64_tag_definition_manager halo2_tools_pc64_manager(halo2_tools_pc64_minidump);

		const char* engine_namespace = nullptr;
		const char* platform_namespace = nullptr;
		get_namespaces(_engine_type_halo2, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		generate_source(
			halo2_tools_pc64_manager, 
			halo2_group_table_address, 
			halo2_num_tag_layouts, 
			engine_namespace, 
			platform_namespace, 
			"tools");

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
		parse_command_line_argument_longlong("halo3-tools-pc64-table-address", halo3_group_table_address);
		parse_command_line_argument_ulong("halo3-tools-pc64-num-tag-layouts", halo3_num_tag_layouts);

		c_halo3_tools_pc64_tag_definition_manager halo3_tools_pc64_manager(halo3_tools_pc64_minidump);

		const char* engine_namespace = nullptr;
		const char* platform_namespace = nullptr;
		get_namespaces(_engine_type_halo3, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		generate_source(
			halo3_tools_pc64_manager,
			halo3_group_table_address,
			halo3_num_tag_layouts,
			engine_namespace,
			platform_namespace,
			"tools");

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
		parse_command_line_argument_longlong("halo3odst-tools-pc64-table-address", halo3odst_group_table_address);
		parse_command_line_argument_ulong("halo3odst-tools-pc64-num-tag-layouts", halo3odst_num_tag_layouts);

		c_halo3_tools_pc64_tag_definition_manager halo3odst_tools_pc64_manager(halo3odst_tools_pc64_minidump);

		const char* engine_namespace = nullptr;
		const char* platform_namespace = nullptr;
		get_namespaces(_engine_type_halo3odst, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		generate_source(
			halo3odst_tools_pc64_manager,
			halo3odst_group_table_address,
			halo3odst_num_tag_layouts,
			engine_namespace,
			platform_namespace,
			"tools");

		debug_point;
	}

	const wchar_t* haloreach_sapien_pc64_minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"haloreach-sapien-pc64-minidump", haloreach_sapien_pc64_minidump)))
	{
		console_write_line("Exporting Halo Reach Sapien PC64");

		if (BCS_FAILED(rs = filesystem_filepath_exists(haloreach_sapien_pc64_minidump)))
		{
			console_write_line("haloreach-sapien-pc64-minidump filepath missing [%S]", haloreach_sapien_pc64_minidump);
			return rs;
		}

		ptr64 haloreach_pc64_group_table_address;
		uint32_t haloreach_pc64_num_tag_layouts;
		parse_command_line_argument_longlong("haloreach-sapien-pc64-table-address", haloreach_pc64_group_table_address);
		parse_command_line_argument_ulong("haloreach-sapien-pc64-num-tag-layouts", haloreach_pc64_num_tag_layouts);

		c_halo3_tools_pc64_tag_definition_manager haloreach_pc64_manager(haloreach_sapien_pc64_minidump);

		const char* engine_namespace = nullptr;
		const char* platform_namespace = nullptr;
		get_namespaces(_engine_type_haloreach, _platform_type_pc_64bit, engine_namespace, platform_namespace);
		generate_source(
			haloreach_pc64_manager,
			haloreach_pc64_group_table_address,
			haloreach_pc64_num_tag_layouts,
			engine_namespace,
			platform_namespace,
			"tools");

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
		parse_command_line_argument_long("haloreach-tagtest-xbox360-table-address", haloreach_x360_group_table_address);
		parse_command_line_argument_ulong("haloreach-tagtest-xbox360-num-tag-layouts", haloreach_x360_num_tag_layouts);

		c_reach_x360_tag_definition_manager haloreach_x360_manager(haloreach_tagtest_xbox360_minidump);

		const char* engine_namespace = nullptr;
		const char* platform_namespace = nullptr;
		get_namespaces(_engine_type_haloreach, _platform_type_xbox_360, engine_namespace, platform_namespace);
		generate_source(
			haloreach_x360_manager,
			haloreach_x360_group_table_address,
			haloreach_x360_num_tag_layouts,
			engine_namespace,
			platform_namespace,
			"tagtest");

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
		parse_command_line_argument_long("halo4-tagtest-xbox360-table-address", halo4_x360_group_table_address);
		parse_command_line_argument_ulong("halo4-tagtest-xbox360-num-tag-layouts", halo4_x360_num_tag_layouts);

		c_halo4_x360_tag_definition_manager halo4_x360_manager(halo4_tagtest_xbox360_minidump);

		const char* engine_namespace = nullptr;
		const char* platform_namespace = nullptr;
		get_namespaces(_engine_type_halo4, _platform_type_xbox_360, engine_namespace, platform_namespace);
		generate_source(
			halo4_x360_manager,
			halo4_x360_group_table_address,
			halo4_x360_num_tag_layouts,
			engine_namespace,
			platform_namespace,
			"tagtest");


		debug_point;
	}

	if (BCS_FAILED(rs = deinit_command_line()))
	{
		return rs;
	}

	return rs;
}
