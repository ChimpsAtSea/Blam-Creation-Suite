#include "texturetest-private-pch.h"

using namespace blofeld::halo3::pc64;

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("TextureTest") : BCS_S_OK;

	s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };

	const blofeld::s_tag_group* bitmap_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, blofeld::halo3::pc64::BITMAP_TAG);
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

	unsigned int num_layers = 1;
	for (unsigned int layer_index = 0; layer_index < num_layers; layer_index++)
	{
		auto& bitmap_entry = bitmap->bitmaps_block.emplace_back();

		int width = 4;
		int height = 4;

		std::vector<char> source_data;
		source_data.resize(width * height * 4);

		std::vector<char> processed_pixel_data = {
			255i8, 0i8, 0i8, 0i8,
			0i8, 255i8, 0i8, 0i8,
			0i8, 0i8, 255i8, 0i8,
			255i8, 255i8, 255i8, 0i8,


			0i8, 255i8, 0i8, 0i8,
			0i8, 0i8, 255i8, 0i8,
			255i8, 255i8, 255i8, 0i8,
			255i8, 0i8, 0i8, 0i8,


			0i8, 0i8, 255i8, 0i8,
			255i8, 255i8, 255i8, 0i8,
			255i8, 0i8, 0i8, 0i8,
			0i8, 255i8, 0i8, 0i8,


			0i8, 255i8, 0i8, 0i8,
			0i8, 0i8, 255i8, 0i8,
			255i8, 255i8, 255i8, 0i8,
			255i8, 0i8, 0i8, 0i8,
		};
		processed_pixel_data.resize(width * height * 4);

		bitmap_entry.signature = BITMAP_TAG;
		bitmap_entry.width = width;
		bitmap_entry.height = height;
		bitmap_entry.depth = 1;
		bitmap_entry.more_flags;
		bitmap_entry.type = _bitmap_types__2d_texture;
		bitmap_entry.format = _bitmap_formats_a8r8g8b8;
		bitmap_entry.flags.set(_bitmap_flags_power_of_two_dimensions, bitmap_entry.width == bitmap_entry.height);
		bitmap_entry.flags.set(_bitmap_flags_compressed, false);
		bitmap_entry.registration_point = { 0, 0 };
		bitmap_entry.mipmap_count = 0;
		bitmap_entry.curve = _bitmap_curve_enum_srgb;
		bitmap_entry.interleaved_interop = 0;
		bitmap_entry.interleaved_texture_index = 0;
		bitmap_entry.pixels_offset = bitmap->processed_pixel_data.size();
		bitmap_entry.pixels_size = processed_pixel_data.size();
		bitmap_entry.high_res_pixels_offset_offset = 0;
		bitmap_entry.high_res_pixels_size = 0;
		bitmap_entry.hardware_format = -1;
		bitmap_entry.runtime_tag_base_address = 0;

		//bitmap->source_data.insert(
		//	bitmap->source_data.end(),
		//	source_data.begin(),
		//	source_data.end());

		bitmap->processed_pixel_data.insert(
			bitmap->processed_pixel_data.end(), 
			processed_pixel_data.begin(),
			processed_pixel_data.end());
	}

	const char* tags_directory;
	BCS_RESULT get_command_line_argument_result2 = command_line_get_argument("tagsdir", tags_directory);
	BCS_FAIL_THROW(get_command_line_argument_result2);

	char bitmap_filepath[260];
	memcpy(bitmap_filepath, tags_directory, strlen(tags_directory) + 1);
	strcat_s(bitmap_filepath, "texturetest.bitmap");

	c_high_level_tag_file_writer tag_file_writer(engine_platform_build, bitmap_filepath, bitmap_tag);

	debug_point;

	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
