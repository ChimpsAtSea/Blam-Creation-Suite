#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(detail_object_type, MAXIMUM_DETAIL_OBJECT_TYPES_PER_COLLECTION)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_char_integer, "sequence index:[0,15]" ),
	FIELD( _field_byte_flags, "type flags" ),
	FIELD( _field_pad, "VYF", 2 ),
	FIELD( _field_real_fraction, "color override factor#fraction of detail object color to use instead of the base map color in the environment:[0,1]" ),
	FIELD( _field_pad, "QMOOJ", 8 ),
	FIELD( _field_real, "near fade distance:world units" ),
	FIELD( _field_real, "far fade distance:world units" ),
	FIELD( _field_real, "size:world units per pixel" ),
	FIELD( _field_pad, "TDAQ", 4 ),
	FIELD( _field_real_rgb_color, "minimum color:[0,1]" ),
	FIELD( _field_real_rgb_color, "maximum color:[0,1]" ),
	FIELD( _field_argb_color, "ambient color:[0,255]" ),
	FIELD( _field_pad, "VCXJHYY", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_detail_object_cells, MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE)
{
	FIELD( _field_short_integer, "cell x!*" ),
	FIELD( _field_short_integer, "cell y!*" ),
	FIELD( _field_short_integer, "cell z!*" ),
	FIELD( _field_short_integer, "offset z!*" ),
	FIELD( _field_long_integer, "valid layers flags!*" ),
	FIELD( _field_long_integer, "start index!*" ),
	FIELD( _field_long_integer, "count index!*" ),
	FIELD( _field_pad, "OHF", 12 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_detail_object, MAXIMUM_DETAIL_OBJECTS_PER_STRUCTURE)
{
	FIELD( _field_char_integer, "position x!*" ),
	FIELD( _field_char_integer, "position y!*" ),
	FIELD( _field_char_integer, "position z!*" ),
	FIELD( _field_char_integer, "data!*" ),
	FIELD( _field_short_integer, "color!*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_detail_object_counts, MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE*MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE)
{
	FIELD( _field_short_integer, "count!*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_z_reference_vector, MAXIMUM_DETAIL_OBJECT_CELLS_PER_STRUCTURE)
{
	FIELD( _field_real, "z reference i!*" ),
	FIELD( _field_real, "z reference j!*" ),
	FIELD( _field_real, "z reference k!*" ),
	FIELD( _field_real, "z reference l!*" ),
	FIELD( _field_terminator )
};

TAG_GROUP(detail_object_collection, DETAIL_OBJECT_COLLECTION_TAG)
{
	FIELD( _field_enum, "collection type" ),
	FIELD( _field_pad, "YN", 2 ),
	FIELD( _field_real, "global z offset:applied to all detail objects of in this collection so they don\'t float above the ground" ),
	FIELD( _field_pad, "EBGQ", 44 ),
	FIELD( _field_tag_reference, "sprite plate" ),
	FIELD( _field_block, "types", &detail_object_type_block ),
	FIELD( _field_pad, "ZQUVEZKGL", 48 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

