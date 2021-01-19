#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		light_cone_group,
		LIGHT_CONE_TAG,
		nullptr,
		INVALID_TAG,
		light_cone_block );

	TAG_BLOCK_FROM_STRUCT(
		light_cone_block,
		"light_cone_block",
		1,
		light_cone_struct_definition);

	#define LIGHT_CONE_STRUCT_DEFINITION_ID { 0xEA23F17B, 0x58F148D7, 0xAD1DFE08, 0xBDD37574 }
	TAG_STRUCT(
		light_cone_struct_definition,
		"light_cone_struct_definition",
		"LightConeDefinition",
		LIGHT_CONE_STRUCT_DEFINITION_ID)
	{
		{ _field_byte_flags, "flags", &lightConeFlags },
		{ _field_pad, "gosh", 3 },
		FIELD_CUSTOM("material", _custom_field_shader_template),
		FIELD_CUSTOM(nullptr, _custom_field_hidd_begin),
		{ _field_struct, "actual material\?", &material_struct },
		FIELD_CUSTOM(nullptr, _custom_field_hidd_end),
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

} // namespace macaque

} // namespace blofeld

