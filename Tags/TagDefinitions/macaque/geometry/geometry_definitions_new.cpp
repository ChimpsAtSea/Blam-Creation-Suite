#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_GEOMETRY_MATERIAL_BLOCK_ID { 0xB1135973, 0x34A54DC5, 0x99901631, 0xB0B5E573 }
	TAG_BLOCK(
		global_geometry_material_block,
		"material",
		MAXIMUM_MATERIALS_PER_GEOMETRY,
		"geometry_material",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_GEOMETRY_MATERIAL_BLOCK_ID)
	{
		{ _field_tag_reference, "render method", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &global_geometry_material_block_render_method_reference },
		{ _field_long_integer, "imported material index", FIELD_FLAG_READ_ONLY },
		{ _field_real, "lightmap resolution scale" },
		{ _field_long_integer, "lightmap additive transparency color" },
		{ _field_long_integer, "lightmap traslucency tint color" },
		{ _field_real, "lightmap analytical light absorb" },
		{ _field_real, "lightmap normal light absorb" },
		{ _field_byte_flags, "lightmap flags", &global_geometry_material_lightmap_flags },
		{ _field_char_integer, "breakable surface index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "lightmap chart group index" },
		{ _field_terminator }
	};

	STRINGS(global_geometry_material_lightmap_flags)
	{
		"ignore default resolution scale",
		"transparency override",
		"lighting from both sides",
		"version1"
	};
	STRING_LIST(global_geometry_material_lightmap_flags, global_geometry_material_lightmap_flags_strings, _countof(global_geometry_material_lightmap_flags_strings));

} // namespace macaque

} // namespace blofeld

