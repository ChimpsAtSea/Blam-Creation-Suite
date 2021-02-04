#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SOUND_COMBINER_STRUCT_DEFINITION_ID { 0x736BECD5, 0x8A73405C, 0x9918CE8F, 0x8972CB83 }
	TAG_BLOCK(
		sound_combiner_block,
		"sound_combiner_block",
		1,
		"s_sound_combiner_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_COMBINER_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "entries", &sound_combiner_definition_entry_block },
		{ _field_real, "maximum play seconds", "this is determined at post process time", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "minimum distance default", "this is determined at post process time", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "maximum distance default", "this is determined at post process time", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	TAG_GROUP(
		sound_combiner_group,
		SOUND_COMBINER_TAG,
		nullptr,
		INVALID_TAG,
		sound_combiner_block );

	#define SOUND_COMBINER_DEFINITION_ENTRY_BLOCK_ID { 0x32D8ADA1, 0xDFEF403A, 0x8826F6BC, 0x9605D1D2 }
	TAG_BLOCK(
		sound_combiner_definition_entry_block,
		"sound_combiner_definition_entry_block",
		k_maximum_sound_combiner_defintion_entry_count,
		"s_sound_combiner_definition_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_COMBINER_DEFINITION_ENTRY_BLOCK_ID)
	{
		{ _field_tag_reference, "sound", &global_force_sound_only_reference },
		{ _field_real_bounds, "delay bounds", "delay before this sound is played", "seconds" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

