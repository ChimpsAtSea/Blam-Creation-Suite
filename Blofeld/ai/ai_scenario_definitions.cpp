#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(character_palette, 64)
{
	{ _field_tag_reference, "reference^" },
	{ _field_terminator },
};

TAG_BLOCK(ai_recording_reference, 128)
{
	{ _field_string, "recording name^" },
	{ _field_pad, "INYRGOR", 8 },
	{ _field_terminator },
};

TAG_BLOCK(big_battle_creature_palette, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
{
	{ _field_tag_reference, "reference^" },
	{ _field_terminator },
};

} // namespace blofeld

