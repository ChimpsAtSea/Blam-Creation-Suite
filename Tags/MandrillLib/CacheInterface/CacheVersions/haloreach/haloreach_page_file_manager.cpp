#include "mandrilllib-private-pch.h"

c_haloreach_page_file_manager::c_haloreach_page_file_manager(c_haloreach_cache_file& cache_file) :
	cache_file(cache_file)
{
	using namespace blofeld::haloreach;

	c_tag_group_interface* cache_file_resource_gestalt_group = cache_file.get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
	DEBUG_ASSERT(cache_file_resource_gestalt_group != nullptr);
	DEBUG_ASSERT(cache_file_resource_gestalt_group->get_tag_interfaces_count() == 1);
	v_tag_interface<s_cache_file_resource_gestalt_block_struct>* cache_file_resource_gestalt = dynamic_cast<decltype(cache_file_resource_gestalt)>(cache_file_resource_gestalt_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
	DEBUG_ASSERT(cache_file_resource_gestalt != nullptr);

	c_tag_group_interface* cache_file_resource_layout_table_group = cache_file.get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG);
	DEBUG_ASSERT(cache_file_resource_layout_table_group != nullptr);
	DEBUG_ASSERT(cache_file_resource_layout_table_group->get_tag_interfaces_count() == 1);
	v_tag_interface<s_cache_file_resource_layout_table_block_struct>* cache_file_resource_layout_table = dynamic_cast<decltype(cache_file_resource_layout_table)>(cache_file_resource_layout_table_group->get_tag_interfaces()[0]->get_virtual_tag_interface());
	DEBUG_ASSERT(cache_file_resource_layout_table != nullptr);

	/*
	* Load all of the resources pages into memory and decompress them if nessesary
	*/

	uint32_t resource_pages_count = static_cast<uint32_t>(cache_file_resource_layout_table->file_pages_block.count);
	resource_pages.resize(resource_pages_count);
	auto create_resource_page = [this, cache_file_resource_layout_table](uint32_t file_page_index)
	{
		auto& file_page = cache_file_resource_layout_table->file_pages_block[file_page_index];

		c_cache_file* file_page_cache_file = this->cache_file.get_shared_cache_file_by_file_index(file_page.shared_file);

		DEBUG_ASSERT(file_page_cache_file != nullptr);

		const s_section_cache& resources_section = dynamic_cast<c_gen3_cache_file*>(file_page_cache_file)->get_resources_section();
		const char* resources_raw_page_data = resources_section.data + file_page.file_offset;

		c_gen3_resource_page* resource_page = new c_gen3_resource_page(this->cache_file, resources_raw_page_data, file_page.file_size, file_page.size, true); /* #TODO: Detect if compressed */

		resource_pages[file_page_index].resource_page = resource_page;
	};
	tbb::parallel_for(0u, resource_pages_count, create_resource_page);

	/*
	* Create the page offset address ranges for the resource page entries
	* #TODO: Move to the loop above using an atomic operation???
	*/

	uint32_t current_page_offset = 0;
	for (uint32_t file_page_index = 0; file_page_index < cache_file_resource_layout_table->file_pages_block.count; file_page_index++)
	{
		s_resource_page_entry& resource_page_entry = resource_pages[file_page_index];
		c_gen3_resource_page& resource_page = *resource_page_entry.resource_page;
		resource_page_entry.page_address_start = current_page_offset;
		resource_page_entry.page_address_end = resource_page_entry.page_address_start + ((resource_page.data_size + 3u) / 4u);

		current_page_offset = resource_page_entry.page_address_end + 1024; // add an extra barrier of 4KiB to prevent traversal
	}
}

c_haloreach_page_file_manager::~c_haloreach_page_file_manager()
{
	for (s_resource_page_entry& resource_page_entry : resource_pages)
	{
		delete resource_page_entry.resource_page;
	}
	resource_pages.clear();
}

uint32_t c_haloreach_page_file_manager::encode_page_address(uint32_t file_page_index, uint32_t file_page_offset)
{
	DEBUG_ASSERT((file_page_offset % 4) == 0); // expect 4 byte alignment for the offset
	DEBUG_ASSERT(file_page_index < resource_pages.size()); // expect 4 byte alignment for the offset

	const s_resource_page_entry& resource_page_entry = resource_pages[file_page_index];

	uint32_t page_address = resource_page_entry.page_address_start + (file_page_offset / 4);
	uint32_t custom_bits = page_address | 0x80000000;

#ifdef _DEBUG
	uint32_t out_file_page_index;
	uint32_t out_file_page_offset;
	bool x = decode_page_address(custom_bits, out_file_page_index, out_file_page_offset);
	ASSERT(out_file_page_index == file_page_index);
	ASSERT(out_file_page_offset == file_page_offset);
#endif
	return custom_bits;
}

bool c_haloreach_page_file_manager::decode_page_address(uint32_t custom_bits, uint32_t& out_file_page_index, uint32_t& out_file_page_offset)
{
	if (custom_bits & 0x80000000)
	{
		uint32_t page_address = custom_bits & 0x7FFFFFFF;

		uint32_t num_resource_pages = static_cast<uint32_t>(resource_pages.size());
		for (uint32_t file_page_index = 0; file_page_index < num_resource_pages; file_page_index++)
		{
			const s_resource_page_entry& resource_page_entry = resource_pages[file_page_index];

			if (page_address >= resource_page_entry.page_address_start && page_address < resource_page_entry.page_address_end)
			{
				out_file_page_index = file_page_index;
				out_file_page_offset = (page_address - resource_page_entry.page_address_start) * 4;
				return true;
			}
		}
		DEBUG_ONLY(FATAL_ERROR(L"Unknown custom address type"));

		return false;
	}
	return false;
}

bool c_haloreach_page_file_manager::is_valid_data_address(void* data) const
{
	for (const s_resource_page_entry& resource_page_entry : resource_pages)
	{
		const char* resource_page_data_begin = resource_page_entry.resource_page->data;
		const char* resource_page_data_end = resource_page_data_begin + resource_page_entry.resource_page->data_size;

		if (data >= resource_page_data_begin && data < resource_page_data_end)
		{
			return true;
		}
	}
	return false;
}
