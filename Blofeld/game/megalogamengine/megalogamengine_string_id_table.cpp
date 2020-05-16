#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(megalo_string_id_table_struct_definition)
{
	FIELD( _field_block, "megalo string_ids", &megalo_string_id_block ),
	FIELD( _field_block, "megalo string_ids sprite mapping", &megalo_string_id_to_sprite_index_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(megalo_string_id_block, k_maximum_megalo_string_ids)
{
	FIELD( _field_string_id, "string_id^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(megalo_string_id_to_sprite_index_block, k_maximum_megalo_string_ids)
{
	FIELD( _field_custom_long_block_index, "from megalo string_id" ),
	FIELD( _field_long_integer, "loadout menu sprite frame" ),
	FIELD( _field_terminator )
};

TAG_GROUP(megalo_string_id_table_block, MEGALO_STRING_ID_TABLE_TAG)
{
	FIELD( _field_block, "megalo string_ids", &megalo_string_id_block ),
	FIELD( _field_block, "megalo string_ids sprite mapping", &megalo_string_id_to_sprite_index_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

