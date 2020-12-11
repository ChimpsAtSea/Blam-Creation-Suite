#include "mandrilllib-private-pch.h"

void test_mandrill_cache_file_blofeld_validation(const wchar_t* cache_filepath)
{
	c_cache_file* test_cache_file = c_cache_file::create_cache_file(cache_filepath);
	ASSERT(test_cache_file != nullptr);
	while (test_cache_file->is_loading()) {};

	for (c_tag_interface& tag_interface : c_reference_loop(test_cache_file->get_tag_interfaces(), test_cache_file->get_tag_count()))
	{
		size_t region_size = 0;
		char* region_data = nullptr;
		test_cache_file->get_raw_tag_memory_region(tag_interface.get_index(), region_size, region_data);
		if (region_size == 0) continue;
		c_console::write_line_verbose("%s is approximately %u bytes", tag_interface.get_path_with_group_id_cstr(), static_cast<uint32_t>(region_size));
	}

	delete test_cache_file;
}
