#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(decal_flags, 1)
	{
		OPTION("render in transparents pass"),
	};

	TAG_ENUM(decal_system_flags, 3)
	{
		OPTION("random rotation"),
		OPTION("force planar"),
		OPTION("is strip"),
	};

	TAG_GROUP_FROM_BLOCK(decal_system, DECAL_SYSTEM_TAG, decal_system_block_block );

	TAG_BLOCK_FROM_STRUCT(decal_system_block, 1, decal_system_struct_definition_struct_definition );

	TAG_BLOCK(decal_definition_block, c_decal_system_definition::k_max_decal)
	{
		FIELD( _field_string_id, "decal name^" ),
		FIELD( _field_long_flags, "flags", &decal_flags ),
		FIELD( _field_custom, "material" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "actual material\?", &material_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_real_bounds, "radius:world units" ),
		FIELD( _field_real_bounds, "decay time:seconds!" ),
		FIELD( _field_real_bounds, "lifespan:seconds!" ),
		FIELD( _field_real, "clamp angle:degrees#Projections at greater than this angle will be clamped to this angle" ),
		FIELD( _field_real, "cull angle:degrees#Projections at greater than this angle will not be drawn" ),
		FIELD( _field_real, "depth bias" ),
		FIELD( _field_custom, "Decal Strip" ),
		FIELD( _field_real, "strip U-coordinate tile length" ),
		FIELD( _field_real, "strip max profile distance" ),
		FIELD( _field_custom ),
		FIELD( _field_real, "runtime bitmap aspect!" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(decal_system_struct_definition)
{
		FIELD( _field_long_flags, "flags", &decal_system_flags ),
		FIELD( _field_long_integer, "ring buffer size (in triangles)#bigger sizes keep more decals around but use much more memory" ),
		FIELD( _field_long_integer, "ring buffer size single player (in triangles)#above entry is for MP -- SP can be different" ),
		FIELD( _field_real, "material shader fade time#material shader lifetime is modulated from 1 to 0 over this time" ),
		FIELD( _field_real_point_2d, "decal scale override#NOTE - If set to non-zero, this will override manual scaling in Sapien and smash it with these values" ),
		FIELD( _field_explanation, "Decal bucket sharing" ),
		FIELD( _field_short_bounds, "random sprite index bounds#if zero, will use random sprite" ),
		FIELD( _field_block, "decals", &decal_definition_block_block ),
		FIELD( _field_real, "runtime max radius!" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

