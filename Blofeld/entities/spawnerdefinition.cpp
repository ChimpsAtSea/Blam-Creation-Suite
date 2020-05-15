#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(spawner, SPAWNER_TAG, entity, ENTITY_TAG)
{
	{ _field_struct, "entity" },
	{ _field_custom, "$$$ SPAWNER $$$" },
	{ _field_byte_flags, "Spawner Flags" },
	{ _field_pad, "FlagPad1", 3 },
	{ _field_long_integer, "Post Spawn Cooldown (ticks)" },
	{ _field_real, "Activation Task Priority #Priority of task to activate this spawner." },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

