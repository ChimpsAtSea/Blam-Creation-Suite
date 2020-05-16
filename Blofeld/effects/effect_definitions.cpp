#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(effect_locations_block, k_maximum_effect_locations_count)
{
	FIELD( _field_explanation, "MARKER NAMES" ),
	FIELD( _field_custom ),
	FIELD( _field_old_string_id, "marker name^" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_char_enum, "priority!*" ),
	FIELD( _field_pad, "RGEWNQIG", 1 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(effect_event_block, k_maximum_effect_events_count)
{
	FIELD( _field_string_id, "event name^" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_char_enum, "priority!*" ),
	FIELD( _field_pad, "EVUIQSNDS", 1 ),
	FIELD( _field_real_fraction, "skip fraction#chance that this event will be skipped entirely" ),
	FIELD( _field_custom, "delay bounds:seconds#delay before this event takes place" ),
	FIELD( _field_real_bounds, "delay bounds:seconds#delay before this event takes place" ),
	FIELD( _field_custom, "duration bounds:seconds#duration of this event" ),
	FIELD( _field_real_bounds, "duration bounds:seconds#duration of this event" ),
	FIELD( _field_explanation, "event age duration override" ),
	FIELD( _field_real, "event age duration override:seconds#the amount of time over which the \"event age\" function input goes from 0 to 1" ),
	FIELD( _field_block, "parts", &effect_part_block ),
	FIELD( _field_block, "accelerations", &effect_accelerations_block ),
	FIELD( _field_block, "particle systems", &particle_system_definition_block_new ),
	FIELD( _field_terminator )
};

TAG_BLOCK(effect_part_block, k_maximum_effect_parts_per_event_count)
{
	FIELD( _field_enum, "create in" ),
	FIELD( _field_enum, "violence mode" ),
	FIELD( _field_short_block_index, "location" ),
	FIELD( _field_short_block_index, "secondary location (beams)" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_char_enum, "priority" ),
	FIELD( _field_char_enum, "camera mode#Currently, the only supported use is to turn parts off in first-person view." ),
	FIELD( _field_tag, "runtime base group tag!" ),
	FIELD( _field_char_enum, "game mode" ),
	FIELD( _field_char_enum, "damage reporting type" ),
	FIELD( _field_pad, "JCIOEHR", 2 ),
	FIELD( _field_tag_reference, "type^" ),
	FIELD( _field_custom, "velocity bounds:world units per second#initial velocity along the location\'s forward, for decals the distance at which decal is created (defaults to 0.5)" ),
	FIELD( _field_real_bounds, "velocity bounds:world units per second#initial velocity along the location\'s forward, for decals the distance at which decal is created (defaults to 0.5)" ),
	FIELD( _field_real_euler_angles_2d, "velocity orientation (yaw, pitch)#NOT USED!" ),
	FIELD( _field_angle, "velocity cone angle:degrees#initial velocity will be inside the cone defined by this angle." ),
	FIELD( _field_angle_bounds, "angular velocity bounds:degrees per second" ),
	FIELD( _field_custom, "radius modifier bounds" ),
	FIELD( _field_real_bounds, "radius modifier bounds" ),
	FIELD( _field_real_point_3d, "relative offset" ),
	FIELD( _field_real_euler_angles_2d, "relative orientation (yaw, pitch)" ),
	FIELD( _field_explanation, "SCALE MODIFIERS" ),
	FIELD( _field_long_flags, "A scales values:" ),
	FIELD( _field_long_flags, "B scales values:" ),
	FIELD( _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize on spawn" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(effect_accelerations_block, k_maximum_effect_accelerations_per_event_count)
{
	FIELD( _field_enum, "create in" ),
	FIELD( _field_enum, "violence mode" ),
	FIELD( _field_short_block_index, "location" ),
	FIELD( _field_pad, "THY", 2 ),
	FIELD( _field_real, "acceleration" ),
	FIELD( _field_real, "inner cone angle:degrees" ),
	FIELD( _field_real, "outer cone angle:degrees" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(effect_looping_sound_block, k_maximum_effect_looping_sounds_count)
{
	FIELD( _field_tag_reference, "looping sound^" ),
	FIELD( _field_short_block_index, "location" ),
	FIELD( _field_short_block_index, "bind scale to event" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(effect_conical_distribution_block, 1)
{
	FIELD( _field_explanation, "conical_projection: AKA shotgun" ),
	FIELD( _field_short_integer, "yaw count" ),
	FIELD( _field_short_integer, "pitch count" ),
	FIELD( _field_real, "distribution exponent#exp==.5 even distribution, exp>.5== tighter" ),
	FIELD( _field_angle, "spread#degrees" ),
	FIELD( _field_terminator )
};

TAG_GROUP(effect_block, EFFECT_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_dword_integer, "fixed random seed#If this is non-zero, the effect will usually be exactly repeatable" ),
	FIELD( _field_real, "restart if within{overlap threshold}:world units" ),
	FIELD( _field_real, "continue if within:world units" ),
	FIELD( _field_real, "death_delay" ),
	FIELD( _field_short_block_index, "loop start event" ),
	FIELD( _field_char_enum, "priority!*" ),
	FIELD( _field_pad, "asdfsdf", 1 ),
	FIELD( _field_real, "global size scale" ),
	FIELD( _field_string_id, "scale A override#Handle with care. FYI only works if the effect is attached to an object" ),
	FIELD( _field_string_id, "scale B override#Handle with care. FYI only works if the effect is attached to an object" ),
	FIELD( _field_real, "runtime danger radius!" ),
	FIELD( _field_block, "locations", &effect_locations_block ),
	FIELD( _field_block, "events", &effect_event_block ),
	FIELD( _field_block, "looping sounds", &effect_looping_sound_block ),
	FIELD( _field_real, "always play distance" ),
	FIELD( _field_real, "never play distance" ),
	FIELD( _field_real, "runtime lightprobe_death_delay!" ),
	FIELD( _field_real, "runtime local_space_death_delay!" ),
	FIELD( _field_block, "conical distribution", &effect_conical_distribution_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

