#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		detail_object_collection_group,
		DETAIL_OBJECT_COLLECTION_TAG,
		nullptr,
		INVALID_TAG,
		detail_object_collection_block );

	TAG_BLOCK_FROM_STRUCT(
		detail_object_collection_block,
		"detail_object_collection_block",
		1,
		detail_object_collection_struct_definition);

	#define DETAIL_OBJECT_TYPE_BLOCK_ID { 0xAD1BA8EC, 0x9D6D4B81, 0x941E1C74, 0x6B46F40A }
	TAG_BLOCK(
		detail_object_type_block,
		"detail_object_type_block",
		MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION,
		"detail_object_type_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DETAIL_OBJECT_TYPE_BLOCK_ID)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_char_integer, "sequence index", nullptr, nullptr, "[0,15]" },
		{ _field_byte_flags, "type flags", &detail_object_type_flags_definition },
		FIELD_PAD("VYF", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "color override factor", "fraction of detail object color to use instead of the base map color in the environment:[0,1]" },
		FIELD_PAD("QMOOJ", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "near fade distance", nullptr, "world units" },
		{ _field_real, "far fade distance", nullptr, "world units" },
		{ _field_real, "size", nullptr, "world units per pixel" },
		FIELD_PAD("TDAQ", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_rgb_color, "minimum color", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "maximum color", nullptr, nullptr, "[0,1]" },
		{ _field_argb_color, "ambient color", nullptr, nullptr, "[0,255]" },
		FIELD_PAD("VCXJHYY", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	#define GLOBAL_DETAIL_OBJECT_CELLS_BLOCK_ID { 0x1960315C, 0xBFE04781, 0xBB7BDB66, 0x5627F0EE }
	TAG_BLOCK(
		global_detail_object_cells_block,
		"global_detail_object_cells_block",
		MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE,
		"detail_object_cell_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DETAIL_OBJECT_CELLS_BLOCK_ID)
	{
		{ _field_short_integer, "cell x", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "cell y", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "cell z", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "offset z", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "valid layers flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "start index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "count index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("OHF", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	#define GLOBAL_DETAIL_OBJECT_BLOCK_ID { 0x1418CEDE, 0x449D419B, 0x9406F322, 0xA3D43D98 }
	TAG_BLOCK(
		global_detail_object_block,
		"global_detail_object_block",
		MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE,
		"detail_object",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DETAIL_OBJECT_BLOCK_ID)
	{
		{ _field_char_integer, "position x", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "position y", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "position z", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "color", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define GLOBAL_DETAIL_OBJECT_COUNTS_BLOCK_ID { 0xCB802C6A, 0xFBE64494, 0x9401AEFB, 0x0759E910 }
	TAG_BLOCK(
		global_detail_object_counts_block,
		"global_detail_object_counts_block",
		MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE*MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE,
		"detail_object_count",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_DETAIL_OBJECT_COUNTS_BLOCK_ID)
	{
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define GLOBAL_Z_REFERENCE_VECTOR_BLOCK_ID { 0x2BDA3AB4, 0x28434572, 0xA6BF6C69, 0x72508C99 }
	TAG_BLOCK(
		global_z_reference_vector_block,
		"global_z_reference_vector_block",
		MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE,
		"real_vector4d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_Z_REFERENCE_VECTOR_BLOCK_ID)
	{
		{ _field_real, "z reference i", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "z reference j", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "z reference k", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "z reference l", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define DETAIL_OBJECT_COLLECTION_STRUCT_DEFINITION_ID { 0x5410E64E, 0x0296459C, 0xAC1594F8, 0xF1099A8B }
	TAG_STRUCT(
		detail_object_collection_struct_definition,
		"detail_object_collection_struct_definition",
		"detail_object_collection_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DETAIL_OBJECT_COLLECTION_STRUCT_DEFINITION_ID)
	{
		{ _field_enum, "collection type", &detail_object_collection_type_enum_definition },
		FIELD_PAD("YN", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "global z offset", nullptr, "applied to all detail objects of in this collection so they don't float above the ground" },
		FIELD_PAD("EBGQ", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_tag_reference, "sprite plate", &global_bitmap_reference },
		{ _field_block, "types", &detail_object_type_block },
		FIELD_PAD("ZQUVEZKGL", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	STRINGS(detail_object_collection_type_enum_definition)
	{
		"screen-facing",
		"viewer-facing"
	};
	STRING_LIST(detail_object_collection_type_enum_definition, detail_object_collection_type_enum_definition_strings, _countof(detail_object_collection_type_enum_definition_strings));

	STRINGS(detail_object_type_flags_definition)
	{
		"unused0!",
		"unused1!",
		"interpolate color in hsv",
		"...more colors"
	};
	STRING_LIST(detail_object_type_flags_definition, detail_object_type_flags_definition_strings, _countof(detail_object_type_flags_definition_strings));

	TAG_REFERENCE(global_detail_object_collection_reference, DETAIL_OBJECT_COLLECTION_TAG);



} // namespace blofeld

