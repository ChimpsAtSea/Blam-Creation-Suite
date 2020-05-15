#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(breakable_surface, BREAKABLE_SURFACE_TAG)
{
	{ _field_explanation, "VITALITY" },
	{ _field_real_bounds, "direct damage vitality#this is damage from bullets hitting the surface" },
	{ _field_real_bounds, "collision damage impulse thresholds#not really vitality - this is mass * velocity into the surface.  Running player bipeds cap out around 255\nrun \'event_display_category physics:breakable_surfaces verbose\' to get verbose information about damage to breakable surfaces" },
	{ _field_real_bounds, "AoE damage vitality!#not actually in use yet..." },
	{ _field_tag_reference, "effect" },
	{ _field_tag_reference, "sound" },
	{ _field_block, "particle effects", &particle_system_definition_block },
	{ _field_real, "particle density" },
	{ _field_tag_reference, "crack bitmap" },
	{ _field_tag_reference, "hole bitmap" },
	{ _field_terminator },
};

} // namespace blofeld

