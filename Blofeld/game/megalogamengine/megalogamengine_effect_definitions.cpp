#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(multiplayerEffects_struct_definition)
{
	FIELD( _field_block, "effects", &multiplayerEffectsBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(multiplayerEffectsBlock, k_multiplayer_effect_maximum_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_tag_reference, "effect" ),
	FIELD( _field_terminator )
};

TAG_GROUP(multiplayerEffects_block, MULTIPLAYEREFFECTS_TAG)
{
	FIELD( _field_block, "effects", &multiplayerEffectsBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld

