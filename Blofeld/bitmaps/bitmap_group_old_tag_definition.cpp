#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(bitmap_group_sprite_block_def, MAXIMUM_SPRITES_PER_SEQUENCE)
	{
		FIELD( _field_short_integer, "bitmap index*" ),
		FIELD( _field_pad, "D", 2 ),
		FIELD( _field_pad, "GMLJPJIMC", 4 ),
		FIELD( _field_real, "left*" ),
		FIELD( _field_real, "right*" ),
		FIELD( _field_real, "top*" ),
		FIELD( _field_real, "bottom*" ),
		FIELD( _field_real_point_2d, "registration point*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(bitmap_group_sequence_block_def, MAXIMUM_SEQUENCES_PER_BITMAP_GROUP)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_short_integer, "first bitmap index*" ),
		FIELD( _field_short_integer, "bitmap count*" ),
		FIELD( _field_pad, "OTXYKQ", 16 ),
		FIELD( _field_block, "sprites*", &bitmap_group_sprite_block_def_block ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

