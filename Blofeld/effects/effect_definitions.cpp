#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(effect_locations, k_maximum_effect_locations_count)
{
	{ _field_explanation, "MARKER NAMES" },
	{ _field_custom },
	{ _field_old_string_id, "marker name^" },
	{ _field_word_flags, "flags" },
	{ _field_char_enum, "priority!*" },
	{ _field_pad, "RGEWNQIG", 1 },
	{ _field_terminator },
};

TAG_BLOCK(effect_event, k_maximum_effect_events_count)
{
	{ _field_string_id, "event name^" },
	{ _field_word_flags, "flags" },
	{ _field_char_enum, "priority!*" },
	{ _field_pad, "EVUIQSNDS", 1 },
	{ _field_real_fraction, "skip fraction#chance that this event will be skipped entirely" },
	{ _field_custom, "delay bounds:seconds#delay before this event takes place" },
	{ _field_real_bounds, "delay bounds:seconds#delay before this event takes place" },
	{ _field_custom, "duration bounds:seconds#duration of this event" },
	{ _field_real_bounds, "duration bounds:seconds#duration of this event" },
	{ _field_explanation, "event age duration override" },
	{ _field_real, "event age duration override:seconds#the amount of time over which the \"event age\" function input goes from 0 to 1" },
	{ _field_block, "parts", &effect_part_block },
	{ _field_block, "accelerations", &effect_accelerations_block },
	{ _field_block, "particle systems", &particle_system_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(effect_part, k_maximum_effect_parts_per_event_count)
{
	{ _field_enum, "create in" },
	{ _field_enum, "violence mode" },
	{ _field_short_block_index, "location" },
	{ _field_short_block_index, "secondary location (beams)" },
	{ _field_word_flags, "flags" },
	{ _field_char_enum, "priority" },
	{ _field_char_enum, "camera mode#Currently, the only supported use is to turn parts off in first-person view." },
	{ _field_tag, "runtime base group tag!" },
	{ _field_char_enum, "game mode" },
	{ _field_char_enum, "damage reporting type" },
	{ _field_pad, "JCIOEHR", 2 },
	{ _field_tag_reference, "type^" },
	{ _field_custom, "velocity bounds:world units per second#initial velocity along the location\'s forward, for decals the distance at which decal is created (defaults to 0.5)" },
	{ _field_real_bounds, "velocity bounds:world units per second#initial velocity along the location\'s forward, for decals the distance at which decal is created (defaults to 0.5)" },
	{ _field_real_euler_angles_2d, "velocity orientation (yaw, pitch)#NOT USED!" },
	{ _field_angle, "velocity cone angle:degrees#initial velocity will be inside the cone defined by this angle." },
	{ _field_angle_bounds, "angular velocity bounds:degrees per second" },
	{ _field_custom, "radius modifier bounds" },
	{ _field_real_bounds, "radius modifier bounds" },
	{ _field_real_point_3d, "relative offset" },
	{ _field_real_euler_angles_2d, "relative orientation (yaw, pitch)" },
	{ _field_explanation, "SCALE MODIFIERS" },
	{ _field_long_flags, "A scales values:" },
	{ _field_long_flags, "B scales values:" },
	{ _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize on spawn" },
	{ _field_terminator },
};

TAG_BLOCK(effect_accelerations, k_maximum_effect_accelerations_per_event_count)
{
	{ _field_enum, "create in" },
	{ _field_enum, "violence mode" },
	{ _field_short_block_index, "location" },
	{ _field_pad, "THY", 2 },
	{ _field_real, "acceleration" },
	{ _field_real, "inner cone angle:degrees" },
	{ _field_real, "outer cone angle:degrees" },
	{ _field_terminator },
};

TAG_BLOCK(effect_looping_sound, k_maximum_effect_looping_sounds_count)
{
	{ _field_tag_reference, "looping sound^" },
	{ _field_short_block_index, "location" },
	{ _field_short_block_index, "bind scale to event" },
	{ _field_terminator },
};

TAG_BLOCK(effect_conical_distribution, 1)
{
	{ _field_explanation, "conical_projection: AKA shotgun" },
	{ _field_short_integer, "yaw count" },
	{ _field_short_integer, "pitch count" },
	{ _field_real, "distribution exponent#exp==.5 even distribution, exp>.5== tighter" },
	{ _field_angle, "spread#degrees" },
	{ _field_terminator },
};

TAG_GROUP(effect, EFFECT_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_dword_integer, "fixed random seed#If this is non-zero, the effect will usually be exactly repeatable" },
	{ _field_real, "restart if within{overlap threshold}:world units" },
	{ _field_real, "continue if within:world units" },
	{ _field_real, "death_delay" },
	{ _field_short_block_index, "loop start event" },
	{ _field_char_enum, "priority!*" },
	{ _field_pad, "asdfsdf", 1 },
	{ _field_real, "global size scale" },
	{ _field_string_id, "scale A override#Handle with care. FYI only works if the effect is attached to an object" },
	{ _field_string_id, "scale B override#Handle with care. FYI only works if the effect is attached to an object" },
	{ _field_real, "runtime danger radius!" },
	{ _field_block, "locations", &effect_locations_block },
	{ _field_block, "events", &effect_event_block },
	{ _field_block, "looping sounds", &effect_looping_sound_block },
	{ _field_real, "always play distance" },
	{ _field_real, "never play distance" },
	{ _field_real, "runtime lightprobe_death_delay!" },
	{ _field_real, "runtime local_space_death_delay!" },
	{ _field_block, "conical distribution", &effect_conical_distribution_block },
	{ _field_terminator },
};

} // namespace blofeld

