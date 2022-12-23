#pragma once

namespace blofeld
{
	namespace haloreach
	{
		namespace xbox360
		{
			class h_bitmap_block_struct;
		}
	}
}

class c_render_context;

class c_haloreach_bitmap_test
{
public:
	c_haloreach_bitmap_test(
		c_render_context& parent_render_context,
		blofeld::haloreach::xbox360::h_bitmap_block_struct& bitmap_struct);
	~c_haloreach_bitmap_test();

	c_render_context& parent_render_context;
	blofeld::haloreach::xbox360::h_bitmap_block_struct& bitmap_struct;

	void draw_ui();
	void _export(const char* filepath);
};
