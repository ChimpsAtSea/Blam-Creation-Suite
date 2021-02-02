#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(leaf_system, LEAF_SYSTEM_TAG, leaf_system_block_block );

	V5_TAG_BLOCK(leaf_type_block, k_maximum_leaf_type_definitions)
	{
		{ _field_legacy, _field_short_integer, "bitmap sprite index#assumes sequence 0. if no sprites uses full bitmap" },
		{ _field_legacy, _field_pad, "UNAX", 2 },
		{ _field_legacy, _field_real, "frequency" },
		{ _field_legacy, _field_real, "mass" },
		{ _field_legacy, _field_real_bounds, "geometry scale#default of 0 for both means 0.1" },
		{ _field_legacy, _field_real, "flitteriness" },
		{ _field_legacy, _field_real, "flitteriness swing arm length*" },
		{ _field_legacy, _field_real, "flitteriness scale*" },
		{ _field_legacy, _field_real, "flitteriness speed*" },
		{ _field_legacy, _field_real, "flitteriness leaves phase*" },
		{ _field_legacy, _field_real, "tumble scale" },
		{ _field_legacy, _field_real, "rotation scale" },
		{ _field_legacy, _field_real, "starting velocity" },
		{ _field_legacy, _field_real_fraction_bounds, "air friction XY and Z" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(leaf_system_block, 1, leaf_system_struct_definition_struct_definition );

	V5_TAG_STRUCT(leaf_system_struct_definition)
	{
		{ _field_legacy, _field_long_flags, "flags!", &leaf_flags },
		{ _field_legacy, _field_string_id, "marker attach name" },
		{ _field_legacy, _field_tag_reference, "bitmap sprite plate", &global_bitmap_reference },
		{ _field_legacy, _field_real_bounds, "emission rate#seconds" },
		{ _field_legacy, _field_real, "lifetime" },
		{ _field_legacy, _field_real_bounds, "wind min/max#default 0,0" },
		{ _field_legacy, _field_real, "wind scale" },
		{ _field_legacy, _field_real, "time scale" },
		{ _field_legacy, _field_real_bounds, "fade distance!#from maximum movement range (10+). default 0!" },
		{ _field_legacy, _field_real, "emissions sphere radius" },
		{ _field_legacy, _field_real, "movement cylinder radius" },
		{ _field_legacy, _field_real, "fade in time!" },
		{ _field_legacy, _field_real, "fade out time!" },
		{ _field_legacy, _field_block, "leaf types", &leaf_type_block_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(leaf_flags$2)
	{
		"collides structure",
		"collides objects",
		"collides water",
		"affected by explosions"
	};
	STRING_LIST(leaf_flags$2, leaf_flags$2_strings, _countof(leaf_flags$2_strings));

} // namespace blofeld

