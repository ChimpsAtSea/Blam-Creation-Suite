#include "texturetest-private-pch.h"

using namespace blofeld::halo3::pc64;

struct s_graphics_data_format_lookup
{
	e_bitmap_formats bitmap_format;
	e_graphics_data_format graphics_data_format;
	e_graphics_data_format graphics_data_format_srgb;
};

static constexpr s_type_lookup<e_bitmap_formats, s_graphics_data_format_lookup> texture_format_lookup[] =
{
#define texture_format(bitmap_format, graphics_data_format, graphics_data_format_srgb) { bitmap_format, { bitmap_format, graphics_data_format, graphics_data_format_srgb } }
	texture_format(_bitmap_formats_a8, _graphics_data_format_a8_unorm, _graphics_data_format_a8_unorm),
	texture_format(_bitmap_formats_y8, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_ay8, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_a8y8, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_r8, _graphics_data_format_r8_unorm, _graphics_data_format_r8_unorm),
	texture_format(_bitmap_formats_unused2, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_r5g6b5, _graphics_data_format_b5g6r5_unorm, _graphics_data_format_b5g6r5_unorm),
	texture_format(_bitmap_formats_unused3, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_a1r5g5b5, _graphics_data_format_b5g5r5a1_unorm, _graphics_data_format_b5g5r5a1_unorm),
	texture_format(_bitmap_formats_a4r4g4b4, _graphics_data_format_b4g4r4a4_unorm, _graphics_data_format_b4g4r4a4_unorm),
	texture_format(_bitmap_formats_x8r8g8b8, _graphics_data_format_b8g8r8x8_unorm, _graphics_data_format_b8g8r8x8_unorm_srgb),
	texture_format(_bitmap_formats_a8r8g8b8, _graphics_data_format_b8g8r8a8_unorm, _graphics_data_format_b8g8r8a8_unorm_srgb),
	texture_format(_bitmap_formats_unused4, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_unused5, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxt1, _graphics_data_format_bc1_unorm, _graphics_data_format_bc1_unorm_srgb),
	texture_format(_bitmap_formats_dxt3, _graphics_data_format_bc2_unorm, _graphics_data_format_bc2_unorm_srgb),
	texture_format(_bitmap_formats_dxt5, _graphics_data_format_bc3_unorm, _graphics_data_format_bc3_unorm_srgb),
	texture_format(_bitmap_formats_a4r4g4b4_font, _graphics_data_format_b4g4r4a4_unorm, _graphics_data_format_b4g4r4a4_unorm),
	texture_format(_bitmap_formats_unused7, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_unused8, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_software_rgbfp32, _graphics_data_format_r32g32b32_float, _graphics_data_format_r32g32b32_float),
	texture_format(_bitmap_formats_unused9, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_v8u8, _graphics_data_format_r8g8_unorm, _graphics_data_format_r8g8_unorm),
	texture_format(_bitmap_formats_g8b8, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_abgrfp32, _graphics_data_format_r32g32b32a32_float, _graphics_data_format_r32g32b32a32_float),
	texture_format(_bitmap_formats_abgrfp16, _graphics_data_format_r16g16b16a16_float, _graphics_data_format_r16g16b16a16_float),
	texture_format(_bitmap_formats_q8w8v8u8, _graphics_data_format_r8g8b8a8_unorm, _graphics_data_format_r8g8b8a8_unorm_srgb),
	texture_format(_bitmap_formats_a2r10g10b10, _graphics_data_format_r10g10b10a2_unorm, _graphics_data_format_r10g10b10a2_unorm),
	texture_format(_bitmap_formats_a16b16g16r16, _graphics_data_format_r16g16b16a16_uint, _graphics_data_format_r16g16b16a16_uint),
	texture_format(_bitmap_formats_v16u16, _graphics_data_format_r16g16_float, _graphics_data_format_r16g16_float),
	texture_format(_bitmap_formats_dxt3a, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxt5a, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxt3a_1111, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxn, _graphics_data_format_bc5_snorm, _graphics_data_format_bc5_snorm),
	texture_format(_bitmap_formats_ctx1, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxt3a_alpha, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxt3a_mono, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxt5a_alpha, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxt5a_mono, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
	texture_format(_bitmap_formats_dxn_mono_alpha, _graphics_data_format_unspecified, _graphics_data_format_unspecified),
#undef texture_format
};
static_assert(_countof(texture_format_lookup) == k_bitmap_formats_count);
static_assert(is_enum_lookup_valid(texture_format_lookup));

BCS_RESULT graphics_data_format_to_halo3_bitmap_format(e_graphics_data_format graphics_data_format, e_bitmap_formats& bitmap_format)
{
	for (auto& texture_format : texture_format_lookup)
	{
		if (texture_format.value.graphics_data_format == graphics_data_format || texture_format.value.graphics_data_format_srgb == graphics_data_format)
		{
			bitmap_format = texture_format._enum;
			return BCS_S_OK;
		}
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT halo3_bitmap_format_to_graphics_data_format(e_bitmap_formats bitmap_format, bool is_srgb, e_graphics_data_format& graphics_data_format)
{
	if (is_srgb)
	{
		graphics_data_format = texture_format_lookup[bitmap_format].value.graphics_data_format_srgb;
	}
	else
	{
		graphics_data_format = texture_format_lookup[bitmap_format].value.graphics_data_format;
	}
	return BCS_S_OK;
}

extern "C" int bcs_main()
{
	BCS_RESULT rs2 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("TextureTest") : BCS_S_OK;

	const wchar_t* texture_file_path;
	BCS_RESULT get_command_line_argument_result = command_line_get_argument(L"texturepath", texture_file_path);
	BCS_FAIL_THROW(get_command_line_argument_result);

	const wchar_t* texture_file_extenson = filesystem_extract_filepath_extension(texture_file_path);


	c_texture* texture;
	BCS_RESULT texture_load_from_file_result = texture_load_from_file(texture_file_path, texture);
	ASSERT(BCS_SUCCEEDED(texture_load_from_file_result));

	e_graphics_data_format graphics_data_format;
	BCS_RESULT get_graphics_data_format_result = texture->get_graphics_data_format(graphics_data_format);
	ASSERT(BCS_SUCCEEDED(get_graphics_data_format_result));

	unsigned int num_layers = texture->get_num_layers();
	unsigned int num_mips = texture->get_num_mips();
	unsigned int width = texture->get_width(0);
	unsigned int height = texture->get_height(0);
	unsigned int depth = texture->get_depth(0);

	// #TODO: Hack to fix gif import
	if (wcsicmp(texture_file_extenson, L".gif") == 0)
	{
		unsigned int bits_per_pixel;
		BCS_RESULT graphics_data_format_to_bits_per_pixel_result = graphics_data_format_to_bits_per_pixel(graphics_data_format, bits_per_pixel);
		ASSERT(BCS_SUCCEEDED(graphics_data_format_to_bits_per_pixel_result));

		if (bits_per_pixel == 32)
		{
			const char* previous_layer_pixel_data;
			size_t previous_layer_pixel_data_size;
			BCS_RESULT get_layer_data_result = texture->get_layer_data(0, 0, previous_layer_pixel_data, previous_layer_pixel_data_size);

			for (unsigned int layer_index = 1; layer_index < num_layers; layer_index++)
			{
				const char* current_layer_pixel_data;
				size_t current_layer_pixel_data_size;
				BCS_RESULT get_layer_data_result2 = texture->get_layer_data(layer_index, 0, current_layer_pixel_data, current_layer_pixel_data_size);

				int* current_layer_pixel_data_pos = reinterpret_cast<int*>(const_cast<char*>(current_layer_pixel_data));
				int* previous_layer_pixel_data_pos = reinterpret_cast<int*>(const_cast<char*>(previous_layer_pixel_data));
				for (unsigned int row = 0; row < height; row++)
				{
					for (unsigned int column = 0; column < width; column++)
					{
						int& pixel = current_layer_pixel_data_pos[column];
						if ((pixel & 0xff000000) == 0)
						{
							pixel = previous_layer_pixel_data_pos[column];
						}
					}
					current_layer_pixel_data_pos += width;
					previous_layer_pixel_data_pos += width;
				}

				previous_layer_pixel_data = current_layer_pixel_data;
				previous_layer_pixel_data_size = current_layer_pixel_data_size;
			}
		}
	}

	// make sure that the bitmap format is supported otherwise convert to a default format
	e_bitmap_formats bitmap_format;
	BCS_RESULT graphics_data_format_to_halo3_bitmap_format_result = graphics_data_format_to_halo3_bitmap_format(graphics_data_format, bitmap_format);
	if (BCS_FAILED(graphics_data_format_to_halo3_bitmap_format_result))
	{
		// #TODO: Suggest a best case compatible format to use based off the old graphics_data_format

		BCS_RESULT convert_to_graphics_data_format_result = texture->convert_to_graphics_data_format(_graphics_data_format_b8g8r8a8_unorm);
		ASSERT(BCS_SUCCEEDED(convert_to_graphics_data_format_result));

		BCS_RESULT get_graphics_data_format_result = texture->get_graphics_data_format(graphics_data_format);
		ASSERT(BCS_SUCCEEDED(get_graphics_data_format_result));

		BCS_RESULT graphics_data_format_to_halo3_bitmap_format_result = graphics_data_format_to_halo3_bitmap_format(graphics_data_format, bitmap_format);
		ASSERT(BCS_SUCCEEDED(graphics_data_format_to_halo3_bitmap_format_result));
	}


	// textures of size 1x1x1 are invalid
	// #NOTE: Anything except a 1x1 is counted as valid, by default the tools resize to a 4x4 for some reason
	if (width == 1 && height == 1 && depth == 1)
	{
		BCS_RESULT resize_result = texture->resize(4, 4, 4);
		ASSERT(BCS_SUCCEEDED(resize_result));

		width = texture->get_width(0);
		height = texture->get_height(0);
		depth = texture->get_depth(0);
	}
	else
	{
		BCS_RESULT generate_mips_result = texture->generate_mips();
		ASSERT(BCS_SUCCEEDED(generate_mips_result));

		num_mips = texture->get_num_mips();
	}

	BCS_RESULT convert_to_graphics_data_format_result = texture->convert_to_graphics_data_format(_graphics_data_format_bc3_unorm_srgb);
	ASSERT(BCS_SUCCEEDED(convert_to_graphics_data_format_result));

	BCS_RESULT get_graphics_data_format_result2 = texture->get_graphics_data_format(graphics_data_format);
	ASSERT(BCS_SUCCEEDED(get_graphics_data_format_result2));

	BCS_RESULT graphics_data_format_to_halo3_bitmap_format_result2 = graphics_data_format_to_halo3_bitmap_format(graphics_data_format, bitmap_format);
	ASSERT(BCS_SUCCEEDED(graphics_data_format_to_halo3_bitmap_format_result2));

	s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };

	blofeld::s_tag_group const* bitmap_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, blofeld::halo3::pc64::BITMAP_TAG);
	h_group* bitmap_high_level_group = new() h_group(engine_platform_build, *bitmap_tag_group);

	h_tag& bitmap_tag = bitmap_high_level_group->create_tag_instance("texturetest");

	h_bitmap_block_struct* bitmap = dynamic_cast<decltype(bitmap)>(&bitmap_tag);

	bitmap->usage;
	bitmap->flags;
	bitmap->sprite_spacing = 4;
	bitmap->bump_map_height = 5;
	bitmap->fade_factor = 0.5f;
	bitmap->curve_mode;
	bitmap->max_mipmap_level;
	bitmap->force_bitmap_format;
	bitmap->usage_override_block;
	bitmap->manual_sequences_block;
	bitmap->source_data;
	bitmap->processed_pixel_data;
	bitmap->sequences_block;
	bitmap->bitmaps_block;
	bitmap->xenon_processed_pixel_data;
	bitmap->xenon_bitmaps_block;
	bitmap->hardware_textures_block;
	bitmap->interleaved_hardware_textures_block;

	bool is_compressed;
	BCS_RESULT graphics_data_format_is_compressed_result = graphics_data_format_is_compressed(graphics_data_format, is_compressed);
	ASSERT(BCS_SUCCEEDED(graphics_data_format_is_compressed_result));

	bool is_srgb;
	BCS_RESULT graphics_data_format_is_srgb_result = graphics_data_format_is_srgb(graphics_data_format, is_srgb);
	ASSERT(BCS_SUCCEEDED(graphics_data_format_is_srgb_result));

	for (unsigned int layer_index = 0; layer_index < num_layers; layer_index++)
	{
		auto& bitmap_entry = bitmap->bitmaps_block.emplace_back();

		size_t pixel_data_start_byte_index = bitmap->processed_pixel_data.size();
		size_t total_pixel_data_size = 0;
		for (unsigned int mip_index = 0; mip_index < num_mips; mip_index++)
		{
			const char* pixel_data;
			size_t pixel_data_size;
			BCS_RESULT get_layer_data_result = texture->get_layer_data(layer_index, mip_index, pixel_data, pixel_data_size);
			ASSERT(BCS_SUCCEEDED(get_layer_data_result));

			bitmap->processed_pixel_data.insert(
				bitmap->processed_pixel_data.end(),
				pixel_data,
				pixel_data + pixel_data_size);

			total_pixel_data_size += pixel_data_size;
		}

		bitmap_entry.signature = BITMAP_TAG;
		bitmap_entry.width = width;
		bitmap_entry.height = height;
		bitmap_entry.depth = depth;
		bitmap_entry.more_flags;
		bitmap_entry.type = _bitmap_types__2d_texture;
		bitmap_entry.format = bitmap_format;
		bitmap_entry.flags.set(_bitmap_flags_power_of_two_dimensions, bitmap_entry.width == bitmap_entry.height);
		bitmap_entry.flags.set(_bitmap_flags_compressed, is_compressed);
		bitmap_entry.registration_point = { 0, 0 };
		bitmap_entry.mipmap_count = num_mips - 1;
		bitmap_entry.curve = is_srgb ? _bitmap_curve_enum_srgb : _bitmap_curve_enum_linear;
		bitmap_entry.interleaved_interop = 0;
		bitmap_entry.interleaved_texture_index = 0;
		bitmap_entry.pixels_offset = pixel_data_start_byte_index;
		bitmap_entry.pixels_size = total_pixel_data_size;
		bitmap_entry.high_res_pixels_offset_offset = 0;
		bitmap_entry.high_res_pixels_size = 0;
		bitmap_entry.hardware_format = -1;
		bitmap_entry.runtime_tag_base_address = 0;

		debug_point;
	}

	const char* tags_directory;
	BCS_RESULT get_command_line_argument_result2 = command_line_get_argument("tagsdir", tags_directory);
	BCS_FAIL_THROW(get_command_line_argument_result2);

	char bitmap_filepath[260];
	memcpy(bitmap_filepath, tags_directory, strlen(tags_directory) + 1);
	strcat_s(bitmap_filepath, "texturetest.bitmap");

	c_high_level_tag_file_writer tag_file_writer(engine_platform_build, bitmap_filepath, bitmap_tag);

	debug_point;

	if (BCS_SUCCEEDED(rs2)) rs2 = deinit_console();

	BCS_FAIL_RETURN(rs2);

	return 0;
}
