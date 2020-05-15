#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(customized_model_selection, k_maximum_number_of_model_customization_selections_per_area)
{
	{ _field_string_id, "selection name^" },
	{ _field_string_id, "app name#Which player-stats modifier should be activated when this item is equipped" },
	{ _field_block, "customized bits", &customized_model_player_bits_block },
	{ _field_terminator },
};

TAG_BLOCK(customized_model_player_bits, k_maximum_number_of_model_customization_bits_per_selection)
{
	{ _field_string_id, "region name^" },
	{ _field_string_id, "permutation name" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad1", 3 },
	{ _field_terminator },
};

TAG_GROUP(player_model_customization_globals, PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG)
{
	{ _field_tag_reference, "spartan render model#used for string list generation" },
	{ _field_tag_reference, "elite render model!" },
	{ _field_block, "helmet selections", &customized_model_selection_block },
	{ _field_block, "chest selections", &customized_model_selection_block },
	{ _field_block, "elite selections!", &customized_model_selection_block },
	{ _field_block, "left shoulder", &customized_model_selection_block },
	{ _field_block, "right shoulder", &customized_model_selection_block },
	{ _field_block, "arms", &customized_model_selection_block },
	{ _field_block, "legs", &customized_model_selection_block },
	{ _field_block, "unused 5!", &customized_model_selection_block },
	{ _field_block, "spartan armor effect selections", &customized_model_selection_block },
	{ _field_block, "elite armor effect selections!", &customized_model_selection_block },
	{ _field_block, "male spartan selections", &customized_model_player_bits_block },
	{ _field_block, "female spartan selections", &customized_model_player_bits_block },
	{ _field_block, "spartan model defaults", &customized_model_player_bits_block },
	{ _field_block, "elite model defaults!", &customized_model_player_bits_block },
	{ _field_terminator },
};

} // namespace blofeld

