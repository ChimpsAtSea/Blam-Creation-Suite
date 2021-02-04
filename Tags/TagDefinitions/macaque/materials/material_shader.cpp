#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MATERIAL_SHADER_STRUCT_DEFINITION_ID { 0x1D0531C4, 0xBFBC4D8F, 0x945CF431, 0x7567B718 }
	TAG_BLOCK(
		material_shader_block,
		"material_shader_block",
		1,
		"c_material_shader",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_SHADER_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &material_shader_flags },
		{ _field_block, "source shader files", &material_shader_source_file_block },
		{ _field_block, "compiled effects", &compiled_effects_block },
		{ _field_long_integer, "source shader hash", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "compiled shader hash", FIELD_FLAG_UNKNOWN0 },
		{ _field_tag_reference, "shader bank", &material_shader_bank_reference },
		{ _field_block, "vertex shader entry points", &material_vertex_shader_entry_point_block },
		{ _field_block, "pixel shader entry points", &compiled_pixel_shader_refererence_block },
		{ _field_block, "material parameters", &material_shader_parameter_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		material_shader_group,
		MATERIAL_SHADER_TAG,
		nullptr,
		INVALID_TAG,
		material_shader_block );

	#define MATERIAL_SHADER_SOURCE_FILE_BLOCK_ID { 0xB9DD4E56, 0x85724A5B, 0x9191D4D2, 0xEF3D72CA }
	TAG_BLOCK(
		material_shader_source_file_block,
		"material_shader_source_file_block",
		MATERIAL_SHADER_MAX_SOURCE_FILES,
		"s_material_shader_source_file",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_SHADER_SOURCE_FILE_BLOCK_ID)
	{
		{ _field_long_string, "shader path", FIELD_FLAG_INDEX },
		{ _field_data, "shader data" },
		{ _field_terminator }
	};

	#define COMPILED_EFFECTS_BLOCK_ID { 0x1935F30F, 0x65BF4E9E, 0x8FEC9CC4, 0x9E114507 }
	TAG_BLOCK(
		compiled_effects_block,
		"compiled_effects_block",
		k_number_of_platforms,
		"s_tag_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMPILED_EFFECTS_BLOCK_ID)
	{
		{ _field_data, "compiled effect data" },
		{ _field_terminator }
	};

	#define MATERIAL_VERTEX_SHADER_ENTRY_POINT_BLOCK_STRUCT_ID { 0xB4C9BC4F, 0xA11E40AE, 0xA23D74EA, 0xB323A5EA }
	TAG_BLOCK(
		material_vertex_shader_entry_point_block,
		"material_vertex_shader_entry_point_block",
		k_number_of_entry_points + 8,
		"s_material_vertex_shader_entry_point",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_VERTEX_SHADER_ENTRY_POINT_BLOCK_STRUCT_ID)
	{
		{ _field_block, "vertex type shader indices", &compiled_vertex_shader_refererence_block },
		{ _field_terminator }
	};

	#define COMPILED_VERTEX_SHADER_REFERERENCE_BLOCK_STRUCT_ID { 0x6DFB7684, 0xE9B749F4, 0xA401B552, 0x1DDCE7D1 }
	TAG_BLOCK(
		compiled_vertex_shader_refererence_block,
		"compiled_vertex_shader_refererence_block",
		k_number_of_vertex_types + 8,
		"s_compiled_material_shader_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMPILED_VERTEX_SHADER_REFERERENCE_BLOCK_STRUCT_ID)
	{
		{ _field_long_integer, "hash" },
		{ _field_long_integer, "index" },
		{ _field_terminator }
	};

	#define COMPILED_PIXEL_SHADER_REFERERENCE_BLOCK_STRUCT_ID { 0x6DFB2384, 0xA401DD52, 0x1DABC7D1, 0xE97849F4 }
	TAG_BLOCK(
		compiled_pixel_shader_refererence_block,
		"compiled_pixel_shader_refererence_block",
		k_number_of_entry_points + 8,
		"s_compiled_material_shader_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMPILED_PIXEL_SHADER_REFERERENCE_BLOCK_STRUCT_ID)
	{
		{ _field_long_integer, "hash" },
		{ _field_long_integer, "index" },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

