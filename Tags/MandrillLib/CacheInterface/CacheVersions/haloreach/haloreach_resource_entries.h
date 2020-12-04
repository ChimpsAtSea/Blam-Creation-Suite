#pragma once

namespace blofeld
{
	namespace haloreach
	{
		struct s_render_texture_interop_definition_struct;
	}
}

class c_bitmap_texture_interop_resource_entry :
	public c_resource_entry
{
public:
	c_bitmap_texture_interop_resource_entry(char* data);
	~c_bitmap_texture_interop_resource_entry();
	virtual void* get_data();
	static uint32_t get_data_size();
	blofeld::haloreach::s_render_texture_interop_definition_struct& entry;
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

