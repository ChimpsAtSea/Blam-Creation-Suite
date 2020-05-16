#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(material_shader_source_file_block, MATERIAL_SHADER_MAX_SOURCE_FILES)
{
	FIELD( _field_long_string, "shader path^" ),
	FIELD( _field_data, "shader data" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(compiled_effects_block, k_number_of_platforms)
{
	FIELD( _field_data, "compiled effect data" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(material_vertex_shader_entry_point_block, k_number_of_entry_points + 8)
{
	FIELD( _field_block, "vertex type shader indices", &compiled_vertex_shader_refererence_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(compiled_vertex_shader_refererence_block, k_number_of_vertex_types + 8)
{
	FIELD( _field_long_integer, "hash" ),
	FIELD( _field_long_integer, "index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(compiled_pixel_shader_refererence_block, k_number_of_entry_points + 8)
{
	FIELD( _field_long_integer, "hash" ),
	FIELD( _field_long_integer, "index" ),
	FIELD( _field_terminator )
};

TAG_GROUP(material_shader_block, MATERIAL_SHADER_TAG)
{
	FIELD( _field_long_flags, "flags!" ),
	FIELD( _field_block, "source shader files!", &material_shader_source_file_block ),
	FIELD( _field_block, "compiled effects!", &compiled_effects_block ),
	FIELD( _field_long_integer, "source shader hash!" ),
	FIELD( _field_long_integer, "compiled shader hash!" ),
	FIELD( _field_tag_reference, "shader bank" ),
	FIELD( _field_block, "vertex shader entry points*", &material_vertex_shader_entry_point_block ),
	FIELD( _field_block, "pixel shader entry points*", &compiled_pixel_shader_refererence_block ),
	FIELD( _field_block, "material parameters*", &material_shader_parameter_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

