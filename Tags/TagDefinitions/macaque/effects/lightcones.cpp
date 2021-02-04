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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_CONE_STRUCT_DEFINITION_ID)
	{
		{ _field_byte_flags, "flags", &lightConeFlags },
		FIELD_PAD("gosh", nullptr, 3),
		FIELD_CUSTOM("material", nullptr, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_begin),
		{ _field_struct, "actual material?", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_end),
		{ _field_real, "angle fade range", nullptr, "degrees" },
		{ _field_real, "angle fade cutoff", nullptr, "degrees" },
		{ _field_real, "far fade range", nullptr, "wus" },
		{ _field_real, "far fade cutoff", nullptr, "wus" },
		{ _field_terminator }
	};

	STRINGS(lightConeFlags)
	{
		"disabled in split-screen"
	};
	STRING_LIST(lightConeFlags, lightConeFlags_strings, _countof(lightConeFlags_strings));

} // namespace macaque

} // namespace blofeld

