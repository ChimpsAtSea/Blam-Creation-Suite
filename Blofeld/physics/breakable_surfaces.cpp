#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(breakable_surface, BREAKABLE_SURFACE_TAG)
{
	FIELD( _field_explanation, "VITALITY" ),
	FIELD( _field_real_bounds, "direct damage vitality#this is damage from bullets hitting the surface" ),
	FIELD( _field_real_bounds, "collision damage impulse thresholds#not really vitality - this is mass * velocity into the surface.  Running player bipeds cap out around 255\nrun \'event_display_category physics:breakable_surfaces verbose\' to get verbose information about damage to breakable surfaces" ),
	FIELD( _field_real_bounds, "AoE damage vitality!#not actually in use yet..." ),
	FIELD( _field_tag_reference, "effect" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_block, "particle effects", &particle_system_definition_block ),
	FIELD( _field_real, "particle density" ),
	FIELD( _field_tag_reference, "crack bitmap" ),
	FIELD( _field_tag_reference, "hole bitmap" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

