#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(material_shader_source_file, MATERIAL_SHADER_MAX_SOURCE_FILES)
{
	{ _field_long_string, "shader path^" },
	{ _field_data, "shader data" },
	{ _field_terminator },
};

TAG_BLOCK(compiled_effects, k_number_of_platforms)
{
	{ _field_data, "compiled effect data" },
	{ _field_terminator },
};

TAG_BLOCK(material_vertex_shader_entry_point, k_number_of_entry_points + 8)
{
	{ _field_block, "vertex type shader indices", &compiled_vertex_shader_refererence_block },
	{ _field_terminator },
};

TAG_BLOCK(compiled_vertex_shader_refererence, k_number_of_vertex_types + 8)
{
	{ _field_long_integer, "hash" },
	{ _field_long_integer, "index" },
	{ _field_terminator },
};

TAG_BLOCK(compiled_pixel_shader_refererence, k_number_of_entry_points + 8)
{
	{ _field_long_integer, "hash" },
	{ _field_long_integer, "index" },
	{ _field_terminator },
};

TAG_GROUP(material_shader, MATERIAL_SHADER_TAG)
{
	{ _field_long_flags, "flags!" },
	{ _field_block, "source shader files!", &material_shader_source_file_block },
	{ _field_block, "compiled effects!", &compiled_effects_block },
	{ _field_long_integer, "source shader hash!" },
	{ _field_long_integer, "compiled shader hash!" },
	{ _field_tag_reference, "shader bank" },
	{ _field_block, "vertex shader entry points*", &material_vertex_shader_entry_point_block },
	{ _field_block, "pixel shader entry points*", &compiled_pixel_shader_refererence_block },
	{ _field_block, "material parameters*", &material_shader_parameter_block },
	{ _field_terminator },
};

} // namespace blofeld

