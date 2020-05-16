#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(player_model_customization_globals, PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG, player_model_customization_globals_block_block )

TAG_BLOCK_FROM_STRUCT(player_model_customization_globals_block, 1, player_model_customization_globals_struct_definition_struct_definition );

TAG_BLOCK(customized_model_selection_block, k_maximum_number_of_model_customization_selections_per_area)
{
	FIELD( _field_string_id, "selection name^" ),
	FIELD( _field_string_id, "app name#Which player-stats modifier should be activated when this item is equipped" ),
	FIELD( _field_block, "customized bits", &customized_model_player_bits_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(customized_model_player_bits_block, k_maximum_number_of_model_customization_bits_per_selection)
{
	FIELD( _field_string_id, "region name^" ),
	FIELD( _field_string_id, "permutation name" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad1", 3 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(player_model_customization_globals_struct_definition)
{
	FIELD( _field_tag_reference, "spartan render model#used for string list generation" ),
	FIELD( _field_tag_reference, "elite render model!" ),
	FIELD( _field_block, "helmet selections", &customized_model_selection_block_block ),
	FIELD( _field_block, "chest selections", &customized_model_selection_block_block ),
	FIELD( _field_block, "elite selections!", &customized_model_selection_block_block ),
	FIELD( _field_block, "left shoulder", &customized_model_selection_block_block ),
	FIELD( _field_block, "right shoulder", &customized_model_selection_block_block ),
	FIELD( _field_block, "arms", &customized_model_selection_block_block ),
	FIELD( _field_block, "legs", &customized_model_selection_block_block ),
	FIELD( _field_block, "unused 5!", &customized_model_selection_block_block ),
	FIELD( _field_block, "spartan armor effect selections", &customized_model_selection_block_block ),
	FIELD( _field_block, "elite armor effect selections!", &customized_model_selection_block_block ),
	FIELD( _field_block, "male spartan selections", &customized_model_player_bits_block_block ),
	FIELD( _field_block, "female spartan selections", &customized_model_player_bits_block_block ),
	FIELD( _field_block, "spartan model defaults", &customized_model_player_bits_block_block ),
	FIELD( _field_block, "elite model defaults!", &customized_model_player_bits_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

