#pragma once

namespace infinite
{
	class c_infinite_generic_module_file_entry
	{
	public:
		c_infinite_generic_module_file_entry();
		c_infinite_generic_module_file_entry(const void* data, e_build build);
		c_infinite_generic_module_file_entry(const infinite::s_module_file_entry_48& file_entry);
		c_infinite_generic_module_file_entry(const infinite::s_module_file_entry_51& file_entry);

		union
		{
			const infinite::s_module_file_entry_48* file_entry_48;
			const infinite::s_module_file_entry_51* file_entry_51;
		};
		unsigned short block_count;
		unsigned short resource_count;
		uint32_t first_block_index;
		uint32_t first_resource_index;
		tag group_tag;
		s_module_file_packed_data_offset packed_data_offset;
		uint32_t compressed_size;
		uint32_t uncompressed_size;
		uint32_t header_data_size;
		uint32_t tag_data_size;
		uint32_t resource_data_size;
		uint32_t unknown_data_size;
		unsigned char header_data_alignment;
		unsigned char tag_data_alignment;
		unsigned char resource_data_alignment;
		unsigned char unknown_data_alignment;
		uint32_t name_offset;
		int32_t parent_file_index;
		int64_t asset_id;
		int32_t global_tag_id;
		int64_t global_tag_id64;
	};
}
