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
		unsigned long first_block_index;
		unsigned long first_resource_index;
		tag group_tag;
		s_module_file_packed_data_offset packed_data_offset;
		unsigned long compressed_size;
		unsigned long uncompressed_size;
		unsigned long header_data_size;
		unsigned long tag_data_size;
		unsigned long resource_data_size;
		unsigned long unknown_data_size;
		unsigned char header_data_alignment;
		unsigned char tag_data_alignment;
		unsigned char resource_data_alignment;
		unsigned char unknown_data_alignment;
		unsigned long name_offset;
		long parent_file_index;
		long long asset_id;
		long global_tag_id;
		long long global_tag_id64;
	};
}
