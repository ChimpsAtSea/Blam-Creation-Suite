#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(multiplayerEffects, MULTIPLAYEREFFECTS_TAG, multiplayerEffects_block_block );

	V5_TAG_BLOCK(multiplayerEffectsBlock, k_multiplayer_effect_maximum_count)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_tag_reference, "effect", &effect_reference$3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(multiplayerEffects_block, 1, multiplayerEffects_struct_definition_struct_definition );

	V5_TAG_STRUCT(multiplayerEffects_struct_definition)
	{
		{ _field_legacy, _field_block, "effects", &multiplayerEffectsBlock_block },
		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(global_multiplayer_effect_group_reference, MULTIPLAYEREFFECTS_TAG);

} // namespace blofeld

