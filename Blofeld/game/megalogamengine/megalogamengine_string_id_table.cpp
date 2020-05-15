#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(megalo_string_id, k_maximum_megalo_string_ids)
{
	{ _field_string_id, "string_id^" },
	{ _field_terminator },
};

TAG_BLOCK(megalo_string_id_to_sprite_index, k_maximum_megalo_string_ids)
{
	{ _field_custom_long_block_index, "from megalo string_id" },
	{ _field_long_integer, "loadout menu sprite frame" },
	{ _field_terminator },
};

TAG_GROUP(megalo_string_id_table, MEGALO_STRING_ID_TABLE_TAG)
{
	{ _field_block, "megalo string_ids", &megalo_string_id_block },
	{ _field_block, "megalo string_ids sprite mapping", &megalo_string_id_to_sprite_index_block },
	{ _field_terminator },
};

} // namespace blofeld

