#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(render_method, RENDER_METHOD_TAG, render_method_block_block );

	TAG_GROUP_FROM_BLOCK(render_method_definition, RENDER_METHOD_DEFINITION_TAG, render_method_definition_block_block );

	TAG_GROUP_FROM_BLOCK(render_method_option, RENDER_METHOD_OPTION_TAG, render_method_option_block_block );

	TAG_GROUP_FROM_BLOCK(render_method_template, RENDER_METHOD_TEMPLATE_TAG, render_method_template_block_block );

	TAG_BLOCK(short_block, k_kilo)
	{
		FIELD( _field_short_integer, "short" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_animated_parameter_block, k_kilo)
	{
		FIELD( _field_long_enum, "type^", &render_method_animated_parameter_type_enum ),
		FIELD( _field_string_id, "input name" ),
		FIELD( _field_string_id, "range name" ),
		FIELD( _field_real, "time period:seconds" ),
		FIELD( _field_explanation, "FUNCTION" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "function", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_parameter_block, c_render_method::k_maximum_parameters)
	{
		FIELD( _field_string_id, "parameter name^" ),
		FIELD( _field_long_enum, "parameter type", &render_method_parameter_type_enum ),
		FIELD( _field_tag_reference, "bitmap" ),
		FIELD( _field_real, "real" ),
		FIELD( _field_long_integer, "int/bool" ),
		FIELD( _field_word_integer, "bitmap flags" ),
		FIELD( _field_word_integer, "bitmap filter mode" ),
		FIELD( _field_word_integer, "bitmap address mode" ),
		FIELD( _field_word_integer, "bitmap address mode x" ),
		FIELD( _field_word_integer, "bitmap address mode y" ),
		FIELD( _field_short_integer, "bitmap anisotropy amount" ),
		FIELD( _field_short_integer, "bitmap extern RTT mode" ),
		FIELD( _field_word_integer, "bitmap sharpen mode" ),
		FIELD( _field_block, "animated parameters", &render_method_animated_parameter_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_postprocess_texture_block, c_render_method::k_maximum_postprocess_textures)
	{
		FIELD( _field_tag_reference, "bitmap reference" ),
		FIELD( _field_short_integer, "bitmap index" ),
		FIELD( _field_byte_integer, "address mode" ),
		FIELD( _field_byte_integer, "filter mode" ),
		FIELD( _field_byte_integer, "extern texture mode" ),
		FIELD( _field_char_block_index, "texture transform constant index" ),
		FIELD( _field_struct, "texture transform overlay indices", &tag_block_index_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(real_vector4d_block, k_kilo)
	{
		FIELD( _field_real_vector_3d, "vector" ),
		FIELD( _field_real, "vector w" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(int_block, k_kilo)
	{
		FIELD( _field_long_integer, "int value" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(tag_block_index_block, k_kilo)
	{
		FIELD( _field_struct, "block index", &tag_block_index_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_postprocess_pass_block, k_kilo)
	{
		FIELD( _field_word_integer, "bitmaps#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "vertex real#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "pixel real#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_routing_info_block, c_render_method_template::k_maximum_routing_info)
	{
		FIELD( _field_word_integer, "destination index#D3D constant index or sampler index" ),
		FIELD( _field_byte_integer, "source index#into constant tables below, unless this is an extern parameter" ),
		FIELD( _field_byte_integer, "type specific#bitmap flags or shader component mask" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_postprocess_block, 1)
	{
		FIELD( _field_tag_reference, "shader template" ),
		FIELD( _field_block, "textures", &render_method_postprocess_texture_block_block ),
		FIELD( _field_block, "real vectors", &real_vector4d_block_block ),
		FIELD( _field_block, "int constants", &int_block_block ),
		FIELD( _field_long_integer, "bool constants" ),
		FIELD( _field_block, "entry points", &tag_block_index_block_block ),
		FIELD( _field_block, "passes", &render_method_postprocess_pass_block_block ),
		FIELD( _field_block, "routing info", &render_method_routing_info_block_block ),
		FIELD( _field_block, "overlays", &render_method_animated_parameter_block_block ),
		FIELD( _field_long_integer, "blend mode" ),
		FIELD( _field_long_integer, "flags" ),
		FIELD( _field_long_integer, "im_so_fired_pad!*" ),
		FIELD( _field_array, "runtime queryable properties table", &runtime_queryable_properties_array ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_locked_parameter_block, c_render_method_option::k_maximum_parameters)
	{
		FIELD( _field_string_id, "parameter name" ),
		FIELD( _field_long_enum, "parameter type", &render_method_parameter_type_enum ),
		FIELD( _field_dword_integer, "animated parameter flags" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(render_method_block, 1, render_method_struct_definition_struct_definition );

	TAG_BLOCK(render_method_options_block, c_render_method_definition::k_maximum_category_options)
	{
		FIELD( _field_string_id, "option name" ),
		FIELD( _field_tag_reference, "option" ),
		FIELD( _field_string_id, "vertex function" ),
		FIELD( _field_string_id, "pixel function" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_category_block, c_render_method_definition::k_maximum_categories)
	{
		FIELD( _field_string_id, "category name" ),
		FIELD( _field_block, "options", &render_method_options_block_block ),
		FIELD( _field_string_id, "vertex function" ),
		FIELD( _field_string_id, "pixel function" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_pass_category_dependencies, 1)
	{
		FIELD( _field_short_block_index, "category" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_pass_block, k_kilo)
	{
		FIELD( _field_word_flags, "flags", &render_method_pass_flags ),
		FIELD( _field_pad, "nothing", 2 ),
		FIELD( _field_block, "category dependencies&shared PS category dependencies", &render_method_pass_category_dependencies_block ),
		FIELD( _field_block, "shared VS category dependencies", &render_method_pass_category_dependencies_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_entry_points_block, c_render_method_definition::k_maximum_entry_points)
	{
		FIELD( _field_long_enum, "entry point", &entry_point_enum ),
		FIELD( _field_block, "passes", &render_method_pass_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vertex_types_block, k_number_of_vertex_types)
	{
		FIELD( _field_enum, "vertex type", &vertex_types_names_enum ),
		FIELD( _field_pad, "blahasdf", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(render_method_definition_block, 1, render_method_definition_struct_definition_struct_definition );

	TAG_BLOCK(render_method_option_parameter_block, c_render_method_option::k_maximum_parameters)
	{
		FIELD( _field_string_id, "parameter name" ),
		FIELD( _field_string_id, "parameter ui override name" ),
		FIELD( _field_long_enum, "parameter type", &render_method_parameter_type_enum ),
		FIELD( _field_long_enum, "source extern", &render_method_extern_enum ),
		FIELD( _field_tag_reference, "default bitmap" ),
		FIELD( _field_real, "default real value" ),
		FIELD( _field_long_integer, "default int/bool value" ),
		FIELD( _field_word_integer, "flags" ),
		FIELD( _field_enum, "default filter mode", &render_method_bitmap_filter_mode_enum ),
		FIELD( _field_enum, "default address mode", &render_method_bitmap_address_mode_enum ),
		FIELD( _field_word_integer, "anisotropy amount" ),
		FIELD( _field_argb_color, "default color" ),
		FIELD( _field_real, "default bitmap scale" ),
		FIELD( _field_long_flags, "usage flags", &ui_and_usage_flags ),
		FIELD( _field_enum, "force function type", &function_type_enum_definition ),
		FIELD( _field_enum, "force function color count", &color_graph_type_enum_definition ),
		FIELD( _field_real, "suggested real min" ),
		FIELD( _field_real, "suggested real max" ),
		FIELD( _field_long_integer, "ticks from min to max" ),
		FIELD( _field_data, "help text" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(render_method_option_block, 1, render_method_option_struct_definition_struct_definition );

	TAG_BLOCK(render_method_template_pass_block, c_render_method_template::k_maximum_passes)
	{
		FIELD( _field_word_integer, "bitmaps#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "vertex real constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "vertex int constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "vertex bool constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "pixel real constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "pixel int constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "pixel bool constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "extern bitmaps#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "extern vertex real constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "extern vertex int constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "extern pixel real constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_word_integer, "extern pixel int constants#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_long_integer, "alpha blend mode" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_template_constant_table_block, 254)
	{
		FIELD( _field_string_id, "parameter name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(render_method_template_platform_block, 1)
	{
		FIELD( _field_tag_reference, "vertex shader" ),
		FIELD( _field_tag_reference, "pixel shader" ),
		FIELD( _field_dword_integer, "available entry_points*" ),
		FIELD( _field_block, "entry points", &tag_block_index_block_block ),
		FIELD( _field_block, "passes", &render_method_template_pass_block_block ),
		FIELD( _field_block, "routing info", &render_method_routing_info_block_block ),
		FIELD( _field_block, "float constants", &render_method_template_constant_table_block_block ),
		FIELD( _field_block, "int constants", &render_method_template_constant_table_block_block ),
		FIELD( _field_block, "bool constants", &render_method_template_constant_table_block_block ),
		FIELD( _field_block, "textures", &render_method_template_constant_table_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(render_method_template_block, 1, render_method_template_struct_definition_struct_definition );

	TAG_ARRAY(runtime_queryable_properties, s_render_method_postprocess_definition::k_runtime_queryable_properties_count)
	{
		FIELD( _field_short_block_index, "index" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(render_method_struct_definition)
	{
		FIELD( _field_custom ),
		FIELD( _field_tag_reference, "definition*" ),
		FIELD( _field_tag_reference, "reference" ),
		FIELD( _field_block, "options", &short_block_block ),
		FIELD( _field_block, "parameters", &render_method_parameter_block_block ),
		FIELD( _field_block, "postprocess", &render_method_postprocess_block_block ),
		FIELD( _field_long_integer, "is template" ),
		FIELD( _field_long_flags, "locked options", &global_render_method_lock_option_flags_defintion ),
		FIELD( _field_block, "locked parameters", &render_method_locked_parameter_block_block ),
		FIELD( _field_word_flags, "shader flags*", &global_render_method_flags_defintion ),
		FIELD( _field_char_enum, "sort layer*", &global_sort_layer_enum_defintion ),
		FIELD( _field_char_integer, "version!" ),
		FIELD( _field_long_integer, "Custom fog setting index" ),
		FIELD( _field_long_block_index, "prediction atom index!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(tag_block_index_struct)
	{
		FIELD( _field_word_integer, "block index data#divide by 1024 for count, remainder is start index" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(render_method_definition_struct_definition)
	{
		FIELD( _field_tag_reference, "global options" ),
		FIELD( _field_block, "categories", &render_method_category_block_block ),
		FIELD( _field_block, "entry_points", &render_method_entry_points_block_block ),
		FIELD( _field_block, "vertex_types", &vertex_types_block_block ),
		FIELD( _field_tag_reference, "shared pixel shaders*" ),
		FIELD( _field_tag_reference, "shared vertex shaders*" ),
		FIELD( _field_long_flags, "flags", &render_method_definition_flags ),
		FIELD( _field_dword_integer, "version:bump to force recompile" ),
		FIELD( _field_explanation, "source file location" ),
		FIELD( _field_long_string, "location" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(render_method_option_struct_definition)
	{
		FIELD( _field_block, "parameters", &render_method_option_parameter_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(render_method_template_struct_definition)
	{
		FIELD( _field_tag_reference, "vertex shader" ),
		FIELD( _field_tag_reference, "pixel shader" ),
		FIELD( _field_dword_integer, "available entry points*" ),
		FIELD( _field_block, "entry points", &tag_block_index_block_block ),
		FIELD( _field_block, "passes", &render_method_template_pass_block_block ),
		FIELD( _field_block, "routing info", &render_method_routing_info_block_block ),
		FIELD( _field_block, "float constants", &render_method_template_constant_table_block_block ),
		FIELD( _field_block, "int constants", &render_method_template_constant_table_block_block ),
		FIELD( _field_block, "bool constants", &render_method_template_constant_table_block_block ),
		FIELD( _field_block, "textures", &render_method_template_constant_table_block_block ),
		FIELD( _field_block, "other platforms", &render_method_template_platform_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(render_method_parameter_type_enum, 6)
	{
		OPTION("bitmap"),
		OPTION("color"),
		OPTION("real"),
		OPTION("int"),
		OPTION("bool"),
		OPTION("argb color"),
	};

	TAG_ENUM(render_method_bitmap_filter_mode_enum, 10)
	{
		OPTION("trilinear"),
		OPTION("point"),
		OPTION("bilinear"),
		OPTION("UNUSED 0"),
		OPTION("anisotropic (2) expensive"),
		OPTION("UNUSED 1"),
		OPTION("anisotropic (4) EXPENSIVE"),
		OPTION("lightprobe texture array"),
		OPTION("texture array quadlinear"),
		OPTION("texture array quadanisotropic (2)"),
	};

	TAG_ENUM(render_method_bitmap_address_mode_enum, 6)
	{
		OPTION("wrap"),
		OPTION("clamp"),
		OPTION("mirror"),
		OPTION("black border"),
		OPTION("mirroronce"),
		OPTION("mirroronce border"),
	};

	TAG_ENUM(render_method_animated_parameter_type_enum, 9)
	{
		OPTION("value"),
		OPTION("color"),
		OPTION("scale uniform"),
		OPTION("scale x"),
		OPTION("scale y"),
		OPTION("translation x"),
		OPTION("translation y"),
		OPTION("frame index"),
		OPTION("alpha"),
	};

	TAG_ENUM(render_method_extern_enum, 61)
	{
		OPTION("none"),
		OPTION("texaccum target"),
		OPTION("normal target"),
		OPTION("z target"),
		OPTION("shadow mask"),
		OPTION("shadow 1 target"),
		OPTION("shadow 2 target"),
		OPTION("shadow 3 target"),
		OPTION("shadow 4 target"),
		OPTION("texture camera target"),
		OPTION("reflection target"),
		OPTION("refraction target"),
		OPTION("dualvmf direction ps"),
		OPTION("dualvmf intensity ps"),
		OPTION("dualvmf direction vs"),
		OPTION("dualvmf intensity vs"),
		OPTION("gel texture of analytical light"),
		OPTION("unused 1"),
		OPTION("unused 2"),
		OPTION("change color primary"),
		OPTION("change color secondary"),
		OPTION("change color tertiary"),
		OPTION("change color quaternary"),
		OPTION("emblem color background"),
		OPTION("emblem color primary"),
		OPTION("emblem color secondary"),
		OPTION("dynamic environment map 1"),
		OPTION("dynamic environment map 2"),
		OPTION("cook torrance array"),
		OPTION("vmf diffuse table"),
		OPTION("vmf diffuse table vs"),
		OPTION("direction lut"),
		OPTION("zonal rotation table"),
		OPTION("phong specular table"),
		OPTION("diffuse power specular table"),
		OPTION("light dir 0"),
		OPTION("light color 0"),
		OPTION("light dir 1"),
		OPTION("light color 1"),
		OPTION("light dir 2"),
		OPTION("light color 2"),
		OPTION("light dir 3"),
		OPTION("light color 3"),
		OPTION("unused 3"),
		OPTION("unused 4"),
		OPTION("unused 5"),
		OPTION("dynamic light gel 0"),
		OPTION("flat envmap matrix x"),
		OPTION("flat envmap matrix y"),
		OPTION("flat envmap matrix z"),
		OPTION("debug tint"),
		OPTION("screen constants"),
		OPTION("active camo distortion texture"),
		OPTION("scene ldr texture"),
		OPTION("water memexport addr"),
		OPTION("tree animation timer"),
		OPTION("depth constants"),
		OPTION("camera forward"),
		OPTION("wrinkle weights a"),
		OPTION("wrinkle weights b"),
		OPTION("static lighting previs"),
	};

	TAG_ENUM(render_method_definition_flags, 2)
	{
		OPTION("use automatic macros"),
		OPTION("build constant table in shader"),
	};

	TAG_ENUM(entry_point_enum, 40)
	{
		OPTION("default"),
		OPTION("albedo"),
		OPTION("static_per_pixel"),
		OPTION("static_per_pixel_hybrid_refinement"),
		OPTION("static_per_pixel_analytic"),
		OPTION("static_per_pixel_analytic_hybrid_refinement"),
		OPTION("static_per_pixel_floating_shadow"),
		OPTION("static_per_vertex"),
		OPTION("static_probe"),
		OPTION("static_per_pixel_forge"),
		OPTION("static_per_pixel_object"),
		OPTION("static_per_vertex_object"),
		OPTION("dynamic_light"),
		OPTION("shadow_generate"),
		OPTION("shadow_apply"),
		OPTION("active_camo"),
		OPTION("lightmap_debug_mode"),
		OPTION("vertex_color_lighting"),
		OPTION("water_tessellation"),
		OPTION("water_shading"),
		OPTION("unused2"),
		OPTION("single_pass_per_pixel"),
		OPTION("single_pass_per_vertex"),
		OPTION("single_pass_single_probe"),
		OPTION("single_pass_as_decal"),
		OPTION("midnight_spotlight"),
		OPTION("midnight_spotlight_transparents"),
		OPTION("motion_blur"),
		OPTION("volume_fog_stencil"),
		OPTION("volume_fog_depth"),
		OPTION("curved_cui"),
		OPTION("single_pass_shadowed_no_fog_per_pixel"),
		OPTION("single_pass_shadowed_no_fog_per_vertex"),
		OPTION("single_pass_shadowed_no_fog_single_probe"),
		OPTION("static_per_pixel_floating_shadow_simple"),
		OPTION("static_per_pixel_simple"),
		OPTION("static_per_pixel_ao"),
		OPTION("static_per_vertex_ao"),
		OPTION("static_lit_cui"),
		OPTION("curved_static_lit_cui"),
	};

	TAG_ENUM(render_method_pass_flags, 4)
	{
		OPTION("shared entry point compilation&shared pixel shader compilation"),
		OPTION("shared VS only care non-default option of depended category"),
		OPTION("only be compiled to xenon platform"),
		OPTION("allow failed shader compile"),
	};

	TAG_ENUM(vertex_types_names_enum, 54)
	{
		OPTION("world"),
		OPTION("rigid"),
		OPTION("skinned"),
		OPTION("particle_model"),
		OPTION("flat_world"),
		OPTION("flat_rigid"),
		OPTION("flat_skinned"),
		OPTION("screen"),
		OPTION("debug"),
		OPTION("transparent"),
		OPTION("particle"),
		OPTION("rigid2uv"),
		OPTION("light_volume"),
		OPTION("chud_simple"),
		OPTION("chud_fancy"),
		OPTION("decorator"),
		OPTION("tiny position"),
		OPTION("patchy fog"),
		OPTION("water"),
		OPTION("ripple"),
		OPTION("implicit geometry"),
		OPTION("skinned2uv"),
		OPTION("world_tessellated"),
		OPTION("rigid_tessellated"),
		OPTION("skinned_tessellated"),
		OPTION("shader_cache"),
		OPTION("structure_instance_imposter"),
		OPTION("object_imposter"),
		OPTION("rigid compressed"),
		OPTION("skinned uncompressed"),
		OPTION("light_volume_precompiled"),
		OPTION("blendshape_rigid"),
		OPTION("blendshape_rigid_blendshaped"),
		OPTION("rigid_blendshaped"),
		OPTION("blendshape_skinned"),
		OPTION("blendshape_skinned_blendshaped"),
		OPTION("skinned_blendshaped"),
		OPTION("VirtualGeometryHWtess"),
		OPTION("VirtualGeometryMemexport"),
		OPTION("position_only"),
		OPTION("VirtualGeometryDebug"),
		OPTION("BlendshapeRigidCompressedPosition"),
		OPTION("SkinnedUncompressedPositionBlendshaped"),
		OPTION("BlendshapeSkinnedUncompressedPosition"),
		OPTION("tracer"),
		OPTION("polyart"),
		OPTION("vectorart"),
		OPTION("rigid_boned"),
		OPTION("rigid_boned_2uv"),
		OPTION("blendshape_skinned_2uv"),
		OPTION("blendshape_skinned_2uv_blendshaped"),
		OPTION("skinned_2uv_blendshaped"),
		OPTION("polyartUV"),
		OPTION("BlendshapeSkinnedUncompressedPositionBlendshaped"),
	};

	TAG_ENUM(ui_and_usage_flags, 4)
	{
		OPTION("use force function type"),
		OPTION("use force function color count"),
		OPTION("parameter invisible in ui"),
		OPTION("lock function value"),
	};

	TAG_ENUM(global_render_method_lock_option_flags_defintion, 32)
	{
		OPTION("option 0"),
		OPTION("option 1"),
		OPTION("option 2"),
		OPTION("option 3"),
		OPTION("option 4"),
		OPTION("option 5"),
		OPTION("option 6"),
		OPTION("option 7"),
		OPTION("option 8"),
		OPTION("option 9"),
		OPTION("option 10"),
		OPTION("option 11"),
		OPTION("option 12"),
		OPTION("option 13"),
		OPTION("option 14"),
		OPTION("option 15"),
		OPTION("option 16"),
		OPTION("option 17"),
		OPTION("option 18"),
		OPTION("option 19"),
		OPTION("option 20"),
		OPTION("option 21"),
		OPTION("option 22"),
		OPTION("option 23"),
		OPTION("option 24"),
		OPTION("option 25"),
		OPTION("option 26"),
		OPTION("option 27"),
		OPTION("option 28"),
		OPTION("option 29"),
		OPTION("option 30"),
		OPTION("option 31"),
	};

	TAG_ENUM(global_render_method_flags_defintion, 5)
	{
		OPTION("don\'t fog me"),
		OPTION("use custom setting"),
		OPTION("calculate Z camera"),
		OPTION("never render for shields"),
		OPTION("only render for shields"),
	};

	TAG_ENUM(global_sort_layer_enum_defintion, 4)
	{
		OPTION("invalid"),
		OPTION("pre-pass"),
		OPTION("normal"),
		OPTION("post-pass"),
	};

} // namespace blofeld

