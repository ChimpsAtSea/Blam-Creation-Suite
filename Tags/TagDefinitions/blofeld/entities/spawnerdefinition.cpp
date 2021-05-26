#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		spawner_group,
		SPAWNER_TAG,
		&entity_group,
		ENTITY_TAG,
		spawner_block );

	TAG_BLOCK_FROM_STRUCT(
		spawner_block,
		"spawner_block",
		1,
		spawner_struct_definition);

	#define SPAWNER_STRUCT_DEFINITION_ID { 0x46E8CDF0, 0x61314324, 0x991AD00C, 0xB3F53689 }
	TAG_STRUCT(
		spawner_struct_definition,
		"spawner_struct_definition",
		"SpawnerDefinitionInternal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SPAWNER_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "entity", &entity_struct_definition },
		FIELD_CUSTOM("$$$ SPAWNER $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_byte_flags, "Spawner Flags", &SpawnerFlags },
		FIELD_PAD("FlagPad1", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_long_integer, "Post Spawn Cooldown (ticks)" },
		{ _field_real, "Activation Task Priority ", "Priority of task to activate this spawner." },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	STRINGS(SpawnerFlags)
	{
		"Cooldown Waits for Object Death"
	};
	STRING_LIST(SpawnerFlags, SpawnerFlags_strings, _countof(SpawnerFlags_strings));



} // namespace blofeld

