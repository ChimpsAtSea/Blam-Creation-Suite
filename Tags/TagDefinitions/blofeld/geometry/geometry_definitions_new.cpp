#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(global_geometry_material_block, MAXIMUM_MATERIALS_PER_GEOMETRY)
	{
		{ _field_tag_reference, "render method^*", &global_geometry_material_block_render_method_reference },
		{ _field_long_integer, "imported material index*" },
		{ _field_real, "lightmap resolution scale" },
		{ _field_long_integer, "lightmap additive transparency color" },
		{ _field_long_integer, "lightmap traslucency tint color" },
		{ _field_real, "lightmap analytical light absorb" },
		{ _field_real, "lightmap normal light absorb" },
		{ _field_byte_flags, "lightmap flags", &global_geometry_material_lightmap_flags },
		{ _field_char_integer, "breakable surface index*" },
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

} // namespace blofeld

