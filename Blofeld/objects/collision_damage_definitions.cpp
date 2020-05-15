#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(collision_damage, COLLISION_DAMAGE_TAG)
{
	{ _field_long_flags, "Flags" },
	{ _field_explanation, "Applying collision damage" },
	{ _field_real, "Apply collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage" },
	{ _field_real, "Friendly apply collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" },
	{ _field_explanation, "Game collision damage parameters" },
	{ _field_real, "minimum velocity for game damage#if you are going below this velocity we stop all game damage" },
	{ _field_struct, "game collision damage" },
	{ _field_real_bounds, "game acceleration#0-Infinity" },
	{ _field_explanation, "Applying absolute collision damage" },
	{ _field_real, "Apply absolute collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage" },
	{ _field_real, "Friendly apply absolute collision damage scale#0 means 1.  1 is standard scale.  Some things may want to apply more damage, yet go soft on their friends" },
	{ _field_explanation, "Absolute collision damage parameters" },
	{ _field_real, "minimum velocity for absolute damage#if you are going below this velocity we stop all absolute damage" },
	{ _field_struct, "absolute collision damage" },
	{ _field_real_bounds, "absolute acceleration#0-Infinity" },
	{ _field_explanation, "Alternative damage effect" },
	{ _field_tag_reference, "alternative damage effect" },
	{ _field_terminator },
};

} // namespace blofeld

