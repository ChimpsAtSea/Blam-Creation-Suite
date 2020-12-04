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
	DEBUG_ASSERT(resource_data->resource_type_index == _haloreach_resource_type_bitmap_texture_interop_resource);

	char* const naive_resource_control_data = cache_file.get_tag_data(cache_file_resource_gestalt->naive_resource_control_data); // #TODO: virtual tag data [tag_data.get_data()]
	char* const data = naive_resource_control_data + resource_data->naive_data_offset;

	DEBUG_ASSERT(resource_data->control_size == sizeof(s_render_texture_interop_definition_struct));
	memcpy(&entry, data, sizeof(s_render_texture_interop_definition_struct));

	if (cache_file.cluster != nullptr)
	{
		auto& section = cache_file_resource_layout_table->sections_block[resource_data->page];
		//DEBUG_ASSERT(section.file_page_indexes[0].page_index != -1);

		if (section.file_page_indexes[0].page_index != -1)
		{
			file_page = &cache_file_resource_layout_table->file_pages_block[section.file_page_indexes[0].page_index];

			uint32_t cluster_cache_file_index = -1;
			if (file_page->shared_file == -1) // local file
			{
				cluster_cache_file_index = 2;
			}
			else
			{
				auto& shared_file = cache_file_resource_layout_table->shared_files_block[file_page->shared_file];
				const char* dvd_path = shared_file.dvd_relative_path.get_buffer();

				// #TODO: Clean this up, this is super bad!!!!!!!!!!!

				if (_stricmp(dvd_path, "maps\\shared.map") == 0)
				{
					cluster_cache_file_index = 0;
				}
				else if (_stricmp(dvd_path, "maps\\shared.map") == 0)
				{
					cluster_cache_file_index = 1;
				}
				else if (_stricmp(dvd_path, "maps\\english.map") == 0)
				{

				}
				else DEBUG_ONLY(FATAL_ERROR(L"Unknown resource cache file"));
			}

			if (cluster_cache_file_index != -1)
			{
				uint32_t file_offset = file_page->file_offset + section.page_offsets[0].offset;
				uint32_t page_offset = cache_file.cluster->encode_page_address(cluster_cache_file_index, file_offset);

				entry.pixel_data.address = page_offset;
				entry.high_res_data.address = page_offset; // #TODO: offset to correct spot
				entry.d3d_data.descriptor = 0x5EFF44C5;
				entry.d3d_data.definition_address = 0;

				debug_point;
			}
			else
			{

				debug_point;
			}
		}
		else
		{
			entry.pixel_data.address = 0xBEEFBEEF;
			entry.high_res_data.address = 0xBEEFBEEF;
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
