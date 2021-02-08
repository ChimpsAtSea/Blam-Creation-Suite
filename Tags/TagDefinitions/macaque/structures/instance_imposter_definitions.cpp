#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		instance_imposter_definition_group,
		INSTANCE_IMPOSTER_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		instance_imposter_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		instance_imposter_definition_block,
		"instance_imposter_definition_block",
		1,
		instance_imposter_definition_struct_definition);

	#define INSTANCE_IMPOSTER_BLOCK_ID { 0x97F8A998, 0xFEB34595, 0x9C9AC5A1, 0xD7B18C9F }
	TAG_BLOCK(
		instance_imposter_block,
		"instance_imposter_block",
		k_maximum_instance_geometry_instances_per_structure_bsp,
		"s_instance_imposter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANCE_IMPOSTER_BLOCK_ID)
	{
		{ _field_short_integer, "group index" },
		{ _field_char_integer, "subpart_index" },
		{ _field_byte_flags, "flags", &instance_imposter_element_flags_definition },
		{ _field_terminator }
	};

	#define INSTANCE_IMPOSTER_CHECKSUM_BLOCK_ID { 0xBDCB9FB0, 0x1E5341AC, 0x8C9A9538, 0x9EAB6747 }
	TAG_BLOCK(
		instance_imposter_checksum_block,
		"instance_imposter_checksum_block",
		k_maximum_instance_geometry_instances_per_structure_bsp,
		"s_instance_imposter_checksum",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANCE_IMPOSTER_CHECKSUM_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_long_integer, "import checksum" },
		{ _field_long_integer, "transform checksum" },
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "left" },
		{ _field_real_vector_3d, "up" },
		{ _field_real_point_3d, "position" },
		{ _field_short_integer, "imposter version" },
		{ _field_char_integer, "imposter policy" },
		FIELD_PAD("padefefrdapad", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_real, "bounding radius" },
		{ _field_real, "transition distance" },
		{ _field_terminator }
	};

	#define INSTANCE_IMPOSTER_DEFINITION_STRUCT_DEFINITION_ID { 0x5011F34B, 0x64DA4902, 0x8930C061, 0xF724EA33 }
	TAG_STRUCT(
		instance_imposter_definition_struct_definition,
		"instance_imposter_definition_struct_definition",
		"s_instance_imposter_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANCE_IMPOSTER_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &instance_imposter_flags_definition },
		{ _field_string_id, "bsp name" },
		{ _field_long_integer, "checksum" },
		{ _field_string_id, "source metadata path" },
		{ _field_block, "instances", &instance_imposter_block },
		{ _field_block, "instance checksums", &instance_imposter_checksum_block },
		FIELD_CUSTOM("atlas info", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_short_integer, "atlas tile resolution" },
		{ _field_char_integer, "atlas x tile count" },
		{ _field_char_integer, "atlas y tile count" },
		{ _field_tag_reference, "atlas texture", &global_bitmap_reference },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("mesh data", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "render geometry", &global_render_geometry_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	STRINGS(instance_imposter_flags_definition)
	{
		"raw geometry compressed",
		"use raw instance imposter verts",
		"valid and good to go",
		"build completed"
	};
	STRING_LIST(instance_imposter_flags_definition, instance_imposter_flags_definition_strings, _countof(instance_imposter_flags_definition_strings));

	STRINGS(instance_imposter_element_flags_definition)
	{
		"card",
		"poly",
		"rainbow box",
		"occlusion"
	};
	STRING_LIST(instance_imposter_element_flags_definition, instance_imposter_element_flags_definition_strings, _countof(instance_imposter_element_flags_definition_strings));

	TAG_REFERENCE(global_instance_imposter_reference, INSTANCE_IMPOSTER_DEFINITION_TAG);

} // namespace macaque

} // namespace blofeld

