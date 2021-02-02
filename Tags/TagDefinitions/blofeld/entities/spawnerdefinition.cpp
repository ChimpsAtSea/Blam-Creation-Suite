#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(spawner, SPAWNER_TAG, entity, ENTITY_TAG, spawner_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(spawner_block, 1, spawner_struct_definition_struct_definition );

	V5_TAG_STRUCT(spawner_struct_definition)
	{
		{ _field_legacy, _field_struct, "entity", &entity_struct_definition_struct_definition },
		{ _field_legacy, _field_custom, "$$$ SPAWNER $$$" },
		{ _field_legacy, _field_byte_flags, "Spawner Flags", &SpawnerFlags },
		{ _field_legacy, _field_pad, "FlagPad1", 3 },
		{ _field_legacy, _field_long_integer, "Post Spawn Cooldown (ticks)" },
		{ _field_legacy, _field_real, "Activation Task Priority #Priority of task to activate this spawner." },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(SpawnerFlags)
	{
		"Cooldown Waits for Object Death"
	};
	STRING_LIST(SpawnerFlags, SpawnerFlags_strings, _countof(SpawnerFlags_strings));

} // namespace blofeld

