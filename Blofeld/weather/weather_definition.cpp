#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(rain_definition, RAIN_DEFINITION_TAG, rain_definition_block_block )

TAG_BLOCK_FROM_STRUCT(rain_definition_block, 1, rain_definition_struct_definition_struct_definition );

TAG_STRUCT(rain_definition_struct_definition)
{
	FIELD( _field_long_integer, "version!#INTERNAL TAG USE ONLY DO NOT CHANGE" ),
	FIELD( _field_real, "rain amount:[0,1]#fade control for all rain effects" ),
	FIELD( _field_explanation, "Rain Effects" ),
	FIELD( _field_tag_reference, "effect" ),
	FIELD( _field_tag_reference, "screen effect" ),
	FIELD( _field_tag_reference, "camera fx" ),
	FIELD( _field_custom, "particles" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_tag_reference, "drop texture" ),
	FIELD( _field_tag_reference, "splash texture" ),
	FIELD( _field_real, "density:particles per square world unit" ),
	FIELD( _field_real_vector_3d, "direction#k -1 is down" ),
	FIELD( _field_real, "fall speed:world units per second" ),
	FIELD( _field_real, "size:world units#size of the rain particles" ),
	FIELD( _field_real, "max vertical camera-relative motion:world units per second#the max velocity in which we allow world-relative vertical rain motion.  over this velocity we clamp to camera-relative vertical rain motion" ),
	FIELD( _field_real, "max aspect ratio#height to width ratio" ),
	FIELD( _field_real, "min aspect for intensity#intensity will scale inversely with aspect ratio, this clamps the aspect ratio before scaling" ),
	FIELD( _field_real_rgb_color, "tint color#tints the rain drops" ),
	FIELD( _field_real, "intensity#brightness of the rain drops" ),
	FIELD( _field_real, "alpha scale#transparency of the rain drops" ),
	FIELD( _field_real, "drop near fade distance:world units#distance at which the drops fade out" ),
	FIELD( _field_real, "collision range:world units#depth range over which the particle will search for collisions with the depth buffer" ),
	FIELD( _field_real, "splash size:world units#length of a side of the splash particle card" ),
	FIELD( _field_real, "splash height:world units#height off the ground of the center of the splash particle" ),
	FIELD( _field_real, "splash lifetime:seconds#how long the splash lasts" ),
	FIELD( _field_real, "near fade distance:world units#distance at which the splash fades out" ),
	FIELD( _field_real_rgb_color, "splash tint#tints the splashes" ),
	FIELD( _field_real, "splash intensity#brightness of the splashes" ),
	FIELD( _field_real, "splash alpha#transparency of the splashes" ),
	FIELD( _field_real, "ripple initial size#size of the ripple at impact" ),
	FIELD( _field_real, "ripple max size#maximum size of the ripple" ),
	FIELD( _field_real, "ripple lifetime:seconds#how long the ripples last" ),
	FIELD( _field_real, "ripple intensity#intensifies ripples" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "rain sheet" ),
	FIELD( _field_tag_reference, "rain sheet texture" ),
	FIELD( _field_real, "rain sheet speed" ),
	FIELD( _field_real, "rain sheet intervals" ),
	FIELD( _field_real, "rain sheet minimum distance" ),
	FIELD( _field_real, "rain sheet intensity" ),
	FIELD( _field_real, "rain texture tile scale" ),
	FIELD( _field_real, "rain sheet parallax speed" ),
	FIELD( _field_real, "rain sheet depth fade{rain sheet fade factor}" ),
	FIELD( _field_real, "transparent sort distance" ),
	FIELD( _field_real, "transparent sort layer" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "light volume" ),
	FIELD( _field_tag_reference, "light volume texture" ),
	FIELD( _field_real, "light volume intensity" ),
	FIELD( _field_real, "light volume texture scale" ),
	FIELD( _field_real, "rain drop/particle intensity" ),
	FIELD( _field_real, "farthest rain particle distance" ),
	FIELD( _field_real, "closest rain sheet distance" ),
	FIELD( _field_real, "rain drop length compensation#make it longer when it is far" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "rain transition" ),
	FIELD( _field_real, "wetness fade in time:seconds" ),
	FIELD( _field_real, "wetness fade out time:seconds" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "material dim" ),
	FIELD( _field_real, "dim of point light" ),
	FIELD( _field_real, "dim of imposters" ),
	FIELD( _field_real, "dim of decorators" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

