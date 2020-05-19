#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(multiplayerEffects, MULTIPLAYEREFFECTS_TAG, multiplayerEffects_block_block );

	TAG_BLOCK(multiplayerEffectsBlock, k_multiplayer_effect_maximum_count)
	{
		{ _field_string_id, "name^" },
		{ _field_tag_reference, "effect", &effect_reference$3 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(multiplayerEffects_block, 1, multiplayerEffects_struct_definition_struct_definition );

	TAG_STRUCT(multiplayerEffects_struct_definition)
	{
		{ _field_block, "effects", &multiplayerEffectsBlock_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_multiplayer_effect_group_reference, MULTIPLAYEREFFECTS_TAG);

} // namespace blofeld

