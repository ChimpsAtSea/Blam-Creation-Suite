#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(spawner_struct_definition)
{
	FIELD( _field_struct, "entity", &entity_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ SPAWNER $$$" ),
	FIELD( _field_byte_flags, "Spawner Flags" ),
	FIELD( _field_pad, "FlagPad1", 3 ),
	FIELD( _field_long_integer, "Post Spawn Cooldown (ticks)" ),
	FIELD( _field_real, "Activation Task Priority #Priority of task to activate this spawner." ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(spawner_block, SPAWNER_TAG, entity, ENTITY_TAG)
{
	FIELD( _field_struct, "entity", &entity_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ SPAWNER $$$" ),
	FIELD( _field_byte_flags, "Spawner Flags" ),
	FIELD( _field_pad, "FlagPad1", 3 ),
	FIELD( _field_long_integer, "Post Spawn Cooldown (ticks)" ),
	FIELD( _field_real, "Activation Task Priority #Priority of task to activate this spawner." ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

