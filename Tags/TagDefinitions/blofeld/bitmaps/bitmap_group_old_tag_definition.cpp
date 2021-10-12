#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define BITMAP_GROUP_SEQUENCE_BLOCK_DEF_ID { 0x15026732, 0x9E8B45CE, 0xB853499B, 0x557C9320 }
	TAG_BLOCK(
		bitmap_group_sequence_block_def_block,
		"bitmap_group_sequence_block_def",
		MAXIMUM_SEQUENCES_PER_BITMAP_GROUP,
		"bitmap_group_sequence",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_GROUP_SEQUENCE_BLOCK_DEF_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_short_integer, "first bitmap index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "bitmap count", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("OTXYKQ", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_block, "sprites", FIELD_FLAG_READ_ONLY, &bitmap_group_sprite_block_def_block },
		{ _field_terminator }
	};

	#define BITMAP_GROUP_SPRITE_BLOCK_DEF_ID { 0xBBF4F819, 0xF00A42DC, 0xA731202E, 0x289D9752 }
	TAG_BLOCK(
		bitmap_group_sprite_block_def_block,
		"bitmap_group_sprite_block_def",
		MAXIMUM_SPRITES_PER_SEQUENCE,
		"bitmap_group_sprite",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BITMAP_GROUP_SPRITE_BLOCK_DEF_ID)
	{
		{ _field_short_integer, "bitmap index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("D", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("GMLJPJIMC", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "left", FIELD_FLAG_READ_ONLY },
		{ _field_real, "right", FIELD_FLAG_READ_ONLY },
		{ _field_real, "top", FIELD_FLAG_READ_ONLY },
		{ _field_real, "bottom", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_2d, "registration point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};



} // namespace blofeld

