#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(collision_damage, COLLISION_DAMAGE_TAG, collision_damage_block_block )

TAG_BLOCK_FROM_STRUCT(collision_damage_block, 1, collision_damage_struct_definition_struct_definition );

TAG_STRUCT(collision_damage_struct_definition)
{
	FIELD( _field_long_flags, "Flags" ),
	FIELD( _field_explanation, "Applying collision damage" ),
	FIELD( _field_real, "Apply collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage" ),
	FIELD( _field_real, "Friendly apply collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" ),
	FIELD( _field_explanation, "Game collision damage parameters" ),
	FIELD( _field_real, "minimum velocity for game damage#if you are going below this velocity we stop all game damage" ),
	FIELD( _field_struct, "game collision damage", &collision_damage_function_struct_definition ),
	FIELD( _field_real_bounds, "game acceleration#0-Infinity" ),
	FIELD( _field_explanation, "Applying absolute collision damage" ),
	FIELD( _field_real, "Apply absolute collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage" ),
	FIELD( _field_real, "Friendly apply absolute collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" ),
	FIELD( _field_explanation, "Absolute collision damage parameters" ),
	FIELD( _field_real, "minimum velocity for absolute damage#if you are going below this velocity we stop all absolute damage" ),
	FIELD( _field_struct, "absolute collision damage", &collision_damage_function_struct_definition ),
	FIELD( _field_real_bounds, "absolute acceleration#0-Infinity" ),
	FIELD( _field_explanation, "Alternative damage effect" ),
	FIELD( _field_tag_reference, "alternative damage effect" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(collision_damage_function)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

