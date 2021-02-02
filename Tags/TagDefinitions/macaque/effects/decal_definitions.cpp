#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		decal_system_group,
		DECAL_SYSTEM_TAG,
		nullptr,
		INVALID_TAG,
		decal_system_block );

	TAG_BLOCK_FROM_STRUCT(
		decal_system_block,
		"decal_system_block",
		1,
		decal_system_struct_definition);

	#define DECAL_DEFINITION_BLOCK_ID { 0x05E5AE1B, 0x33A44FBF, 0x83F60D66, 0xAC15FDB8 }
	TAG_BLOCK(
		decal_definition_block,
		"decal_definition_block",
		c_decal_system_definition::k_max_decal,
		"c_decal_definition",
		DECAL_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "decal name" },
		{ _field_long_flags, "flags", &decal_flags },
		FIELD_CUSTOM("material", nullptr, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_begin),
		{ _field_struct, "actual material", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_end),
		{ _field_real_bounds, "radius", "world units" },
		{ _field_real_bounds, "decay time", "seconds" },
		{ _field_real_bounds, "lifespan", "seconds" },
		{ _field_real, "clamp angle", "Projections at greater than this angle will be clamped to this angle", "degrees" },
		{ _field_real, "cull angle", "Projections at greater than this angle will not be drawn", "degrees" },
		{ _field_real, "depth bias" },
		FIELD_CUSTOM("Decal Strip", nullptr, _field_id_function_group_begin),
		{ _field_real, "strip U-coordinate tile length" },
		{ _field_real, "strip max profile distance" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_real, "runtime bitmap aspect" },
		{ _field_terminator }
	};

	#define DECAL_SYSTEM_STRUCT_DEFINITION_ID { 0x570BB931, 0x8CB3411C, 0xB0466FBE, 0x7FE4EEE5 }
	TAG_STRUCT(
		decal_system_struct_definition,
		"decal_system_struct_definition",
		"c_decal_system_definition",
		DECAL_SYSTEM_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &decal_system_flags },
		{ _field_long_integer, "ring buffer size (in triangles)", "bigger sizes keep more decals around but use much more memory" },
		{ _field_long_integer, "ring buffer size single player (in triangles)", "above entry is for MP -- SP can be different" },
		{ _field_real, "material shader fade time", "material shader lifetime is modulated from 1 to 0 over this time" },
		{ _field_real_point_2d, "decal scale override", "NOTE - If set to non-zero, this will override manual scaling in Sapien and smash it with these values" },
		{ _field_explanation, "Decal bucket sharing", "For the index bounds below, if non-zero, sprites will be chosen between low and high bounds, inclusive.\nUse this to keep multiple different decals in the same bucket.\nIf multiple decal systems use the same bitmap set and the same material definition, they will be combined at runtime and share their vertex bucket.\nThis is more efficient in memory and more performant to render." },
		{ _field_short_bounds, "random sprite index bounds", "if zero, will use random sprite" },
		{ _field_block, "decals", &decal_definition_block },
		{ _field_real, "runtime max radius" },
		{ _field_terminator }
	};

	STRINGS(decal_flags)
	{
		"render in transparents pass"
	};
	STRING_LIST(decal_flags, decal_flags_strings, _countof(decal_flags_strings));

	STRINGS(decal_system_flags)
	{
		"random rotation",
		"force planar",
		"is strip"
	};
	STRING_LIST(decal_system_flags, decal_system_flags_strings, _countof(decal_system_flags_strings));

} // namespace macaque

} // namespace blofeld

