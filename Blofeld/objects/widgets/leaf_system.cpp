#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(leaf_system, LEAF_SYSTEM_TAG, leaf_system_block_block );

	TAG_BLOCK(leaf_type_block, k_maximum_leaf_type_definitions)
	{
		FIELD( _field_short_integer, "bitmap sprite index#assumes sequence 0. if no sprites uses full bitmap" ),
		FIELD( _field_pad, "UNAX", 2 ),
		FIELD( _field_real, "frequency" ),
		FIELD( _field_real, "mass" ),
		FIELD( _field_real_bounds, "geometry scale#default of 0 for both means 0.1" ),
		FIELD( _field_real, "flitteriness" ),
		FIELD( _field_real, "flitteriness swing arm length*" ),
		FIELD( _field_real, "flitteriness scale*" ),
		FIELD( _field_real, "flitteriness speed*" ),
		FIELD( _field_real, "flitteriness leaves phase*" ),
		FIELD( _field_real, "tumble scale" ),
		FIELD( _field_real, "rotation scale" ),
		FIELD( _field_real, "starting velocity" ),
		FIELD( _field_real_fraction_bounds, "air friction XY and Z" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(leaf_system_block, 1, leaf_system_struct_definition_struct_definition );

	TAG_STRUCT(leaf_system_struct_definition)
	{
		FIELD( _field_long_flags, "flags!", &leaf_flags ),
		FIELD( _field_string_id, "marker attach name" ),
		FIELD( _field_tag_reference, "bitmap sprite plate" ),
		FIELD( _field_real_bounds, "emission rate#seconds" ),
		FIELD( _field_real, "lifetime" ),
		FIELD( _field_real_bounds, "wind min/max#default 0,0" ),
		FIELD( _field_real, "wind scale" ),
		FIELD( _field_real, "time scale" ),
		FIELD( _field_real_bounds, "fade distance!#from maximum movement range (10+). default 0!" ),
		FIELD( _field_real, "emissions sphere radius" ),
		FIELD( _field_real, "movement cylinder radius" ),
		FIELD( _field_real, "fade in time!" ),
		FIELD( _field_real, "fade out time!" ),
		FIELD( _field_block, "leaf types", &leaf_type_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(leaf_flags$2, 4)
	{
		OPTION("collides structure"),
		OPTION("collides objects"),
		OPTION("collides water"),
		OPTION("affected by explosions"),
	};

} // namespace blofeld

