#include "mandrilllib-private-pch.h"

infinite::c_infinite_generic_module_file_entry::c_infinite_generic_module_file_entry()
{
	memset(this, 0, sizeof(*this));
}

infinite::c_infinite_generic_module_file_entry::c_infinite_generic_module_file_entry(const void* data, e_build build)
{
	switch (build)
	{
	case _build_infinite_FLT002INT_199229_21_07_20_0001:
		new(this) c_infinite_generic_module_file_entry(*static_cast<const infinite::s_module_file_entry_48*>(data));
		break;
	case _build_infinite_HIFLTA_202700_21_09_06_0001:
	case _build_infinite_HIREL_209048_21_12_09_1546:
		new(this) c_infinite_generic_module_file_entry(*static_cast<const infinite::s_module_file_entry_51*>(data));
		break;
	default:
		throw BCS_E_UNSUPPORTED;
	}
}

infinite::c_infinite_generic_module_file_entry::c_infinite_generic_module_file_entry(const infinite::s_module_file_entry_48& file_entry)
{
	file_entry_48 = &file_entry;
	block_count = file_entry.block_count;
	resource_count = file_entry.resource_count;
	first_block_index = file_entry.first_block_index;
	first_resource_index = file_entry.first_resource_index;
	group_tag = file_entry.group_tag;
	packed_data_offset = file_entry.packed_data_offset;
	compressed_size = file_entry.compressed_size;
	uncompressed_size = file_entry.uncompressed_size;
	header_data_size = file_entry.header_data_size;
	tag_data_size = file_entry.tag_data_size;
	resource_data_size = file_entry.resource_data_size;
	unknown_data_size = file_entry.unknown_data_size;
	header_data_alignment = file_entry.header_data_alignment;
	tag_data_alignment = file_entry.tag_data_alignment;
	resource_data_alignment = file_entry.resource_data_alignment;
	unknown_data_alignment = file_entry.unknown_data_alignment;
	name_offset = file_entry.name_offset;
	parent_file_index = file_entry.parent_file_index;
	asset_id = file_entry.asset_id;
	global_tag_id = file_entry.global_tag_id;
	global_tag_id64 = file_entry.global_tag_id64;
}

infinite::c_infinite_generic_module_file_entry::c_infinite_generic_module_file_entry(const infinite::s_module_file_entry_51& file_entry)
{
	file_entry_51 = &file_entry;
	block_count = file_entry.block_count;
	resource_count = file_entry.resource_count;
	first_block_index = file_entry.first_block_index;
	first_resource_index = file_entry.first_resource_index;
	group_tag = file_entry.group_tag;
	packed_data_offset = file_entry.packed_data_offset;
	compressed_size = file_entry.compressed_size;
	uncompressed_size = file_entry.uncompressed_size;
	header_data_size = file_entry.header_data_size;
	tag_data_size = file_entry.tag_data_size;
	resource_data_size = file_entry.resource_data_size;
	unknown_data_size = file_entry.unknown_data_size;
	header_data_alignment = file_entry.header_data_alignment;
	tag_data_alignment = file_entry.tag_data_alignment;
	resource_data_alignment = file_entry.resource_data_alignment;
	unknown_data_alignment = file_entry.unknown_data_alignment;
	name_offset = file_entry.name_offset;
	parent_file_index = file_entry.parent_file_index;
	asset_id = file_entry.asset_id;
	global_tag_id = file_entry.global_tag_id;
	global_tag_id64 = file_entry.global_tag_id64;
}
