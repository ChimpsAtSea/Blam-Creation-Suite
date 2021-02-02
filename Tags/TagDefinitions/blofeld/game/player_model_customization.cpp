#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(player_model_customization_globals, PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG, player_model_customization_globals_block_block );

	V5_TAG_BLOCK(customized_model_player_bits_block, k_maximum_number_of_model_customization_bits_per_selection)
	{
		{ _field_legacy, _field_string_id, "region name^" },
		{ _field_legacy, _field_string_id, "permutation name" },
		{ _field_legacy, _field_byte_flags, "flags", &model_customization_player_permutation_flags },
		{ _field_legacy, _field_pad, "pad1", 3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(customized_model_selection_block, k_maximum_number_of_model_customization_selections_per_area)
	{
		{ _field_legacy, _field_string_id, "selection name^" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_string_id, "app name#Which player-stats modifier should be activated when this item is equipped" },

		{ _field_legacy, _field_block, "customized bits", &customized_model_player_bits_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(player_model_customization_globals_block, 1, player_model_customization_globals_struct_definition_struct_definition );

	V5_TAG_STRUCT(player_model_customization_globals_struct_definition)
	{
		{ _field_legacy, _field_tag_reference, "spartan render model#used for string list generation", &render_model_reference$7 },
		{ _field_legacy, _field_tag_reference, "elite render model!", &render_model_reference$7 },
		{ _field_legacy, _field_block, "helmet selections", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "chest selections", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "elite selections!", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "left shoulder", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "right shoulder", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "arms", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "legs", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "unused 5!", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "spartan armor effect selections", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "elite armor effect selections!", &customized_model_selection_block_block },
		{ _field_legacy, _field_block, "male spartan selections", &customized_model_player_bits_block_block },
		{ _field_legacy, _field_block, "female spartan selections", &customized_model_player_bits_block_block },
		{ _field_legacy, _field_block, "spartan model defaults", &customized_model_player_bits_block_block },
		{ _field_legacy, _field_block, "elite model defaults!", &customized_model_player_bits_block_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(model_customization_player_permutation_flags)
	{
		"male_only#this permutation only applies to male players",
		"female_only#this permutation only applies to female players",
		"mandibles_hidden#this permutation is an elite with enclosed helmet"
	};
	STRING_LIST(model_customization_player_permutation_flags, model_customization_player_permutation_flags_strings, _countof(model_customization_player_permutation_flags_strings));

	TAG_REFERENCE(global_player_model_customization_globals_reference, PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG);

} // namespace blofeld

