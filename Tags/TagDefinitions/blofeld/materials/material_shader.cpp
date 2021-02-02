#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(material_shader, MATERIAL_SHADER_TAG)
	{
		{ _field_legacy, _field_long_flags, "flags!", &material_shader_flags },
		{ _field_legacy, _field_block, "source shader files!", &material_shader_source_file_block_block },
		{ _field_legacy, _field_block, "compiled effects!", &compiled_effects_block_block },
		{ _field_legacy, _field_long_integer, "source shader hash!" },
		{ _field_legacy, _field_long_integer, "compiled shader hash!" },
		{ _field_legacy, _field_tag_reference, "shader bank", &material_shader_bank_reference },
		{ _field_legacy, _field_block, "vertex shader entry points*", &material_vertex_shader_entry_point_block_block },
		{ _field_legacy, _field_block, "pixel shader entry points*", &compiled_pixel_shader_refererence_block_block },
		{ _field_legacy, _field_block, "material parameters*", &material_shader_parameter_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(material_shader_source_file_block, MATERIAL_SHADER_MAX_SOURCE_FILES)
	{
		{ _field_legacy, _field_long_string, "shader path^" },
		{ _field_legacy, _field_data, "shader data" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(compiled_effects_block, k_number_of_platforms)
	{
		{ _field_legacy, _field_data, "compiled effect data" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(compiled_vertex_shader_refererence_block, k_number_of_vertex_types + 8)
	{
		{ _field_legacy, _field_long_integer, "hash" },
		{ _field_legacy, _field_long_integer, "index" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(material_vertex_shader_entry_point_block, k_number_of_entry_points + 8)
	{
		{ _field_legacy, _field_block, "vertex type shader indices", &compiled_vertex_shader_refererence_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(compiled_pixel_shader_refererence_block, k_number_of_entry_points + 8)
	{
		{ _field_legacy, _field_long_integer, "hash" },
		{ _field_legacy, _field_long_integer, "index" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(material_shader_flags)
	{
		"is_distortion",
		"is_decal",
		"blended_materials",
		"no_physics_material",
		"is_volume_fog",
		"is_water",
		"is_waterfall",
		"is_hologram",
		"is_blended_hologram",
		"is_emblem",
		"blended_materials_2",
		"blended_materials_3",
		"is_alpha_clip",
		"is_lightable_transparent"
	};
	STRING_LIST(material_shader_flags, material_shader_flags_strings, _countof(material_shader_flags_strings));

} // namespace blofeld

