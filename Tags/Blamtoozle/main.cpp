#include "blamtoozle-private-pch.h"

int main()
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = init_command_line()))
	{
		return rs;
	}

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

	const wchar_t* halo2guerilla32minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo2guerilla32minidump", halo2guerilla32minidump)))
	{

		ptr32 halo2_guerilla_pc32_group_table_address = 0x00DB6B40;
		unsigned long halo2_guerilla_pc32_num_tag_layouts = 120;

		c_halo2_tools_pc32_tag_definition_manager halo2_tools_pc32_manager(halo2guerilla32minidump);
		halo2_tools_pc32_manager.traverse(halo2_guerilla_pc32_group_table_address, halo2_guerilla_pc32_num_tag_layouts);

		c_blamtoozle_source_generator source_generator(halo2_tools_pc32_manager, "halo2", "pc32");

		source_generator.export_single_header(output_h);
		source_generator.export_single_source(output_cpp);

		debug_point;
	}

	const wchar_t* halo3toolspc64minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo3toolspc64minidump", halo3toolspc64minidump)))
	{

		ptr64 halo3_group_table_address = 0x0000000140EC2C90;
		unsigned long halo3_num_tag_layouts = 182;

		c_halo3_tools_pc64_tag_definition_manager halo3_manager(halo3toolspc64minidump);
		halo3_manager.traverse(halo3_group_table_address, halo3_num_tag_layouts);

		c_blamtoozle_source_generator source_generator(halo3_manager, "halo3", "xbox360");

		source_generator.export_single_header(output_h);
		source_generator.export_single_source(output_cpp);

		debug_point;
	}

	const wchar_t* halo3odstguerillapc64minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo3odstguerillapc64minidump", halo3odstguerillapc64minidump)))
	{

		ptr64 halo3odst_group_table_address = 0x00000001410980D0;
		unsigned long halo3odst_num_tag_layouts = 197;

		c_halo3_tools_pc64_tag_definition_manager halo3odst_manager(halo3odstguerillapc64minidump);
		halo3odst_manager.traverse(halo3odst_group_table_address, halo3odst_num_tag_layouts);

		c_blamtoozle_source_generator source_generator(halo3odst_manager, "halo3odst", "pc64");

		source_generator.export_single_header(output_h);
		source_generator.export_single_source(output_cpp);

		debug_point;
	}

	const wchar_t* haloreachx360minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"haloreachx360minidump", haloreachx360minidump)))
	{

		ptr32 reach_x360_group_table_address = 0x83FA8F40;
		unsigned long reach_x360_num_tag_layouts = 237;

		c_reach_x360_tag_definition_manager reach_x360_manager(haloreachx360minidump);
		reach_x360_manager.traverse(reach_x360_group_table_address, reach_x360_num_tag_layouts);

		c_blamtoozle_source_generator source_generator(reach_x360_manager, "haloreach", "xbox360");

		source_generator.export_single_header(output_h);
		source_generator.export_single_source(output_cpp);

		debug_point;
	}

	const wchar_t* halo4x360minidump;
	if (BCS_SUCCEEDED(rs = command_line_get_argument(L"halo4x360minidump", halo4x360minidump)))
	{

		ptr32 halo4_x360_group_table_address = 0x859D8350;
		unsigned long halo4_x360_num_tag_layouts = 262;

		c_halo4_x360_tag_definition_manager halo4_x360_manager(halo4x360minidump);
		halo4_x360_manager.traverse(halo4_x360_group_table_address, halo4_x360_num_tag_layouts);

		c_blamtoozle_source_generator source_generator(halo4_x360_manager, "halo4", "xbox360");

		source_generator.export_single_header(output_h);
		source_generator.export_single_source(output_cpp);

		debug_point;
	}






	if (BCS_FAILED(rs = deinit_command_line()))
	{
		return rs;
	}

	return rs;
}
