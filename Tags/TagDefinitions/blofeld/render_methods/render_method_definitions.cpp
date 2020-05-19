#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(render_method, RENDER_METHOD_TAG, render_method_block_block );

	TAG_GROUP_FROM_BLOCK(render_method_definition, RENDER_METHOD_DEFINITION_TAG, render_method_definition_block_block );

	TAG_GROUP_FROM_BLOCK(render_method_option, RENDER_METHOD_OPTION_TAG, render_method_option_block_block );

	TAG_GROUP_FROM_BLOCK(render_method_template, RENDER_METHOD_TEMPLATE_TAG, render_method_template_block_block );

	TAG_BLOCK(short_block, k_kilo)
	{
		{ _field_short_integer, "short" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_animated_parameter_block, k_kilo)
	{
		{ _field_long_enum, "type^", &render_method_animated_parameter_type_enum },
		{ _field_string_id, "input name" },
		{ _field_string_id, "range name" },
		{ _field_real, "time period:seconds" },
		{ _field_explanation, "FUNCTION" },
		{ _field_custom },
		{ _field_struct, "function", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_parameter_block, c_render_method::k_maximum_parameters)
	{
		{ _field_string_id, "parameter name^" },
		{ _field_long_enum, "parameter type", &render_method_parameter_type_enum },
		{ _field_tag_reference, "bitmap", &bitmap_reference },
		{ _field_real, "real" },
		{ _field_long_integer, "int/bool" },
		{ _field_word_integer, "bitmap flags" },
		{ _field_word_integer, "bitmap filter mode" },
		{ _field_word_integer, "bitmap address mode" },
		{ _field_word_integer, "bitmap address mode x" },
		{ _field_word_integer, "bitmap address mode y" },
		{ _field_short_integer, "bitmap anisotropy amount" },
		{ _field_short_integer, "bitmap extern RTT mode" },
		{ _field_word_integer, "bitmap sharpen mode" },
		{ _field_block, "animated parameters", &render_method_animated_parameter_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_postprocess_texture_block, c_render_method::k_maximum_postprocess_textures)
	{
		{ _field_tag_reference, "bitmap reference", &global_bitmap_reference },
		{ _field_short_integer, "bitmap index" },
		{ _field_byte_integer, "address mode" },
		{ _field_byte_integer, "filter mode" },
		{ _field_byte_integer, "extern texture mode" },
		{ _field_char_block_index, "texture transform constant index" },
		{ _field_struct, "texture transform overlay indices", &tag_block_index_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(real_vector4d_block, k_kilo)
	{
		{ _field_real_vector_3d, "vector" },
		{ _field_real, "vector w" },
		{ _field_terminator }
	};

	TAG_BLOCK(int_block, k_kilo)
	{
		{ _field_long_integer, "int value" },
		{ _field_terminator }
	};

	TAG_BLOCK(tag_block_index_block, k_kilo)
	{
		{ _field_struct, "block index", &tag_block_index_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_postprocess_pass_block, k_kilo)
	{
		{ _field_word_integer, "bitmaps#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex real#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel real#divide by 1024 for count, remainder is start index" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_routing_info_block, c_render_method_template::k_maximum_routing_info)
	{
		{ _field_word_integer, "destination index#D3D constant index or sampler index" },
		{ _field_byte_integer, "source index#into constant tables below, unless this is an extern parameter" },
		{ _field_byte_integer, "type specific#bitmap flags or shader component mask" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_postprocess_block, 1)
	{
		{ _field_tag_reference, "shader template", &render_method_template_reference },
		{ _field_block, "textures", &render_method_postprocess_texture_block_block },
		{ _field_block, "real vectors", &real_vector4d_block_block },
		{ _field_block, "int constants", &int_block_block },
		{ _field_long_integer, "bool constants" },
		{ _field_block, "entry points", &tag_block_index_block_block },
		{ _field_block, "passes", &render_method_postprocess_pass_block_block },
		{ _field_block, "routing info", &render_method_routing_info_block_block },
		{ _field_block, "overlays", &render_method_animated_parameter_block_block },
		{ _field_long_integer, "blend mode" },
		{ _field_long_integer, "flags" },
		{ _field_long_integer, "im_so_fired_pad!*" },
		{ _field_array, "runtime queryable properties table", &runtime_queryable_properties_array },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_locked_parameter_block, c_render_method_option::k_maximum_parameters)
	{
		{ _field_string_id, "parameter name" },
		{ _field_long_enum, "parameter type", &render_method_parameter_type_enum },
		{ _field_dword_integer, "animated parameter flags" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(render_method_block, 1, render_method_struct_definition_struct_definition );

	TAG_BLOCK(render_method_options_block, c_render_method_definition::k_maximum_category_options)
	{
		{ _field_string_id, "option name" },
		{ _field_tag_reference, "option", &render_method_option_reference },
		{ _field_string_id, "vertex function" },
		{ _field_string_id, "pixel function" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_category_block, c_render_method_definition::k_maximum_categories)
	{
		{ _field_string_id, "category name" },
		{ _field_block, "options", &render_method_options_block_block },
		{ _field_string_id, "vertex function" },
		{ _field_string_id, "pixel function" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_pass_category_dependencies, 1)
	{
		{ _field_short_block_index, "category" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_pass_block, k_kilo)
	{
		{ _field_word_flags, "flags", &render_method_pass_flags },
		{ _field_pad, "nothing", 2 },
		{ _field_block, "category dependencies&shared PS category dependencies", &render_method_pass_category_dependencies_block },
		{ _field_block, "shared VS category dependencies", &render_method_pass_category_dependencies_block },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_entry_points_block, c_render_method_definition::k_maximum_entry_points)
	{
		{ _field_long_enum, "entry point", &entry_point_enum },
		{ _field_block, "passes", &render_method_pass_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(vertex_types_block, k_number_of_vertex_types)
	{
		{ _field_enum, "vertex type", &vertex_types_names_enum },
		{ _field_pad, "blahasdf", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(render_method_definition_block, 1, render_method_definition_struct_definition_struct_definition );

	TAG_BLOCK(render_method_option_parameter_block, c_render_method_option::k_maximum_parameters)
	{
		{ _field_string_id, "parameter name" },
		{ _field_string_id, "parameter ui override name" },
		{ _field_long_enum, "parameter type", &render_method_parameter_type_enum },
		{ _field_long_enum, "source extern", &render_method_extern_enum },
		{ _field_tag_reference, "default bitmap", &global_bitmap_reference },
		{ _field_real, "default real value" },
		{ _field_long_integer, "default int/bool value" },
		{ _field_word_integer, "flags" },
		{ _field_enum, "default filter mode", &render_method_bitmap_filter_mode_enum },
		{ _field_enum, "default address mode", &render_method_bitmap_address_mode_enum },
		{ _field_word_integer, "anisotropy amount" },
		{ _field_argb_color, "default color" },
		{ _field_real, "default bitmap scale" },
		{ _field_long_flags, "usage flags", &ui_and_usage_flags },
		{ _field_enum, "force function type", &function_type_enum_definition },
		{ _field_enum, "force function color count", &color_graph_type_enum_definition },
		{ _field_real, "suggested real min" },
		{ _field_real, "suggested real max" },
		{ _field_long_integer, "ticks from min to max" },
		{ _field_data, "help text" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(render_method_option_block, 1, render_method_option_struct_definition_struct_definition );

	TAG_BLOCK(render_method_template_pass_block, c_render_method_template::k_maximum_passes)
	{
		{ _field_word_integer, "bitmaps#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex real constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex int constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex bool constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel real constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel int constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel bool constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern bitmaps#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern vertex real constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern vertex int constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern pixel real constants#divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern pixel int constants#divide by 1024 for count, remainder is start index" },
		{ _field_long_integer, "alpha blend mode" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_template_constant_table_block, 254)
	{
		{ _field_string_id, "parameter name" },
		{ _field_terminator }
	};

	TAG_BLOCK(render_method_template_platform_block, 1)
	{
		{ _field_tag_reference, "vertex shader", &vertex_shader_reference },
		{ _field_tag_reference, "pixel shader", &pixel_shader_reference },
		{ _field_dword_integer, "available entry_points*" },
		{ _field_block, "entry points", &tag_block_index_block_block },
		{ _field_block, "passes", &render_method_template_pass_block_block },
		{ _field_block, "routing info", &render_method_routing_info_block_block },
		{ _field_block, "float constants", &render_method_template_constant_table_block_block },
		{ _field_block, "int constants", &render_method_template_constant_table_block_block },
		{ _field_block, "bool constants", &render_method_template_constant_table_block_block },
		{ _field_block, "textures", &render_method_template_constant_table_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(render_method_template_block, 1, render_method_template_struct_definition_struct_definition );

	TAG_ARRAY(runtime_queryable_properties, s_render_method_postprocess_definition::k_runtime_queryable_properties_count)
	{
		{ _field_short_block_index, "index" },
		{ _field_terminator }
	};

	TAG_STRUCT(render_method_struct_definition)
	{
		{ _field_custom },
		{ _field_tag_reference, "definition*", &render_method_definition_reference },
		{ _field_tag_reference, "reference", &render_method_reference },
		{ _field_block, "options", &short_block_block },
		{ _field_block, "parameters", &render_method_parameter_block_block },
		{ _field_block, "postprocess", &render_method_postprocess_block_block },
		{ _field_long_integer, "is template" },
		{ _field_long_flags, "locked options", &global_render_method_lock_option_flags_defintion },
		{ _field_block, "locked parameters", &render_method_locked_parameter_block_block },
		{ _field_word_flags, "shader flags*", &global_render_method_flags_defintion },
		{ _field_char_enum, "sort layer*", &global_sort_layer_enum_defintion },
		{ _field_char_integer, "version!" },
		{ _field_long_integer, "Custom fog setting index" },
		{ _field_long_block_index, "prediction atom index!" },
		{ _field_terminator }
	};

	TAG_STRUCT(tag_block_index_struct)
	{
		{ _field_word_integer, "block index data#divide by 1024 for count, remainder is start index" },
		{ _field_terminator }
	};

	TAG_STRUCT(render_method_definition_struct_definition)
	{
		{ _field_tag_reference, "global options", &render_method_option_reference },
		{ _field_block, "categories", &render_method_category_block_block },
		{ _field_block, "entry_points", &render_method_entry_points_block_block },
		{ _field_block, "vertex_types", &vertex_types_block_block },
		{ _field_tag_reference, "shared pixel shaders*", &global_pixel_shader_reference },
		{ _field_tag_reference, "shared vertex shaders*", &global_vertex_shader_reference },
		{ _field_long_flags, "flags", &render_method_definition_flags },
		{ _field_dword_integer, "version:bump to force recompile" },
		{ _field_explanation, "source file location" },
		{ _field_long_string, "location" },
		{ _field_terminator }
	};

	TAG_STRUCT(render_method_option_struct_definition)
	{
		{ _field_block, "parameters", &render_method_option_parameter_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(render_method_template_struct_definition)
	{
		{ _field_tag_reference, "vertex shader", &vertex_shader_reference },
		{ _field_tag_reference, "pixel shader", &pixel_shader_reference },
		{ _field_dword_integer, "available entry points*" },
		{ _field_block, "entry points", &tag_block_index_block_block },
		{ _field_block, "passes", &render_method_template_pass_block_block },
		{ _field_block, "routing info", &render_method_routing_info_block_block },
		{ _field_block, "float constants", &render_method_template_constant_table_block_block },
		{ _field_block, "int constants", &render_method_template_constant_table_block_block },
		{ _field_block, "bool constants", &render_method_template_constant_table_block_block },
		{ _field_block, "textures", &render_method_template_constant_table_block_block },
		{ _field_block, "other platforms", &render_method_template_platform_block_block },
		{ _field_terminator }
	};

	STRINGS(render_method_parameter_type_enum)
	{
		"bitmap",
		"color",
		"real",
		"int",
		"bool",
		"argb color"
	};
	STRING_LIST(render_method_parameter_type_enum, render_method_parameter_type_enum_strings, _countof(render_method_parameter_type_enum_strings));

	STRINGS(render_method_bitmap_filter_mode_enum)
	{
		"trilinear",
		"point",
		"bilinear",
		"UNUSED 0",
		"anisotropic (2) expensive",
		"UNUSED 1",
		"anisotropic (4) EXPENSIVE",
		"lightprobe texture array",
		"texture array quadlinear",
		"texture array quadanisotropic (2)"
	};
	STRING_LIST(render_method_bitmap_filter_mode_enum, render_method_bitmap_filter_mode_enum_strings, _countof(render_method_bitmap_filter_mode_enum_strings));

	STRINGS(render_method_bitmap_address_mode_enum)
	{
		"wrap",
		"clamp",
		"mirror",
		"black border",
		"mirroronce",
		"mirroronce border"
	};
	STRING_LIST(render_method_bitmap_address_mode_enum, render_method_bitmap_address_mode_enum_strings, _countof(render_method_bitmap_address_mode_enum_strings));

	STRINGS(render_method_animated_parameter_type_enum)
	{
		"value",
		"color",
		"scale uniform",
		"scale x",
		"scale y",
		"translation x",
		"translation y",
		"frame index",
		"alpha"
	};
	STRING_LIST(render_method_animated_parameter_type_enum, render_method_animated_parameter_type_enum_strings, _countof(render_method_animated_parameter_type_enum_strings));

	STRINGS(render_method_extern_enum)
	{
		"none",
		"texaccum target",
		"normal target",
		"z target",
		"shadow mask",
		"shadow 1 target",
		"shadow 2 target",
		"shadow 3 target",
		"shadow 4 target",
		"texture camera target",
		"reflection target",
		"refraction target",
		"dualvmf direction ps",
		"dualvmf intensity ps",
		"dualvmf direction vs",
		"dualvmf intensity vs",
		"gel texture of analytical light",
		"unused 1",
		"unused 2",
		"change color primary",
		"change color secondary",
		"change color tertiary",
		"change color quaternary",
		"emblem color background",
		"emblem color primary",
		"emblem color secondary",
		"dynamic environment map 1",
		"dynamic environment map 2",
		"cook torrance array",
		"vmf diffuse table",
		"vmf diffuse table vs",
		"direction lut",
		"zonal rotation table",
		"phong specular table",
		"diffuse power specular table",
		"light dir 0",
		"light color 0",
		"light dir 1",
		"light color 1",
		"light dir 2",
		"light color 2",
		"light dir 3",
		"light color 3",
		"unused 3",
		"unused 4",
		"unused 5",
		"dynamic light gel 0",
		"flat envmap matrix x",
		"flat envmap matrix y",
		"flat envmap matrix z",
		"debug tint",
		"screen constants",
		"active camo distortion texture",
		"scene ldr texture",
		"water memexport addr",
		"tree animation timer",
		"depth constants",
		"camera forward",
		"wrinkle weights a",
		"wrinkle weights b",
		"static lighting previs"
	};
	STRING_LIST(render_method_extern_enum, render_method_extern_enum_strings, _countof(render_method_extern_enum_strings));

	STRINGS(render_method_definition_flags)
	{
		"use automatic macros",
		"build constant table in shader"
	};
	STRING_LIST(render_method_definition_flags, render_method_definition_flags_strings, _countof(render_method_definition_flags_strings));

	STRINGS(entry_point_enum)
	{
		"default",
		"albedo",
		"static_per_pixel",
		"static_per_pixel_hybrid_refinement",
		"static_per_pixel_analytic",
		"static_per_pixel_analytic_hybrid_refinement",
		"static_per_pixel_floating_shadow",
		"static_per_vertex",
		"static_probe",
		"static_per_pixel_forge",
		"static_per_pixel_object",
		"static_per_vertex_object",
		"dynamic_light",
		"shadow_generate",
		"shadow_apply",
		"active_camo",
		"lightmap_debug_mode",
		"vertex_color_lighting",
		"water_tessellation",
		"water_shading",
		"unused2",
		"single_pass_per_pixel",
		"single_pass_per_vertex",
		"single_pass_single_probe",
		"single_pass_as_decal",
		"midnight_spotlight",
		"midnight_spotlight_transparents",
		"motion_blur",
		"volume_fog_stencil",
		"volume_fog_depth",
		"curved_cui",
		"single_pass_shadowed_no_fog_per_pixel",
		"single_pass_shadowed_no_fog_per_vertex",
		"single_pass_shadowed_no_fog_single_probe",
		"static_per_pixel_floating_shadow_simple",
		"static_per_pixel_simple",
		"static_per_pixel_ao",
		"static_per_vertex_ao",
		"static_lit_cui",
		"curved_static_lit_cui"
	};
	STRING_LIST(entry_point_enum, entry_point_enum_strings, _countof(entry_point_enum_strings));

	STRINGS(render_method_pass_flags)
	{
		"shared entry point compilation&shared pixel shader compilation",
		"shared VS only care non-default option of depended category",
		"only be compiled to xenon platform",
		"allow failed shader compile"
	};
	STRING_LIST(render_method_pass_flags, render_method_pass_flags_strings, _countof(render_method_pass_flags_strings));

	STRINGS(vertex_types_names_enum)
	{
		"world",
		"rigid",
		"skinned",
		"particle_model",
		"flat_world",
		"flat_rigid",
		"flat_skinned",
		"screen",
		"debug",
		"transparent",
		"particle",
		"rigid2uv",
		"light_volume",
		"chud_simple",
		"chud_fancy",
		"decorator",
		"tiny position",
		"patchy fog",
		"water",
		"ripple",
		"implicit geometry",
		"skinned2uv",
		"world_tessellated",
		"rigid_tessellated",
		"skinned_tessellated",
		"shader_cache",
		"structure_instance_imposter",
		"object_imposter",
		"rigid compressed",
		"skinned uncompressed",
		"light_volume_precompiled",
		"blendshape_rigid",
		"blendshape_rigid_blendshaped",
		"rigid_blendshaped",
		"blendshape_skinned",
		"blendshape_skinned_blendshaped",
		"skinned_blendshaped",
		"VirtualGeometryHWtess",
		"VirtualGeometryMemexport",
		"position_only",
		"VirtualGeometryDebug",
		"BlendshapeRigidCompressedPosition",
		"SkinnedUncompressedPositionBlendshaped",
		"BlendshapeSkinnedUncompressedPosition",
		"tracer",
		"polyart",
		"vectorart",
		"rigid_boned",
		"rigid_boned_2uv",
		"blendshape_skinned_2uv",
		"blendshape_skinned_2uv_blendshaped",
		"skinned_2uv_blendshaped",
		"polyartUV",
		"BlendshapeSkinnedUncompressedPositionBlendshaped"
	};
	STRING_LIST(vertex_types_names_enum, vertex_types_names_enum_strings, _countof(vertex_types_names_enum_strings));

	STRINGS(ui_and_usage_flags)
	{
		"use force function type",
		"use force function color count",
		"parameter invisible in ui",
		"lock function value"
	};
	STRING_LIST(ui_and_usage_flags, ui_and_usage_flags_strings, _countof(ui_and_usage_flags_strings));

	STRINGS(global_render_method_lock_option_flags_defintion)
	{
		"option 0",
		"option 1",
		"option 2",
		"option 3",
		"option 4",
		"option 5",
		"option 6",
		"option 7",
		"option 8",
		"option 9",
		"option 10",
		"option 11",
		"option 12",
		"option 13",
		"option 14",
		"option 15",
		"option 16",
		"option 17",
		"option 18",
		"option 19",
		"option 20",
		"option 21",
		"option 22",
		"option 23",
		"option 24",
		"option 25",
		"option 26",
		"option 27",
		"option 28",
		"option 29",
		"option 30",
		"option 31"
	};
	STRING_LIST(global_render_method_lock_option_flags_defintion, global_render_method_lock_option_flags_defintion_strings, _countof(global_render_method_lock_option_flags_defintion_strings));

	STRINGS(global_render_method_flags_defintion)
	{
		"don\'t fog me",
		"use custom setting",
		"calculate Z camera",
		"never render for shields",
		"only render for shields"
	};
	STRING_LIST(global_render_method_flags_defintion, global_render_method_flags_defintion_strings, _countof(global_render_method_flags_defintion_strings));

	STRINGS(global_sort_layer_enum_defintion)
	{
		"invalid",
		"pre-pass",
		"normal",
		"post-pass"
	};
	STRING_LIST(global_sort_layer_enum_defintion, global_sort_layer_enum_defintion_strings, _countof(global_sort_layer_enum_defintion_strings));

} // namespace blofeld

