#pragma once

#include <cseries/cseries.h>
#include <math/integer_math.h>
#include <math/real_math.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>
#include <tag_files/tag_resource_internals.h>

/* ---------- constants */

constexpr tag k_bitmap_group_tag = 'bitm';

constexpr int k_maximum_number_of_bitmap_usages = 1;
constexpr int k_maximum_number_of_bitmap_sequences = 256;
constexpr int k_maximum_number_of_bitmap_sequence_sprites = 512;
constexpr int k_maximum_number_of_bitmap_tight_bounds = 20;
constexpr int k_maximum_number_of_bitmap_images = 65536;

/* ---------- types */

enum e_bitmap_usage
{
	_bitmap_usage_diffuse_map,
	_bitmap_usage_specular_map,
	_bitmap_usage_bump_map,
	_bitmap_usage_detail_bump_map,
	_bitmap_usage_detail_map,
	_bitmap_usage_self_illum_map,
	_bitmap_usage_change_color_map,
	_bitmap_usage_cube_map,
	_bitmap_usage_sprite_additive,
	_bitmap_usage_sprite_blend,
	_bitmap_usage_sprite_double_multiply,
	_bitmap_usage_interface_bitmap,
	_bitmap_usage_warp_map,
	_bitmap_usage_vector_map,
	_bitmap_usage_3d_texture,
	_bitmap_usage_float_map,
	_bitmap_usage_half_float_map,
	_bitmap_usage_height_map,
	_bitmap_usage_z_brush_bump_map,
	_bitmap_usage_z_brush_normal_map,
	_bitmap_usage_detail_z_brush_bump_map,
	_bitmap_usage_detail_z_brush_normal_map,
	_bitmap_usage_blend_map,
	_bitmap_usage_palettized,
	_bitmap_usage_chud_related_bitmap,
	_bitmap_usage_lightmap_array,
	_bitmap_usage_water_array,
	_bitmap_usage_interface_sprite,
	_bitmap_usage_interface_gradient,
	_bitmap_usage_material_map,
	_bitmap_usage_smoke_warp,
	_bitmap_usage_mux_material_blend_map,
	_bitmap_usage_cubemap_gel,
	_bitmap_usage_lens_flare,
	_bitmap_usage_signed_noise,
	_bitmap_usage_roughness_map,
	_bitmap_usage_normal_map,
	_bitmap_usage_color_grading,
	_bitmap_usage_detail_normal_map,
	_bitmap_usage_diffuse_texture_array,
	_bitmap_usage_palettized_texture_array,
	_bitmap_usage_uncompressed_palette,
	_bitmap_usage_gobo,
	_bitmap_usage_flow_map,
	_bitmap_usage_linear_control_map_texture_array,
	_bitmap_usage_bump_map_texture_array,
	_bitmap_usage_detail_map_texture_array,
	_bitmap_usage_self_illum_map_texture_array,
	_bitmap_usage_sprite_additive_texture_array,
	_bitmap_usage_sprite_blend_texture_array,
	_bitmap_usage_sprite_double_multiply_texture_array,
	_bitmap_usage_warp_map_texture_array,
	_bitmap_usage_z_brush_normal_map_texture_array,
	_bitmap_usage_z_brush_detail_normal_map_texture_array,
	_bitmap_usage_lens_flare_texture_array,
	_bitmap_usage_normal_map_texture_array,
	_bitmap_usage_detail_normal_map_texture_array,
	_bitmap_usage_flow_map_texture_array,
	_bitmap_usage_sprite_normal_map,
	k_number_of_bitmap_usages
};

enum e_bitmap_flags
{
	_bitmap_is_tiled_bit,
	_bitmap_use_less_blurry_bump_map_bit,
	_bitmap_dither_when_compressing_bit,
	_bitmap_generate_random_sprites_bit,
	_bitmap_using_tag_interop_and_tag_resource_bit,
	_bitmap_ignore_alpha_channel_bit,
	_bitmap_alpha_channel_stores_transparency_bit,
	_bitmap_preserve_alpha_channel_in_mipmaps_for_alpha_test_bit,
	_bitmap_only_use_on_demand_bit,
	_bitmap_generate_tight_bounds_bit,
	_bitmap_tight_bounds_from_alpha_channel_bit,
	_bitmap_do_not_generate_required_section_bit,
	_bitmap_unused_bit,
	_bitmap_apply_max_resolution_after_slicing_bit,
	_bitmap_generate_black_point_tight_bounds_bit,
	_bitmap_pre_filter_cubemaps_bit,
	k_number_of_bitmap_flags
};

enum e_bitmap_type
{
	_bitmap_type_2d_texture,
	_bitmap_type_3d_texture,
	_bitmap_type_cube_map,
	_bitmap_type_array,
	k_number_of_bitmap_types
};

enum e_bitmap_curve
{
	_bitmap_curve_unknown,
	_bitmap_curve_xrgb,
	_bitmap_curve_gamma2,
	_bitmap_curve_linear,
	_bitmap_curve_offset_log,
	_bitmap_curve_srgb,
	_bitmap_curve_709,
	k_number_of_bitmap_curves
};

enum e_bitmap_curve_mode
{
	_bitmap_curve_mode_choose_best,
	_bitmap_curve_mode_force_fast,
	_bitmap_curve_mode_force_pretty,
	k_number_of_bitmap_curve_modes
};

enum e_bitmap_format
{
	_bitmap_format_invalid = NONE,
	_bitmap_format_a8,
	_bitmap_format_y8,
	_bitmap_format_ay8,
	_bitmap_format_a8_y8,
	_bitmap_format_unused_4,
	_bitmap_format_unused_5,
	_bitmap_format_r5_g6_b5,
	_bitmap_format_unused_7,
	_bitmap_format_a1_r5_g5_b5,
	_bitmap_format_a4_r4_g4_b4,
	_bitmap_format_x8_r8_g8_b8,
	_bitmap_format_a8_r8_g8_b8,
	_bitmap_format_unused_c,
	_bitmap_format_unused_d,
	_bitmap_format_dxt1,
	_bitmap_format_dxt3,
	_bitmap_format_dxt5,
	_bitmap_format_a4_r4_g4_b4_font,
	_bitmap_format_p8,
	_bitmap_format_argbfp32,
	_bitmap_format_rgbfp32,
	_bitmap_format_rgbfp16,
	_bitmap_format_v8_u8,
	_bitmap_format_unused_17,
	_bitmap_format_a32_b32_g32_r32_f,
	_bitmap_format_a16_b16_g16_r16_f,
	_bitmap_format_q8_w8_v8_u8,
	_bitmap_format_a2_r10_g10_b10,
	_bitmap_format_a16_b16_g16_r16,
	_bitmap_format_v16_u16,
	_bitmap_format_unused_1e,
	_bitmap_format_dxt5a,
	_bitmap_format_unused_20,
	_bitmap_format_dxn,
	_bitmap_format_ctx1,
	_bitmap_format_dxt3a_alpha,
	_bitmap_format_dxt3a_mono,
	_bitmap_format_dxt5a_alpha,
	_bitmap_format_dxt5a_mono,
	_bitmap_format_dxn_mono_alpha,
	_bitmap_format_reach_dxt3a_mono,
	_bitmap_format_reach_dxt3a_alpha,
	_bitmap_format_reach_dxt5a_mono,
	_bitmap_format_reach_dxt5a_alpha,
	_bitmap_format_reach_dxn_mono_alpha,
	k_number_of_bitmap_formats
};

enum e_bitmap_usage_flags
{
	_bitmap_usage_ignore_curve_override_bit,
	_bitmap_usage_dont_allow_size_optimization_bit,
	_bitmap_usage_swap_axes_bit,
	_bitmap_usage_pre_filter_cubemaps_bit,
	k_number_of_bitmap_usage_flags
};

enum e_bitmap_slicer_mode
{
	_bitmap_slicer_mode_automatically_determine_slicer,
	_bitmap_slicer_mode_no_slicing,
	_bitmap_slicer_mode_color_plate_slicer,
	_bitmap_slicer_mode_cube_map_slicer,
	_bitmap_slicer_mode_color_grading_slicer,
	k_number_of_bitmap_slicer_modes
};

enum e_bitmap_dicer_flags
{
	_bitmap_dicer_convert_plate_color_key_to_alpha_channel_bit,
	_bitmap_dicer_rotate_cube_map_to_match_direct_x_format_bit,
	_bitmap_dicer_shrink_elements_to_smallest_non_zero_alpha_region_bit,
	_bitmap_dicer_shrink_elements_to_smallest_non_zero_color_and_alpha_region_bit,
	_bitmap_dicer_unsigned_to_signed_scale_and_bias_bit,
	_bitmap_dicer_color_grading_s_rgb_correction_bit,
	_bitmap_dicer_color_grading_rec709_correction_bit,
	k_number_of_bitmap_dicer_flags
};

enum e_bitmap_packer_mode
{
	_bitmap_packer_mode_no_packing,
	_bitmap_packer_mode_sprite_pack,
	_bitmap_packer_mode_sprite_pack_if_needed,
	_bitmap_packer_mode_3d_pack,
	k_number_of_bitmap_packer_modes
};

enum e_bitmap_packer_flags
{
	_bitmap_packer_shrink_sprite_texture_pages_tightly_to_content_bit,
	k_number_of_bitmap_packer_flags
};

enum e_bitmap_smallest_mip
{
	_bitmap_smallest_mip_1_pixel,
	_bitmap_smallest_mip_2_pixel,
	_bitmap_smallest_mip_4_pixel,
	_bitmap_smallest_mip_8_pixel,
	_bitmap_smallest_mip_16_pixel,
	_bitmap_smallest_mip_32_pixel,
	_bitmap_smallest_mip_64_pixel,
	_bitmap_smallest_mip_128_pixel,
	_bitmap_smallest_mip_256_pixel,
	_bitmap_smallest_mip_512_pixel,
	_bitmap_smallest_mip_1024_pixel,
	k_number_of_bitmap_smallest_mips
};

enum e_bitmap_downsample_filter
{
	_bitmap_downsample_filter_point_sampled,
	_bitmap_downsample_filter_box,
	_bitmap_downsample_filter_blackman,
	_bitmap_downsample_filter_lanczos,
	_bitmap_downsample_filter_nuttall,
	_bitmap_downsample_filter_blackman_harris,
	_bitmap_downsample_filter_blackman_nuttall,
	_bitmap_downsample_filter_flat_top,
	_bitmap_downsample_filter_extreme,
	k_number_of_bitmap_downsample_filters
};

enum e_bitmap_downsample_flags
{
	_bitmap_downsample_filter_sprites_color_bleed_in_zero_alpha_regions_bit,
	_bitmap_downsample_filter_pre_multiply_alpha_before_downsampling_bit,
	_bitmap_downsample_filter_post_divide_alpha_after_downsampling_bit,
	_bitmap_downsample_filter_height_map_convert_to_bump_map_bit,
	_bitmap_downsample_filter_detail_map_fade_to_gray_bit,
	_bitmap_downsample_filter_signed_gt_unsigned_scale_and_bias_bit,
	_bitmap_downsample_filter_illum_map_fade_to_black_bit,
	_bitmap_downsample_filter_z_bump_scale_by_height_and_renormalize_bit,
	_bitmap_downsample_filter_cubemap_fix_seams_bit,
	_bitmap_downsample_filter_calculate_specular_power_bit,
	_bitmap_downsample_filter_downsample_bumps_in_angular_space_bit,
	_bitmap_downsample_filter_standard_orientation_of_normals_in_angular_space_and_renormalize_bit,
	_bitmap_downsample_filter_generate_rgb_luminance_into_alpha_channel_bit,
	k_number_of_bitmap_downsample_flags
};

enum e_bitmap_swizzle
{
	_bitmap_swizzle_default,
	_bitmap_swizzle_source_red_channel,
	_bitmap_swizzle_source_green_channel,
	_bitmap_swizzle_source_blue_channel,
	_bitmap_swizzle_source_alpha_channel,
	_bitmap_swizzle_set_to_1_0,
	_bitmap_swizzle_set_to_0_0,
	_bitmap_swizzle_set_to_0_5,
	_bitmap_swizzle_random,
	k_number_of_bitmap_swizzles
};

enum e_bitmap_image_flags
{
	_bitmap_image_power_of_two_dimensions_bit,
	_bitmap_image_compressed_bit,
	_bitmap_image_palettized_bit,
	_bitmap_image_swizzled_bit,
	_bitmap_image_linear_bit,
	_bitmap_image_v16u16_bit,
	_bitmap_image_mip_map_debug_level_bit,
	_bitmap_image_prefer_stutter_bit,
	_bitmap_image_unknown8_bit,
	_bitmap_image_always_on_bit,
	_bitmap_image_unknown10_bit,
	_bitmap_image_unknown11_bit,
	_bitmap_image_interlaced_bit,
	_bitmap_image_unknown13_bit,
	_bitmap_image_unknown14_bit,
	_bitmap_image_unknown15_bit,
	k_number_of_bitmap_image_flags
};

enum e_bitmap_more_image_flags
{
	_bitmap_image_xbox360_medium_resolution_offset_is_valid_bit,
	_bitmap_image_xbox360_memory_spacing_bit,
	_bitmap_image_xbox360_uchar_order_bit,
	_bitmap_image_xbox360_tiled_texture_bit,
	_bitmap_image_xbox360_created_correctly_bit,
	_bitmap_image_xbox360_high_resolution_offset_is_valid_bit,
	_bitmap_image_xbox360_use_interleaved_textures_bit,
	_bitmap_image_xbox360_use_on_demand_only_bit,
	k_number_of_bitmap_more_image_flags
};

struct s_bitmap_usage
{
	real source_gamma;
	c_enum<e_bitmap_curve, long> bitmap_curve;
	c_flags<e_bitmap_usage_flags, byte> flags;
	c_enum<e_bitmap_slicer_mode, char> slicer;
	c_enum<e_bitmap_dicer_flags, byte> dicer_flags;
	c_enum<e_bitmap_packer_mode, char> packer;
	c_flags<e_bitmap_packer_flags, byte> packer_flags;
	c_enum<e_bitmap_type, char> type;
	char mipmap_limit;
	c_enum<e_bitmap_smallest_mip, char> smallest_mip;
	c_enum<e_bitmap_downsample_filter, char> downsample_filter;
	char filter_radius_bias;
	c_flags<e_bitmap_downsample_flags, word> downsample_flags;
	s_real_rgb_color sprite_background_color;
	c_enum<e_bitmap_swizzle, char> swizzle_red;
	c_enum<e_bitmap_swizzle, char> swizzle_green;
	c_enum<e_bitmap_swizzle, char> swizzle_blue;
	c_enum<e_bitmap_swizzle, char> swizzle_alpha;
	c_enum<e_bitmap_format, long> format;
};
static_assert(sizeof(s_bitmap_usage) == 0x28);

struct s_bitmap_sequence_sprite
{
	short bitmap_index;
	short : 16;
	long : 32;
	real left;
	real right;
	real top;
	real bottom;
	s_real_point2d registration_point;
};
static_assert(sizeof(s_bitmap_sequence_sprite) == 0x20);

struct s_bitmap_sequence
{
	c_static_string<32> name;
	short first_bitmap_index;
	short bitmap_count;
	long : 32;
	long : 32;
	long : 32;
	long : 32;
	c_typed_tag_block<s_bitmap_sequence_sprite> sprites;
};
static_assert(sizeof(s_bitmap_sequence) == 0x40);

struct s_bitmap_tight_bounds
{
	real u;
	real v;
};
static_assert(sizeof(s_bitmap_tight_bounds) == 0x8);

struct s_bitmap_image
{
	short width;
	short height;
	char depth;
	c_flags<e_bitmap_more_image_flags, byte> more_flags;
	c_enum<e_bitmap_type, char> type;
	char four_times_log2_size;
	c_enum<e_bitmap_format, short> format;
	c_flags<e_bitmap_image_flags, word> flags;
	s_point2d registration_point;
	char mipmap_count;
	c_enum<e_bitmap_curve, char> curve;
	char : 8;
	char interleaved_texture_index;

	long pixels_offset; // offset into resource pixel_data
	long pixels_size;

	long high_res_pixels_offset; // offset into high_res resource pixel_data
	long high_res_pixels_size;

	void *pixels_address;
	void *high_res_pixels_address;
};
static_assert_64(sizeof(s_bitmap_image) == 0x38);

struct s_bitmap_resource_info
{
	s_tag_resource resource;
};
static_assert_64(sizeof(s_bitmap_resource_info) == 0x8);

struct s_bitmap_definition
{
	c_enum<e_bitmap_usage, long> usage;
	c_flags<e_bitmap_flags, word> flags;
	short sprite_spacing;
	real bump_map_height;
	real fade_factor;
	real blur;
	real mipmap_blur;
	c_enum<e_bitmap_curve_mode, char> curve_mode;
	char max_mipmap_level;
	short max_resolution;
	short atlas;
	c_enum<e_bitmap_format, short> force_bitmap_format;
	real tight_bounds_threshold;
	c_typed_tag_block<e_bitmap_usage> usage_override;
	c_typed_tag_block<s_bitmap_sequence> manual_sequences;
	c_typed_tag_block<s_bitmap_tight_bounds> tight_bounds;
	s_tag_data source_data;
	s_tag_data processed_pixel_data;
	c_typed_tag_block<s_bitmap_sequence> sequences;
	c_typed_tag_block<s_bitmap_image> images;
	s_tag_data xenon_processed_pixel_data;
	c_typed_tag_block<s_bitmap_image> xenon_images;
	c_typed_tag_block<s_bitmap_resource_info> resources;
	c_typed_tag_block<s_bitmap_resource_info> interleaved_resources;
};
static_assert_64(sizeof(s_bitmap_definition) == 0xC0);

struct s_bitmap_texture_resource
{
	s_tag_data import_data;
	s_tag_data pixel_data;
	short width;
	short height;
	char depth;
	char mipmap_count;
	c_enum<e_bitmap_type, char> type;
	char unknown1;
	long unknown2;
	long unknown3;
	c_enum<e_bitmap_format, char> format;
	c_enum<e_bitmap_curve, char> curve;
	c_flags<e_bitmap_image_flags, word> flags;
	long unknown4;
	long unknown5;
};
static_assert_64(sizeof(s_bitmap_texture_resource) == 0x44);

struct s_bitmap_texture_interop_resource
{
	c_typed_tag_interop<s_bitmap_texture_resource> bitmap;
};
static_assert_64(sizeof(s_bitmap_texture_interop_resource) == 0xC);
