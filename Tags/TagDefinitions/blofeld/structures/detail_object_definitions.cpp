#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(detail_object_collection, DETAIL_OBJECT_COLLECTION_TAG, detail_object_collection_block_block );

	TAG_BLOCK(detail_object_type_block, MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION)
	{
		{ _field_string, "name^" },
		{ _field_char_integer, "sequence index:[0,15]" },
		{ _field_byte_flags, "type flags", &detail_object_type_flags_definition },
		{ _field_pad, "VYF", 2 },
		{ _field_real_fraction, "color override factor#fraction of detail object color to use instead of the base map color in the environment:[0,1]" },
		{ _field_pad, "QMOOJ", 8 },
		{ _field_real, "near fade distance:world units" },
		{ _field_real, "far fade distance:world units" },
		{ _field_real, "size:world units per pixel" },
		{ _field_pad, "TDAQ", 4 },
		{ _field_real_rgb_color, "minimum color:[0,1]" },
		{ _field_real_rgb_color, "maximum color:[0,1]" },
		{ _field_argb_color, "ambient color:[0,255]" },
		{ _field_pad, "VCXJHYY", 4 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(detail_object_collection_block, 1, detail_object_collection_struct_definition_struct_definition );

	TAG_BLOCK(global_detail_object_cells_block, MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE)
	{
		{ _field_short_integer, "cell x!*" },
		{ _field_short_integer, "cell y!*" },
		{ _field_short_integer, "cell z!*" },
		{ _field_short_integer, "offset z!*" },
		{ _field_long_integer, "valid layers flags!*" },
		{ _field_long_integer, "start index!*" },
		{ _field_long_integer, "count index!*" },
		{ _field_pad, "OHF", 12 },
		{ _field_terminator }
	};

	TAG_BLOCK(global_detail_object_block, MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE)
	{
		{ _field_char_integer, "position x!*" },
		{ _field_char_integer, "position y!*" },
		{ _field_char_integer, "position z!*" },
		{ _field_char_integer, "data!*" },
		{ _field_short_integer, "color!*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_detail_object_counts_block, MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE*MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE)
	{
		{ _field_short_integer, "count!*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_z_reference_vector_block, MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE)
	{
		{ _field_real, "z reference i!*" },
		{ _field_real, "z reference j!*" },
		{ _field_real, "z reference k!*" },
		{ _field_real, "z reference l!*" },
		{ _field_terminator }
	};

	TAG_STRUCT(detail_object_collection_struct_definition)
	{
		{ _field_enum, "collection type", &detail_object_collection_type_enum_definition },
		{ _field_pad, "YN", 2 },
		{ _field_real, "global z offset:applied to all detail objects of in this collection so they don\'t float above the ground" },
		{ _field_pad, "EBGQ", 44 },
		{ _field_tag_reference, "sprite plate", &global_bitmap_reference },
		{ _field_block, "types", &detail_object_type_block_block },
		{ _field_pad, "ZQUVEZKGL", 48 },
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

