#include "blamtoozle-private-pch.h"

int main()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = init_command_line()))
	{
		return rs;
	}

	const wchar_t* mindump_filepath;
	if (BCS_FAILED(rs = command_line_get_argument(L"haloreachx360minidump", mindump_filepath)))
	{
		return rs;
	}

	c_reach_x360_tag_definition_manager manager(mindump_filepath);
	manager.traverse();

	const wchar_t* output_h;
	if (BCS_FAILED(rs = command_line_get_argument(L"outputh", output_h)))
	{
		return rs;
	}

	const wchar_t* output_cpp;
	if (BCS_FAILED(rs = command_line_get_argument(L"outputcpp", output_cpp)))
	{
		return rs;
	}
	
	c_blamtoozle_source_generator source_generator(manager, "haloreach", "xbox360");
	source_generator.export_single_header(output_h);
	source_generator.export_single_source(output_cpp);

	if (BCS_FAILED(rs = deinit_command_line()))
	{
		return rs;
	}

	return rs;
}
