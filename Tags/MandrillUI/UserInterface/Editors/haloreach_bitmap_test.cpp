#include "mandrillui-private-pch.h"
#include <Generated/high_level_haloreach_xbox360/highlevel-haloreach-xbox360-public-pch.h>

#include <dxgiformat.h>
#include <GraphicsLib/dds.h>
#include "surface.h"

c_haloreach_bitmap_test::c_haloreach_bitmap_test(
	c_render_context& parent_render_context,
	blofeld::haloreach::xbox360::h_bitmap_block_struct& bitmap_struct) :
	parent_render_context(parent_render_context),
	bitmap_struct(bitmap_struct)
{
	debug_point;
}

c_haloreach_bitmap_test::~c_haloreach_bitmap_test()
{
}

void c_haloreach_bitmap_test::draw_ui()
{
	ImGui::TextUnformatted(bitmap_struct.get_file_path());

	static bool _auto_run_restore_bitmap_test = BCS_SUCCEEDED(command_line_has_argument("autorunbitmaptest"));
	bool auto_run_restore_bitmap_test = _auto_run_restore_bitmap_test;
	_auto_run_restore_bitmap_test = false;

	if (!bitmap_struct.hardware_textures_block.empty())
	{
		if (ImGui::Button("Restore Bitmap Data from Resource") || auto_run_restore_bitmap_test)
		{
			h_resource* resource = bitmap_struct.hardware_textures_block.front().texture_resource.value;

			if (resource == nullptr)
			{
				ImGui::TextUnformatted("Resource is null");
				return;
			}

			const void* resource_data;
			unsigned long resource_data_size;
			if (BCS_SUCCEEDED(resource->add_reference(resource_data, resource_data_size)))
			{
				size_t dds_file_buffer_size = sizeof(unsigned long) + sizeof(DirectX::DDS_HEADER) + resource_data_size * 2;
				char* const dds_file_buffer = static_cast<char*>(tracked_malloc(dds_file_buffer_size));

				unsigned long* magic_ptr = reinterpret_cast<unsigned long*>(dds_file_buffer);
				DirectX::DDS_HEADER* dds_header_ptr = next_contiguous_pointer(DirectX::DDS_HEADER, magic_ptr);
				unsigned char* texture_data = next_contiguous_pointer(unsigned char, dds_header_ptr);

				*magic_ptr = DirectX::DDS_MAGIC;

				dds_header_ptr->size = sizeof(DirectX::DDS_HEADER);
				dds_header_ptr->flags = DDS_HEADER_FLAGS_TEXTURE | DDS_HEADER_FLAGS_MIPMAP | DDS_HEADER_FLAGS_LINEARSIZE;
				dds_header_ptr->height = bitmap_struct.xenon_bitmaps_block.front().height;
				dds_header_ptr->width = bitmap_struct.xenon_bitmaps_block.front().width;
				dds_header_ptr->pitchOrLinearSize = resource_data_size;
				dds_header_ptr->pitchOrLinearSize = dds_header_ptr->width;
				dds_header_ptr->depth = 0;
				dds_header_ptr->mipMapCount = 1;
				dds_header_ptr->ddspf = DirectX::DDSPF_L8;
				dds_header_ptr->caps = DDS_SURFACE_FLAGS_TEXTURE | DDS_SURFACE_FLAGS_MIPMAP;


				unsigned long num_src_bytes = resource_data_size;
				unsigned char* const src_untiled_texture_data = static_cast<unsigned char*>(tracked_malloc(num_src_bytes));
				{
					const unsigned char* src_texture_data = reinterpret_cast<const unsigned char*>(resource_data);

					unsigned long RowPitch = (dds_header_ptr->width / 4) * 8;
					UntileSurface(src_untiled_texture_data, RowPitch, 0, (void*)src_texture_data, dds_header_ptr->width / 4, dds_header_ptr->height / 4, 0, 8);

					// endian swap
					unsigned short* src_untiled_texture_data_ul = reinterpret_cast<unsigned short*>(src_untiled_texture_data);
					for (unsigned short src_byte_index = 0; src_byte_index < num_src_bytes / sizeof(unsigned short); src_byte_index++)
					{
						src_untiled_texture_data_ul[src_byte_index] = _byteswap_ushort(src_untiled_texture_data_ul[src_byte_index]);
					}

					debug_point;
				}

				unsigned long num_dst_pixels = dds_header_ptr->width * dds_header_ptr->height;
				unsigned char* const pixel_block_data = static_cast<unsigned char*>(tracked_malloc(num_dst_pixels));
				{
					unsigned char* dst_texture_data = pixel_block_data;
					unsigned char* src_untiled_texture_data_pos = src_untiled_texture_data;
					for (unsigned long pixel_index = 0; pixel_index < num_dst_pixels; pixel_index += 4)
					{
						unsigned char p1 = *src_untiled_texture_data_pos >> 4;
						unsigned char p0 = *src_untiled_texture_data_pos & 0xF;
						src_untiled_texture_data_pos++;

						unsigned char p3 = *src_untiled_texture_data_pos >> 4;
						unsigned char p2 = *src_untiled_texture_data_pos & 0xF;
						src_untiled_texture_data_pos++;


						*dst_texture_data = p0;
						*dst_texture_data <<= 4;
						dst_texture_data++;

						*dst_texture_data = p1;
						*dst_texture_data <<= 4;
						dst_texture_data++;

						*dst_texture_data = p2;
						*dst_texture_data <<= 4;
						dst_texture_data++;

						*dst_texture_data = p3;
						*dst_texture_data <<= 4;
						dst_texture_data++;
					}

					debug_point;
				}

				{
					unsigned long block_pixel_width = 4;
					unsigned long block_pixel_height = 4;
					unsigned long block_pixel_size = block_pixel_width * block_pixel_height;

					unsigned long num_blocks = num_dst_pixels / block_pixel_size;
					unsigned long width_blocks = num_blocks / (dds_header_ptr->height / block_pixel_height);

					for (unsigned long pixel_index = 0; pixel_index < num_dst_pixels; pixel_index++)
					{
						unsigned long pixel_x = pixel_index % dds_header_ptr->width;
						unsigned long pixel_y = pixel_index / dds_header_ptr->height;

						unsigned long block_width = 4;
						unsigned long block_height = 4;
						unsigned long block_size = block_width * block_height;
						unsigned long block_x = pixel_x / block_width;
						unsigned long block_y = pixel_y / block_height;
						unsigned long block_offset_x = pixel_x % 4;
						unsigned long block_offset_y = pixel_y % 4;
						unsigned long block_index = block_y * width_blocks + block_x;

						unsigned long src_pixel_index = block_index * block_size + block_offset_y * 4 + block_offset_x;

						texture_data[pixel_index] = pixel_block_data[src_pixel_index];

						debug_point;
					}

					debug_point;
				}

				//memcpy(texture_data, resource_data, resource_data_size);

				filesystem_write_file_from_memory("bitmap_test.dds", dds_file_buffer, dds_file_buffer_size);
				ASSERT(BCS_SUCCEEDED(resource->remove_reference()));

				bitmap_struct.processed_pixel_data.insert(bitmap_struct.processed_pixel_data.begin(), texture_data, texture_data + num_dst_pixels);
				bitmap_struct.xenon_bitmaps_block.clear();
				bitmap_struct.hardware_textures_block.clear();

				debug_point;

				tracked_free(pixel_block_data);
				tracked_free(src_untiled_texture_data);
				tracked_free(dds_file_buffer);
			}
		}
	}

	// serialize the tag
	if (ImGui::Button("Serialize Bitmap Data") || auto_run_restore_bitmap_test)
	{

		debug_point;
	}
}

void c_haloreach_bitmap_test::_export(const char* filepath)
{
	s_engine_platform_build engine_platform_build = { _engine_type_haloreach, _platform_type_pc_64bit, _build_haloreach_tags };
	c_high_level_tag_file_writer tag_file_writer(engine_platform_build, filepath, bitmap_struct);
}