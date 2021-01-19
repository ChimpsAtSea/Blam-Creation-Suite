#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(light_cone, LIGHT_CONE_TAG, light_cone_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(light_cone_block, 1, light_cone_struct_definition_struct_definition );

	V5_TAG_STRUCT(light_cone_struct_definition)
	{
		{ _field_byte_flags, "flags", &lightConeFlags },
		{ _field_pad, "gosh", 3 },
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_real, "angle fade range:degrees" },
		{ _field_real, "angle fade cutoff:degrees" },
		{ _field_real, "far fade range:wus" },
		{ _field_real, "far fade cutoff:wus" },
		{ _field_terminator }
	};

	STRINGS(lightConeFlags)
	{
		"disabled in split-screen"
	};
	STRING_LIST(lightConeFlags, lightConeFlags_strings, _countof(lightConeFlags_strings));

} // namespace blofeld

