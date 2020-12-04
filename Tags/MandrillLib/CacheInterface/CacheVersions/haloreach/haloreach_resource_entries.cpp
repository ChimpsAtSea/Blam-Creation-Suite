#include "mandrilllib-private-pch.h"

using namespace blofeld;
using namespace blofeld::haloreach;

static constexpr size_t y = sizeof(s_render_texture_interop_definition_struct);
static constexpr size_t x = offsetof(s_render_texture_interop_definition_struct, d3d_data);
static_assert(x == 60, "");

c_bitmap_texture_interop_resource_entry::c_bitmap_texture_interop_resource_entry(char* data) :
	entry(*new s_render_texture_interop_definition_struct())
{
	memcpy(&entry, data, sizeof(s_render_texture_interop_definition_struct));

	entry.pixel_data.address = 0x5EFF44C5;
	entry.high_res_data.address = 0x5EFF44C5;
	entry.d3d_data.descriptor = 0x5EFF44C5;
	entry.d3d_data.definition_address = 0;
}

c_bitmap_texture_interop_resource_entry::~c_bitmap_texture_interop_resource_entry()
{
	delete& entry;
}

void* c_bitmap_texture_interop_resource_entry::get_data()
{
	return &entry;
}

uint32_t c_bitmap_texture_interop_resource_entry::get_data_size()
{
	return sizeof(s_render_texture_interop_definition_struct);
}
