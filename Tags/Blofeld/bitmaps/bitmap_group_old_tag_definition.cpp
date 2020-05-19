#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(bitmap_group_sprite_block_def, MAXIMUM_SPRITES_PER_SEQUENCE)
	{
		{ _field_short_integer, "bitmap index*" },
		{ _field_pad, "D", 2 },
		{ _field_pad, "GMLJPJIMC", 4 },
		{ _field_real, "left*" },
		{ _field_real, "right*" },
		{ _field_real, "top*" },
		{ _field_real, "bottom*" },
		{ _field_real_point_2d, "registration point*" },
		{ _field_terminator }
	};

	TAG_BLOCK(bitmap_group_sequence_block_def, MAXIMUM_SEQUENCES_PER_BITMAP_GROUP)
	{
		{ _field_string, "name^" },
		{ _field_short_integer, "first bitmap index*" },
		{ _field_short_integer, "bitmap count*" },
		{ _field_pad, "OTXYKQ", 16 },
		{ _field_block, "sprites*", &bitmap_group_sprite_block_def_block },
		{ _field_terminator }
	};

} // namespace blofeld

