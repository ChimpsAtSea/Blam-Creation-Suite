#pragma once

namespace blofeld
{
	namespace haloreach
	{
		struct s_render_texture_interop_definition_struct;
		struct s_cache_file_resource_data_block_block_struct;
		struct s_cache_file_resource_page_struct;
	}
}

class c_haloreach_cache_file;

enum e_haloreach_resource_type : char
{
	_haloreach_resource_type_bitmap_texture_interop_resource,
	_haloreach_resource_type_render_geometry_api_resource_definition,
	_haloreach_resource_type_constant_buffer_resource_definition,
	_haloreach_resource_type_sound_resource_definition,
	_haloreach_resource_type_model_animation_tag_resource,
	_haloreach_resource_type_structure_bsp_tag_resources,
	_haloreach_resource_type_structure_bsp_cache_file_tag_resources,
	_haloreach_resource_type_invalid = 0xFFi8
};

class c_bitmap_texture_interop_resource_entry :
	public c_resource_entry
{
public:
	c_bitmap_texture_interop_resource_entry(uint32_t resource_index, c_haloreach_cache_file& cache_file);
	~c_bitmap_texture_interop_resource_entry();
	virtual void* get_pageable_data();
	virtual uint32_t get_compressed_size();
	virtual uint32_t get_uncompressed_size();
	c_haloreach_cache_file& cache_file;
	blofeld::haloreach::s_render_texture_interop_definition_struct& entry;
	blofeld::haloreach::s_cache_file_resource_data_block_block_struct* resource_data;
	blofeld::haloreach::s_cache_file_resource_page_struct* file_page;
};

class c_render_geometry_api_resource_definition_entry :
	public c_resource_entry
{
public:

};

class c_constant_buffer_resource_definition_entry :
	public c_resource_entry
{
public:

};

class c_sound_resource_definition_entry :
	public c_resource_entry
{
public:

};

class c_model_animation_tag_resource_entry :
	public c_resource_entry
{
public:

};

class c_structure_bsp_tag_resources_entry :
	public c_resource_entry
{
public:

};

class c_structure_bsp_cache_file_tag_resources_entry :
	public c_resource_entry
{
public:

};

