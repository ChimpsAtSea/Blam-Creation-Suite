#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(multiplayerEffects, MULTIPLAYEREFFECTS_TAG, multiplayerEffects_block_block );

	TAG_BLOCK_FROM_STRUCT(multiplayerEffects_block, 1, multiplayerEffects_struct_definition_struct_definition );

	TAG_BLOCK(multiplayerEffectsBlock, k_multiplayer_effect_maximum_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_tag_reference, "effect" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(multiplayerEffects_struct_definition)
{
		FIELD( _field_block, "effects", &multiplayerEffectsBlock_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

