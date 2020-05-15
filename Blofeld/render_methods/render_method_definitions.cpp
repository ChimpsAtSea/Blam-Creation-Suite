#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(short, k_kilo)
{
	FIELD( _field_short_integer, "short" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_parameter, c_render_method::k_maximum_parameters)
{
	FIELD( _field_string_id, "parameter name^" ),
	FIELD( _field_long_enum, "parameter type" ),
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
	FIELD( _field_block, "animated parameters", &render_method_animated_parameter_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_animated_parameter, k_kilo)
{
	FIELD( _field_long_enum, "type^" ),
	FIELD( _field_string_id, "input name" ),
	FIELD( _field_string_id, "range name" ),
	FIELD( _field_real, "time period:seconds" ),
	FIELD( _field_explanation, "FUNCTION" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "function" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_postprocess, 1)
{
	FIELD( _field_tag_reference, "shader template" ),
	FIELD( _field_block, "textures", &render_method_postprocess_texture_block ),
	FIELD( _field_block, "real vectors", &real_vector4d$2_block ),
	FIELD( _field_block, "int constants", &int$2_block ),
	FIELD( _field_long_integer, "bool constants" ),
	FIELD( _field_block, "entry points", &tag_block_index_block ),
	FIELD( _field_block, "passes", &render_method_postprocess_pass_block ),
	FIELD( _field_block, "routing info", &render_method_routing_info_block ),
	FIELD( _field_block, "overlays", &render_method_animated_parameter_block ),
	FIELD( _field_long_integer, "blend mode" ),
	FIELD( _field_long_integer, "flags" ),
	FIELD( _field_long_integer, "im_so_fired_pad!*" ),
	FIELD( _field_array, "runtime queryable properties table" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_postprocess_texture, c_render_method::k_maximum_postprocess_textures)
{
	FIELD( _field_tag_reference, "bitmap reference" ),
	FIELD( _field_short_integer, "bitmap index" ),
	FIELD( _field_byte_integer, "address mode" ),
	FIELD( _field_byte_integer, "filter mode" ),
	FIELD( _field_byte_integer, "extern texture mode" ),
	FIELD( _field_char_block_index, "texture transform constant index" ),
	FIELD( _field_struct, "texture transform overlay indices" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(real_vector4d$2, k_kilo)
{
	FIELD( _field_real_vector_3d, "vector" ),
	FIELD( _field_real, "vector w" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(int$2, k_kilo)
{
	FIELD( _field_long_integer, "int value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(tag_block_index, k_kilo)
{
	FIELD( _field_struct, "block index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_postprocess_pass, k_kilo)
{
	FIELD( _field_word_integer, "bitmaps#divide by 1024 for count, remainder is start index" ),
	FIELD( _field_word_integer, "vertex real#divide by 1024 for count, remainder is start index" ),
	FIELD( _field_word_integer, "pixel real#divide by 1024 for count, remainder is start index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_routing_info, c_render_method_template::k_maximum_routing_info)
{
	FIELD( _field_word_integer, "destination index#D3D constant index or sampler index" ),
	FIELD( _field_byte_integer, "source index#into constant tables below, unless this is an extern parameter" ),
	FIELD( _field_byte_integer, "type specific#bitmap flags or shader component mask" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_locked_parameter, c_render_method_option::k_maximum_parameters)
{
	FIELD( _field_string_id, "parameter name" ),
	FIELD( _field_long_enum, "parameter type" ),
	FIELD( _field_dword_integer, "animated parameter flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_category, c_render_method_definition::k_maximum_categories)
{
	FIELD( _field_string_id, "category name" ),
	FIELD( _field_block, "options", &render_method_options_block ),
	FIELD( _field_string_id, "vertex function" ),
	FIELD( _field_string_id, "pixel function" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_options, c_render_method_definition::k_maximum_category_options)
{
	FIELD( _field_string_id, "option name" ),
	FIELD( _field_tag_reference, "option" ),
	FIELD( _field_string_id, "vertex function" ),
	FIELD( _field_string_id, "pixel function" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_entry_points, c_render_method_definition::k_maximum_entry_points)
{
	FIELD( _field_long_enum, "entry point" ),
	FIELD( _field_block, "passes", &render_method_pass_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_pass, k_kilo)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "nothing", 2 ),
	FIELD( _field_block, "category dependencies&shared PS category dependencies", &render_method_pass_category_dependencies_block ),
	FIELD( _field_block, "shared VS category dependencies", &render_method_pass_category_dependencies_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_pass_category_dependencies, 1)
{
	FIELD( _field_short_block_index, "category" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vertex_types, k_number_of_vertex_types)
{
	FIELD( _field_enum, "vertex type" ),
	FIELD( _field_pad, "blahasdf", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_option_parameter, c_render_method_option::k_maximum_parameters)
{
	FIELD( _field_string_id, "parameter name" ),
	FIELD( _field_string_id, "parameter ui override name" ),
	FIELD( _field_long_enum, "parameter type" ),
	FIELD( _field_long_enum, "source extern" ),
	FIELD( _field_tag_reference, "default bitmap" ),
	FIELD( _field_real, "default real value" ),
	FIELD( _field_long_integer, "default int/bool value" ),
	FIELD( _field_word_integer, "flags" ),
	FIELD( _field_enum, "default filter mode" ),
	FIELD( _field_enum, "default address mode" ),
	FIELD( _field_word_integer, "anisotropy amount" ),
	FIELD( _field_argb_color, "default color" ),
	FIELD( _field_real, "default bitmap scale" ),
	FIELD( _field_long_flags, "usage flags" ),
	FIELD( _field_enum, "force function type" ),
	FIELD( _field_enum, "force function color count" ),
	FIELD( _field_real, "suggested real min" ),
	FIELD( _field_real, "suggested real max" ),
	FIELD( _field_long_integer, "ticks from min to max" ),
	FIELD( _field_data, "help text" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_template_pass, c_render_method_template::k_maximum_passes)
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

TAG_BLOCK(render_method_template_constant_table, 254)
{
	FIELD( _field_string_id, "parameter name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_method_template_platform, 1)
{
	FIELD( _field_tag_reference, "vertex shader" ),
	FIELD( _field_tag_reference, "pixel shader" ),
	FIELD( _field_dword_integer, "available entry_points*" ),
	FIELD( _field_block, "entry points", &tag_block_index_block ),
	FIELD( _field_block, "passes", &render_method_template_pass_block ),
	FIELD( _field_block, "routing info", &render_method_routing_info_block ),
	FIELD( _field_block, "float constants", &render_method_template_constant_table_block ),
	FIELD( _field_block, "int constants", &render_method_template_constant_table_block ),
	FIELD( _field_block, "bool constants", &render_method_template_constant_table_block ),
	FIELD( _field_block, "textures", &render_method_template_constant_table_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_custom ),
	FIELD( _field_tag_reference, "definition*" ),
	FIELD( _field_tag_reference, "reference" ),
	FIELD( _field_block, "options", &short_block ),
	FIELD( _field_block, "parameters", &render_method_parameter_block ),
	FIELD( _field_block, "postprocess", &render_method_postprocess_block ),
	FIELD( _field_long_integer, "is template" ),
	FIELD( _field_long_flags, "locked options" ),
	FIELD( _field_block, "locked parameters", &render_method_locked_parameter_block ),
	FIELD( _field_word_flags, "shader flags*" ),
	FIELD( _field_char_enum, "sort layer*" ),
	FIELD( _field_char_integer, "version!" ),
	FIELD( _field_long_integer, "Custom fog setting index" ),
	FIELD( _field_long_block_index, "prediction atom index!" ),
	FIELD( _field_terminator )
};

TAG_GROUP(render_method_definition, RENDER_METHOD_DEFINITION_TAG)
{
	FIELD( _field_tag_reference, "global options" ),
	FIELD( _field_block, "categories", &render_method_category_block ),
	FIELD( _field_block, "entry_points", &render_method_entry_points_block ),
	FIELD( _field_block, "vertex_types", &vertex_types_block ),
	FIELD( _field_tag_reference, "shared pixel shaders*" ),
	FIELD( _field_tag_reference, "shared vertex shaders*" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_dword_integer, "version:bump to force recompile" ),
	FIELD( _field_explanation, "source file location" ),
	FIELD( _field_long_string, "location" ),
	FIELD( _field_terminator )
};

TAG_GROUP(render_method_option, RENDER_METHOD_OPTION_TAG)
{
	FIELD( _field_block, "parameters", &render_method_option_parameter_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(render_method_template, RENDER_METHOD_TEMPLATE_TAG)
{
	FIELD( _field_tag_reference, "vertex shader" ),
	FIELD( _field_tag_reference, "pixel shader" ),
	FIELD( _field_dword_integer, "available entry points*" ),
	FIELD( _field_block, "entry points", &tag_block_index_block ),
	FIELD( _field_block, "passes", &render_method_template_pass_block ),
	FIELD( _field_block, "routing info", &render_method_routing_info_block ),
	FIELD( _field_block, "float constants", &render_method_template_constant_table_block ),
	FIELD( _field_block, "int constants", &render_method_template_constant_table_block ),
	FIELD( _field_block, "bool constants", &render_method_template_constant_table_block ),
	FIELD( _field_block, "textures", &render_method_template_constant_table_block ),
	FIELD( _field_block, "other platforms", &render_method_template_platform_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

