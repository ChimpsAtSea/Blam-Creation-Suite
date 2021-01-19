#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
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
		SPAWNER_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "entity", &entity_struct_definition },
		FIELD_CUSTOM("$$$ SPAWNER $$$", _custom_field_function_group_begin),
		{ _field_byte_flags, "Spawner Flags", &SpawnerFlags },
		{ _field_pad, "FlagPad1", 3 },
		{ _field_long_integer, "Post Spawn Cooldown (ticks)" },
		{ _field_real, "Activation Task Priority #Priority of task to activate this spawner." },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	STRINGS(SpawnerFlags)
	{
		"Cooldown Waits for Object Death"
	};
	STRING_LIST(SpawnerFlags, SpawnerFlags_strings, _countof(SpawnerFlags_strings));

} // namespace macaque

} // namespace blofeld

