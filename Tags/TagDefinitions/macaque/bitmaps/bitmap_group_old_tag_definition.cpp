#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define BITMAP_GROUP_SEQUENCE_BLOCK_DEF_ID { 0x15026732, 0x9E8B45CE, 0xB853499B, 0x557C9320 }
	TAG_BLOCK(
		bitmap_group_sequence_block_def_block,
		"bitmap_group_sequence_block_def",
		MAXIMUM_SEQUENCES_PER_BITMAP_GROUP,
		"bitmap_group_sequence",
		BITMAP_GROUP_SEQUENCE_BLOCK_DEF_ID)
	{
		{ _field_string, "name" },
		{ _field_short_integer, "first bitmap index" },
		{ _field_short_integer, "bitmap count" },
		FIELD_PAD("OTXYKQ", nullptr, 16),
		{ _field_block, "sprites", &bitmap_group_sprite_block_def_block },
		{ _field_terminator }
	};

	#define BITMAP_GROUP_SPRITE_BLOCK_DEF_ID { 0xBBF4F819, 0xF00A42DC, 0xA731202E, 0x289D9752 }
	TAG_BLOCK(
		bitmap_group_sprite_block_def_block,
		"bitmap_group_sprite_block_def",
		MAXIMUM_SPRITES_PER_SEQUENCE,
		"bitmap_group_sprite",
		BITMAP_GROUP_SPRITE_BLOCK_DEF_ID)
	{
		{ _field_short_integer, "bitmap index" },
		FIELD_PAD("D", nullptr, 2),
		FIELD_PAD("GMLJPJIMC", nullptr, 4),
		{ _field_real, "left" },
		{ _field_real, "right" },
		{ _field_real, "top" },
		{ _field_real, "bottom" },
		{ _field_real_point_2d, "registration point" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

