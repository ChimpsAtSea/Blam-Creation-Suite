#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(multiplayerEffectsBlock, k_multiplayer_effect_maximum_count)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "effect" },
	{ _field_terminator },
};

TAG_GROUP(multiplayerEffects, MULTIPLAYEREFFECTS_TAG)
{
	{ _field_block, "effects", &multiplayerEffectsBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

