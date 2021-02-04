#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
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
		{ _field_string, "name" },
		{ _field_char_integer, "sequence index" },
		{ _field_byte_flags, "type flags", &detail_object_type_flags_definition },
		FIELD_PAD("VYF", nullptr, 2),
		{ _field_real_fraction, "color override factor", "fraction of detail object color to use instead of the base map color in the environment:[0,1]" },
		FIELD_PAD("QMOOJ", nullptr, 8),
		{ _field_real, "near fade distance", "world units" },
		{ _field_real, "far fade distance", "world units" },
		{ _field_real, "size", "world units per pixel" },
		FIELD_PAD("TDAQ", nullptr, 4),
		{ _field_real_rgb_color, "minimum color" },
		{ _field_real_rgb_color, "maximum color" },
		{ _field_argb_color, "ambient color" },
		FIELD_PAD("VCXJHYY", nullptr, 4),
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
		{ _field_short_integer, "cell x" },
		{ _field_short_integer, "cell y" },
		{ _field_short_integer, "cell z" },
		{ _field_short_integer, "offset z" },
		{ _field_long_integer, "valid layers flags" },
		{ _field_long_integer, "start index" },
		{ _field_long_integer, "count index" },
		FIELD_PAD("OHF", nullptr, 12),
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
		{ _field_char_integer, "position x" },
		{ _field_char_integer, "position y" },
		{ _field_char_integer, "position z" },
		{ _field_char_integer, "data" },
		{ _field_short_integer, "color" },
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
		{ _field_short_integer, "count" },
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
		{ _field_real, "z reference i" },
		{ _field_real, "z reference j" },
		{ _field_real, "z reference k" },
		{ _field_real, "z reference l" },
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
		FIELD_PAD("YN", nullptr, 2),
		{ _field_real, "global z offset", "applied to all detail objects of in this collection so they don't float above the ground" },
		FIELD_PAD("EBGQ", nullptr, 44),
		{ _field_tag_reference, "sprite plate", &global_bitmap_reference },
		{ _field_block, "types", &detail_object_type_block },
		FIELD_PAD("ZQUVEZKGL", nullptr, 48),
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

} // namespace macaque

} // namespace blofeld

