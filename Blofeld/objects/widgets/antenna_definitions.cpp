#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(antenna, ANTENNA_TAG, antenna_block_block );

	TAG_BLOCK(antenna_vertex_block, MAXIMUM_NUMBER_OF_ANTENNA_VERTICES)
	{
		FIELD( _field_real_euler_angles_2d, "angles#direction toward next vertex!" ),
		FIELD( _field_real, "length:world units#distance between this vertex and the next" ),
		FIELD( _field_short_integer, "sequence index#bitmap group sequence index for this vertex\'s texture" ),
		FIELD( _field_pad, "NTCTQQF", 2 ),
		FIELD( _field_real_argb_color, "color#color at this vertex" ),
		FIELD( _field_real_argb_color, "LOD color#color at this vertex for the low-LOD line primitives!" ),
		FIELD( _field_real, "hermite t!" ),
		FIELD( _field_real_vector_3d, "vector to next!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(antenna_block, 1, antenna_struct_definition_struct_definition );

	TAG_STRUCT(antenna_struct_definition)
	{
		FIELD( _field_old_string_id, "attachment marker name#the marker name where the antenna should be attached" ),
		FIELD( _field_tag_reference, "bitmaps" ),
		FIELD( _field_tag_reference, "physics" ),
		FIELD( _field_real_fraction, "spring strength coefficient#strength of the spring (larger values make the spring stronger)" ),
		FIELD( _field_real, "texel to world width scale" ),
		FIELD( _field_real, "falloff pixels!" ),
		FIELD( _field_real, "cutoff pixels!" ),
		FIELD( _field_real, "point of bend#[0,1]" ),
		FIELD( _field_real, "starting bend#[0,1]" ),
		FIELD( _field_real, "ending bend#[0,1]" ),
		FIELD( _field_real, "runtime total length!" ),
		FIELD( _field_block, "vertices", &antenna_vertex_block_block ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

