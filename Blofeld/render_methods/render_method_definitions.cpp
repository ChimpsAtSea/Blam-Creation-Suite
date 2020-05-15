#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(short, k_kilo)
{
	{ _field_short_integer, "short" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_parameter, c_render_method::k_maximum_parameters)
{
	{ _field_string_id, "parameter name^" },
	{ _field_long_enum, "parameter type" },
	{ _field_tag_reference, "bitmap" },
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
	{ _field_block, "animated parameters", &render_method_animated_parameter_block },
	{ _field_terminator },
};

TAG_BLOCK(render_method_animated_parameter, k_kilo)
{
	{ _field_long_enum, "type^" },
	{ _field_string_id, "input name" },
	{ _field_string_id, "range name" },
	{ _field_real, "time period:seconds" },
	{ _field_explanation, "FUNCTION" },
	{ _field_custom },
	{ _field_struct, "function" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_postprocess, 1)
{
	{ _field_tag_reference, "shader template" },
	{ _field_block, "textures", &render_method_postprocess_texture_block },
	{ _field_block, "real vectors", &real_vector4d$2_block },
	{ _field_block, "int constants", &int$2_block },
	{ _field_long_integer, "bool constants" },
	{ _field_block, "entry points", &tag_block_index_block },
	{ _field_block, "passes", &render_method_postprocess_pass_block },
	{ _field_block, "routing info", &render_method_routing_info_block },
	{ _field_block, "overlays", &render_method_animated_parameter_block },
	{ _field_long_integer, "blend mode" },
	{ _field_long_integer, "flags" },
	{ _field_long_integer, "im_so_fired_pad!*" },
	{ _field_array, "runtime queryable properties table" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_postprocess_texture, c_render_method::k_maximum_postprocess_textures)
{
	{ _field_tag_reference, "bitmap reference" },
	{ _field_short_integer, "bitmap index" },
	{ _field_byte_integer, "address mode" },
	{ _field_byte_integer, "filter mode" },
	{ _field_byte_integer, "extern texture mode" },
	{ _field_char_block_index, "texture transform constant index" },
	{ _field_struct, "texture transform overlay indices" },
	{ _field_terminator },
};

TAG_BLOCK(real_vector4d$2, k_kilo)
{
	{ _field_real_vector_3d, "vector" },
	{ _field_real, "vector w" },
	{ _field_terminator },
};

TAG_BLOCK(int$2, k_kilo)
{
	{ _field_long_integer, "int value" },
	{ _field_terminator },
};

TAG_BLOCK(tag_block_index, k_kilo)
{
	{ _field_struct, "block index" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_postprocess_pass, k_kilo)
{
	{ _field_word_integer, "bitmaps#divide by 1024 for count, remainder is start index" },
	{ _field_word_integer, "vertex real#divide by 1024 for count, remainder is start index" },
	{ _field_word_integer, "pixel real#divide by 1024 for count, remainder is start index" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_routing_info, c_render_method_template::k_maximum_routing_info)
{
	{ _field_word_integer, "destination index#D3D constant index or sampler index" },
	{ _field_byte_integer, "source index#into constant tables below, unless this is an extern parameter" },
	{ _field_byte_integer, "type specific#bitmap flags or shader component mask" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_locked_parameter, c_render_method_option::k_maximum_parameters)
{
	{ _field_string_id, "parameter name" },
	{ _field_long_enum, "parameter type" },
	{ _field_dword_integer, "animated parameter flags" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_category, c_render_method_definition::k_maximum_categories)
{
	{ _field_string_id, "category name" },
	{ _field_block, "options", &render_method_options_block },
	{ _field_string_id, "vertex function" },
	{ _field_string_id, "pixel function" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_options, c_render_method_definition::k_maximum_category_options)
{
	{ _field_string_id, "option name" },
	{ _field_tag_reference, "option" },
	{ _field_string_id, "vertex function" },
	{ _field_string_id, "pixel function" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_entry_points, c_render_method_definition::k_maximum_entry_points)
{
	{ _field_long_enum, "entry point" },
	{ _field_block, "passes", &render_method_pass_block },
	{ _field_terminator },
};

TAG_BLOCK(render_method_pass, k_kilo)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "nothing", 2 },
	{ _field_block, "category dependencies&shared PS category dependencies", &render_method_pass_category_dependencies_block },
	{ _field_block, "shared VS category dependencies", &render_method_pass_category_dependencies_block },
	{ _field_terminator },
};

TAG_BLOCK(render_method_pass_category_dependencies, 1)
{
	{ _field_short_block_index, "category" },
	{ _field_terminator },
};

TAG_BLOCK(vertex_types, k_number_of_vertex_types)
{
	{ _field_enum, "vertex type" },
	{ _field_pad, "blahasdf", 2 },
	{ _field_terminator },
};

TAG_BLOCK(render_method_option_parameter, c_render_method_option::k_maximum_parameters)
{
	{ _field_string_id, "parameter name" },
	{ _field_string_id, "parameter ui override name" },
	{ _field_long_enum, "parameter type" },
	{ _field_long_enum, "source extern" },
	{ _field_tag_reference, "default bitmap" },
	{ _field_real, "default real value" },
	{ _field_long_integer, "default int/bool value" },
	{ _field_word_integer, "flags" },
	{ _field_enum, "default filter mode" },
	{ _field_enum, "default address mode" },
	{ _field_word_integer, "anisotropy amount" },
	{ _field_argb_color, "default color" },
	{ _field_real, "default bitmap scale" },
	{ _field_long_flags, "usage flags" },
	{ _field_enum, "force function type" },
	{ _field_enum, "force function color count" },
	{ _field_real, "suggested real min" },
	{ _field_real, "suggested real max" },
	{ _field_long_integer, "ticks from min to max" },
	{ _field_data, "help text" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_template_pass, c_render_method_template::k_maximum_passes)
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
	{ _field_terminator },
};

TAG_BLOCK(render_method_template_constant_table, 254)
{
	{ _field_string_id, "parameter name" },
	{ _field_terminator },
};

TAG_BLOCK(render_method_template_platform, 1)
{
	{ _field_tag_reference, "vertex shader" },
	{ _field_tag_reference, "pixel shader" },
	{ _field_dword_integer, "available entry_points*" },
	{ _field_block, "entry points", &tag_block_index_block },
	{ _field_block, "passes", &render_method_template_pass_block },
	{ _field_block, "routing info", &render_method_routing_info_block },
	{ _field_block, "float constants", &render_method_template_constant_table_block },
	{ _field_block, "int constants", &render_method_template_constant_table_block },
	{ _field_block, "bool constants", &render_method_template_constant_table_block },
	{ _field_block, "textures", &render_method_template_constant_table_block },
	{ _field_terminator },
};

TAG_GROUP(render_method, RENDER_METHOD_TAG)
{
	{ _field_custom },
	{ _field_tag_reference, "definition*" },
	{ _field_tag_reference, "reference" },
	{ _field_block, "options", &short_block },
	{ _field_block, "parameters", &render_method_parameter_block },
	{ _field_block, "postprocess", &render_method_postprocess_block },
	{ _field_long_integer, "is template" },
	{ _field_long_flags, "locked options" },
	{ _field_block, "locked parameters", &render_method_locked_parameter_block },
	{ _field_word_flags, "shader flags*" },
	{ _field_char_enum, "sort layer*" },
	{ _field_char_integer, "version!" },
	{ _field_long_integer, "Custom fog setting index" },
	{ _field_long_block_index, "prediction atom index!" },
	{ _field_terminator },
};

TAG_GROUP(render_method_definition, RENDER_METHOD_DEFINITION_TAG)
{
	{ _field_tag_reference, "global options" },
	{ _field_block, "categories", &render_method_category_block },
	{ _field_block, "entry_points", &render_method_entry_points_block },
	{ _field_block, "vertex_types", &vertex_types_block },
	{ _field_tag_reference, "shared pixel shaders*" },
	{ _field_tag_reference, "shared vertex shaders*" },
	{ _field_long_flags, "flags" },
	{ _field_dword_integer, "version:bump to force recompile" },
	{ _field_explanation, "source file location" },
	{ _field_long_string, "location" },
	{ _field_terminator },
};

TAG_GROUP(render_method_option, RENDER_METHOD_OPTION_TAG)
{
	{ _field_block, "parameters", &render_method_option_parameter_block },
	{ _field_terminator },
};

TAG_GROUP(render_method_template, RENDER_METHOD_TEMPLATE_TAG)
{
	{ _field_tag_reference, "vertex shader" },
	{ _field_tag_reference, "pixel shader" },
	{ _field_dword_integer, "available entry points*" },
	{ _field_block, "entry points", &tag_block_index_block },
	{ _field_block, "passes", &render_method_template_pass_block },
	{ _field_block, "routing info", &render_method_routing_info_block },
	{ _field_block, "float constants", &render_method_template_constant_table_block },
	{ _field_block, "int constants", &render_method_template_constant_table_block },
	{ _field_block, "bool constants", &render_method_template_constant_table_block },
	{ _field_block, "textures", &render_method_template_constant_table_block },
	{ _field_block, "other platforms", &render_method_template_platform_block },
	{ _field_terminator },
};

} // namespace blofeld

