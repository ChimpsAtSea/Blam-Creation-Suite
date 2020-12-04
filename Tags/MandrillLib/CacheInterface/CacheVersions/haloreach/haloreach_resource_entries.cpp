#include "mandrilllib-private-pch.h"

using namespace blofeld;
using namespace blofeld::haloreach;

static constexpr size_t y = sizeof(s_render_texture_interop_definition_struct);
static constexpr size_t x = offsetof(s_render_texture_interop_definition_struct, d3d_data);
static_assert(x == 60, "");

c_bitmap_texture_interop_resource_entry::c_bitmap_texture_interop_resource_entry(uint32_t resource_index, c_haloreach_cache_file& cache_file) :
	cache_file(cache_file),
	entry(*new s_render_texture_interop_definition_struct()),
	resource_data(nullptr),
	file_page(nullptr)
{
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

	resource_data = &cache_file_resource_gestalt->resources_block[resource_index];

	char* const naive_resource_control_data = cache_file.get_tag_data(cache_file_resource_gestalt->naive_resource_control_data); // #TODO: virtual tag data [tag_data.get_data()]
	char* const data = naive_resource_control_data + resource_data->naive_data_offset;

	DEBUG_ASSERT(resource_data->control_size == sizeof(s_render_texture_interop_definition_struct));
	memcpy(&entry, data, sizeof(s_render_texture_interop_definition_struct));

	if (cache_file.cluster != nullptr)
	{
		auto& section = cache_file_resource_layout_table->sections_block[resource_data->page];

		uint32_t page_offsets[2] = {};
		for (uint32_t i = 0; i < 2; i++)
		{
			uint32_t page_index = section.file_page_indexes[i].page_index;
			if (page_index != -1)
			{
				file_page = &cache_file_resource_layout_table->file_pages_block[page_index];
				uint32_t page_offset = cache_file.page_file_manager->encode_page_address(page_index, section.page_offsets[i].offset);

				page_offsets[i] = page_offset;
			}
		}
		entry.pixel_data.address = page_offsets[0];
		entry.high_res_data.address = page_offsets[1];

		if (page_offsets[0] || page_offsets[1])
		{
			entry.d3d_data.descriptor = 0x5EFF44C5;
			entry.d3d_data.definition_address = 0;
		}
		else
		{
			entry.pixel_data.address = 0x0EEFBEEF;
			entry.high_res_data.address = 0x0EEFBEEF;
		}
	}
}

c_bitmap_texture_interop_resource_entry::~c_bitmap_texture_interop_resource_entry()
{
	delete& entry;
}

void* c_bitmap_texture_interop_resource_entry::get_pageable_data()
{
	return &entry;
}

uint32_t c_bitmap_texture_interop_resource_entry::get_compressed_size()
{
	if (file_page != nullptr)
	{
		return file_page->file_size;
	}
	return 0;
}

uint32_t c_bitmap_texture_interop_resource_entry::get_uncompressed_size()
{
	if (file_page != nullptr)
	{
		return file_page->size;
	}
	return 0;
}
