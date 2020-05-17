#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(effect, EFFECT_TAG)
	{
		FIELD( _field_long_flags, "flags", &effect_flags ),
		FIELD( _field_dword_integer, "fixed random seed#If this is non-zero, the effect will usually be exactly repeatable" ),
		FIELD( _field_real, "restart if within{overlap threshold}:world units" ),
		FIELD( _field_real, "continue if within:world units" ),
		FIELD( _field_real, "death_delay" ),
		FIELD( _field_short_block_index, "loop start event" ),
		FIELD( _field_char_enum, "priority!*", &global_effect_priority_enum ),
		FIELD( _field_pad, "asdfsdf", 1 ),
		FIELD( _field_real, "global size scale" ),
		FIELD( _field_string_id, "scale A override#Handle with care. FYI only works if the effect is attached to an object" ),
		FIELD( _field_string_id, "scale B override#Handle with care. FYI only works if the effect is attached to an object" ),
		FIELD( _field_real, "runtime danger radius!" ),
		FIELD( _field_block, "locations", &effect_locations_block_block ),
		FIELD( _field_block, "events", &effect_event_block_block ),
		FIELD( _field_block, "looping sounds", &effect_looping_sound_block_block ),
		FIELD( _field_real, "always play distance" ),
		FIELD( _field_real, "never play distance" ),
		FIELD( _field_real, "runtime lightprobe_death_delay!" ),
		FIELD( _field_real, "runtime local_space_death_delay!" ),
		FIELD( _field_block, "conical distribution", &effect_conical_distribution_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(effect_locations_block, k_maximum_effect_locations_count)
	{
		FIELD( _field_explanation, "MARKER NAMES" ),
		FIELD( _field_custom ),
		FIELD( _field_old_string_id, "marker name^" ),
		FIELD( _field_word_flags, "flags", &effect_location_flags ),
		FIELD( _field_char_enum, "priority!*", &global_effect_priority_enum ),
		FIELD( _field_pad, "RGEWNQIG", 1 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(effect_part_block, k_maximum_effect_parts_per_event_count)
	{
		FIELD( _field_enum, "create in", &effect_environments ),
		FIELD( _field_enum, "violence mode", &effect_dispositions ),
		FIELD( _field_short_block_index, "location" ),
		FIELD( _field_short_block_index, "secondary location (beams)" ),
		FIELD( _field_word_flags, "flags", &effect_part_flags ),
		FIELD( _field_char_enum, "priority", &global_effect_priority_enum ),
		FIELD( _field_char_enum, "camera mode#Currently, the only supported use is to turn parts off in first-person view.", &effect_camera_modes ),
		FIELD( _field_tag, "runtime base group tag!" ),
		FIELD( _field_char_enum, "game mode", &effectPartGameModeDefinition ),
		FIELD( _field_char_enum, "damage reporting type", &global_damage_reporting_enum_definition ),
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
		FIELD( _field_long_flags, "A scales values:", &effect_part_scaleable_values ),
		FIELD( _field_long_flags, "B scales values:", &effect_part_scaleable_values ),
		FIELD( _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize on spawn" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(effect_accelerations_block, k_maximum_effect_accelerations_per_event_count)
	{
		FIELD( _field_enum, "create in", &effect_environments ),
		FIELD( _field_enum, "violence mode", &effect_dispositions ),
		FIELD( _field_short_block_index, "location" ),
		FIELD( _field_pad, "THY", 2 ),
		FIELD( _field_real, "acceleration" ),
		FIELD( _field_real, "inner cone angle:degrees" ),
		FIELD( _field_real, "outer cone angle:degrees" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(effect_event_block, k_maximum_effect_events_count)
	{
		FIELD( _field_string_id, "event name^" ),
		FIELD( _field_word_flags, "flags", &event_flags ),
		FIELD( _field_char_enum, "priority!*", &global_effect_priority_enum ),
		FIELD( _field_pad, "EVUIQSNDS", 1 ),
		FIELD( _field_real_fraction, "skip fraction#chance that this event will be skipped entirely" ),
		FIELD( _field_custom, "delay bounds:seconds#delay before this event takes place" ),
		FIELD( _field_real_bounds, "delay bounds:seconds#delay before this event takes place" ),
		FIELD( _field_custom, "duration bounds:seconds#duration of this event" ),
		FIELD( _field_real_bounds, "duration bounds:seconds#duration of this event" ),
		FIELD( _field_explanation, "event age duration override" ),
		FIELD( _field_real, "event age duration override:seconds#the amount of time over which the \"event age\" function input goes from 0 to 1" ),
		FIELD( _field_block, "parts", &effect_part_block_block ),
		FIELD( _field_block, "accelerations", &effect_accelerations_block_block ),
		FIELD( _field_block, "particle systems", &particle_system_definition_block_new_block ),
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

	TAG_ENUM(effect_dispositions, 3)
	{
		OPTION("either mode"),
		OPTION("violent mode only"),
		OPTION("nonviolent mode only"),
	};

	TAG_ENUM(effect_environments, 6)
	{
		OPTION("any environment"),
		OPTION("air only"),
		OPTION("water only"),
		OPTION("space only"),
		OPTION("wet only"),
		OPTION("dry only"),
	};

	TAG_ENUM(effect_camera_modes, 4)
	{
		OPTION("independent of camera mode"),
		OPTION("only in first person"),
		OPTION("only in third person"),
		OPTION("both first and third"),
	};

	TAG_ENUM(effect_location_flags, 4)
	{
		OPTION("optional (no error if not found)"),
		OPTION("destructible (no error if goes away)"),
		OPTION("track sub-frame movements#When effect moves multiple times within one frame, update location each time"),
		OPTION("never stagger across markers#Even if this effect is told to stagger across available markers, always fire from all instances"),
	};

	TAG_ENUM(effect_part_scaleable_values, 6)
	{
		OPTION("velocity"),
		OPTION("velocity delta"),
		OPTION("velocity cone angle"),
		OPTION("angular velocity"),
		OPTION("angular velocity delta"),
		OPTION("type-specific scale"),
	};

	TAG_ENUM(effect_part_flags, 11)
	{
		OPTION("face down regardless of location (decals)"),
		OPTION("offset origin away from geometry (lights)"),
		OPTION("never attached to object"),
		OPTION("disabled for debugging"),
		OPTION("draw regardless of distance"),
		OPTION("make every tick"),
		OPTION("inherit parent variant"),
		OPTION("batch AOE damage"),
		OPTION("create even when event loops back to self"),
		OPTION("face up regardless of location (replace_up)"),
		OPTION("sound only plays in killcam#NOTE this is only for sound, and really only for firing effect sounds"),
	};

	TAG_ENUM(effectPartGameModeDefinition, 6)
	{
		OPTION("any"),
		OPTION("campaign only"),
		OPTION("multiplayer only"),
		OPTION("campaign only not cinematics"),
		OPTION("campaign cinematics only"),
		OPTION("campaign solo only"),
	};

	TAG_ENUM(event_flags, 3)
	{
		OPTION("disabled for debugging"),
		OPTION("particles die when effect ends{particles die when event ends}"),
		OPTION("loop event age duration override"),
	};

	TAG_ENUM(effect_flags, 19)
	{
		OPTION("deleted when attachment deactivates"),
		OPTION("run events in parallel"),
		OPTION("do not re-use parts when looping#This option will hurt performance on effects with very short duration."),
		OPTION("age creator\'s weapon"),
		OPTION("use parent position but world orientation"),
		OPTION("can penetrate walls (expensive)"),
		OPTION("cannot be restarted#Will help performance for parallel events of different lengths, if the effect is unlikely to be reused"),
		OPTION("force use own lightprobe#Do not adopt parent object\'s lightprobe, even when it\'s available"),
		OPTION("force looping#Do not use this unless you know you stop the effect at some point"),
		OPTION("ordnance droppod locator#trigger creation of player\'s ordnance droppod"),
		OPTION("render in hologram pass#this effect should be lumped in with Cortana and other holograms when rendered"),
		OPTION("lightprobe only sample airprobes#Only works with \"force use own lightprobe\"; causes effect to never sample lightmap, only placed light probes"),
		OPTION("play effect even outside bsps (expensive)"),
		OPTION("draw .parts when stopped{draw lens flares when stopped}"),
		OPTION("kill particles when stopped#particularly useful for particles that live forever"),
		OPTION("play even on hidden objects"),
		OPTION("disable first person parts in blind skull#blind skull hides the first person weapon"),
		OPTION("hides associated object on effect deletion#when the effect is deleted, it hides the object it is associated with (for hologram in mp)"),
		OPTION("bypass mp throttle#effect can not ignore generated crates or be non-networked"),
	};

} // namespace blofeld

