#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(effect, EFFECT_TAG)
	{
		{ _field_long_flags, "flags", &effect_flags },
		{ _field_dword_integer, "fixed random seed#If this is non-zero, the effect will usually be exactly repeatable" },
		{ _field_real, "restart if within{overlap threshold}:world units" },
		{ _field_real, "continue if within:world units" },
		{ _field_real, "death_delay" },
		{ _field_short_block_index, "loop start event" },
		{ _field_char_enum, "priority!*", &global_effect_priority_enum },
		{ _field_pad, "asdfsdf", 1 },
		{ _field_real, "global size scale" },
		{ _field_string_id, "scale A override#Handle with care. FYI only works if the effect is attached to an object" },
		{ _field_string_id, "scale B override#Handle with care. FYI only works if the effect is attached to an object" },
		{ _field_real, "runtime danger radius!" },
		{ _field_block, "locations", &effect_locations_block_block },
		{ _field_block, "events", &effect_event_block_block },
		{ _field_block, "looping sounds", &effect_looping_sound_block_block },
		{ _field_real, "always play distance" },
		{ _field_real, "never play distance" },
		{ _field_real, "runtime lightprobe_death_delay!" },
		{ _field_real, "runtime local_space_death_delay!" },
		{ _field_block, "conical distribution", &effect_conical_distribution_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_locations_block, k_maximum_effect_locations_count)
	{
		{ _field_explanation, "MARKER NAMES" },
		{ _field_custom },
		{ _field_old_string_id, "marker name^" },
		{ _field_word_flags, "flags", &effect_location_flags },
		{ _field_char_enum, "priority!*", &global_effect_priority_enum },
		{ _field_pad, "RGEWNQIG", 1 },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_part_block, k_maximum_effect_parts_per_event_count)
	{
		{ _field_enum, "create in", &effect_environments },
		{ _field_enum, "violence mode", &effect_dispositions },
		{ _field_short_block_index, "location" },
		{ _field_short_block_index, "secondary location (beams)" },
		{ _field_word_flags, "flags", &effect_part_flags },
		{ _field_char_enum, "priority", &global_effect_priority_enum },
		{ _field_char_enum, "camera mode#Currently, the only supported use is to turn parts off in first-person view.", &effect_camera_modes },
		{ _field_tag, "runtime base group tag!" },
		{ _field_char_enum, "game mode", &effectPartGameModeDefinition },
		{ _field_char_enum, "damage reporting type", &global_damage_reporting_enum_definition },
		{ _field_pad, "JCIOEHR", 2 },
		{ _field_tag_reference, "type^", &effect_part_block_type_reference },
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
		{ _field_long_flags, "A scales values:", &effect_part_scaleable_values },
		{ _field_long_flags, "B scales values:", &effect_part_scaleable_values },
		{ _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize on spawn", &global_particleize_parameters_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_accelerations_block, k_maximum_effect_accelerations_per_event_count)
	{
		{ _field_enum, "create in", &effect_environments },
		{ _field_enum, "violence mode", &effect_dispositions },
		{ _field_short_block_index, "location" },
		{ _field_pad, "THY", 2 },
		{ _field_real, "acceleration" },
		{ _field_real, "inner cone angle:degrees" },
		{ _field_real, "outer cone angle:degrees" },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_event_block, k_maximum_effect_events_count)
	{
		{ _field_string_id, "event name^" },
		{ _field_word_flags, "flags", &event_flags },
		{ _field_char_enum, "priority!*", &global_effect_priority_enum },
		{ _field_pad, "EVUIQSNDS", 1 },
		{ _field_real_fraction, "skip fraction#chance that this event will be skipped entirely" },
		{ _field_custom, "delay bounds:seconds#delay before this event takes place" },
		{ _field_real_bounds, "delay bounds:seconds#delay before this event takes place" },
		{ _field_custom, "duration bounds:seconds#duration of this event" },
		{ _field_real_bounds, "duration bounds:seconds#duration of this event" },
		{ _field_explanation, "event age duration override" },
		{ _field_real, "event age duration override:seconds#the amount of time over which the \"event age\" function input goes from 0 to 1" },
		{ _field_block, "parts", &effect_part_block_block },
		{ _field_block, "accelerations", &effect_accelerations_block_block },
		{ _field_block, "particle systems", &particle_system_definition_block_new_block },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_looping_sound_block, k_maximum_effect_looping_sounds_count)
	{
		{ _field_tag_reference, "looping sound^", &global_looping_sound_reference },
		{ _field_short_block_index, "location" },
		{ _field_short_block_index, "bind scale to event" },
		{ _field_terminator }
	};

	TAG_BLOCK(effect_conical_distribution_block, 1)
	{
		{ _field_explanation, "conical_projection: AKA shotgun" },
		{ _field_short_integer, "yaw count" },
		{ _field_short_integer, "pitch count" },
		{ _field_real, "distribution exponent#exp==.5 even distribution, exp>.5== tighter" },
		{ _field_angle, "spread#degrees" },
		{ _field_terminator }
	};

	STRINGS(effect_dispositions)
	{
		"either mode",
		"violent mode only",
		"nonviolent mode only"
	};
	STRING_LIST(effect_dispositions, effect_dispositions_strings, _countof(effect_dispositions_strings));

	STRINGS(effect_environments)
	{
		"any environment",
		"air only",
		"water only",
		"space only",
		"wet only",
		"dry only"
	};
	STRING_LIST(effect_environments, effect_environments_strings, _countof(effect_environments_strings));

	STRINGS(effect_camera_modes)
	{
		"independent of camera mode",
		"only in first person",
		"only in third person",
		"both first and third"
	};
	STRING_LIST(effect_camera_modes, effect_camera_modes_strings, _countof(effect_camera_modes_strings));

	STRINGS(effect_location_flags)
	{
		"optional (no error if not found)",
		"destructible (no error if goes away)",
		"track sub-frame movements#When effect moves multiple times within one frame, update location each time",
		"never stagger across markers#Even if this effect is told to stagger across available markers, always fire from all instances"
	};
	STRING_LIST(effect_location_flags, effect_location_flags_strings, _countof(effect_location_flags_strings));

	STRINGS(effect_part_scaleable_values)
	{
		"velocity",
		"velocity delta",
		"velocity cone angle",
		"angular velocity",
		"angular velocity delta",
		"type-specific scale"
	};
	STRING_LIST(effect_part_scaleable_values, effect_part_scaleable_values_strings, _countof(effect_part_scaleable_values_strings));

	STRINGS(effect_part_flags)
	{
		"face down regardless of location (decals)",
		"offset origin away from geometry (lights)",
		"never attached to object",
		"disabled for debugging",
		"draw regardless of distance",
		"make every tick",
		"inherit parent variant",
		"batch AOE damage",
		"create even when event loops back to self",
		"face up regardless of location (replace_up)",
		"sound only plays in killcam#NOTE this is only for sound, and really only for firing effect sounds"
	};
	STRING_LIST(effect_part_flags, effect_part_flags_strings, _countof(effect_part_flags_strings));

	STRINGS(effectPartGameModeDefinition)
	{
		"any",
		"campaign only",
		"multiplayer only",
		"campaign only not cinematics",
		"campaign cinematics only",
		"campaign solo only"
	};
	STRING_LIST(effectPartGameModeDefinition, effectPartGameModeDefinition_strings, _countof(effectPartGameModeDefinition_strings));

	STRINGS(event_flags)
	{
		"disabled for debugging",
		"particles die when effect ends{particles die when event ends}",
		"loop event age duration override"
	};
	STRING_LIST(event_flags, event_flags_strings, _countof(event_flags_strings));

	STRINGS(effect_flags)
	{
		"deleted when attachment deactivates",
		"run events in parallel",
		"do not re-use parts when looping#This option will hurt performance on effects with very short duration.",
		"age creator\'s weapon",
		"use parent position but world orientation",
		"can penetrate walls (expensive)",
		"cannot be restarted#Will help performance for parallel events of different lengths, if the effect is unlikely to be reused",
		"force use own lightprobe#Do not adopt parent object\'s lightprobe, even when it\'s available",
		"force looping#Do not use this unless you know you stop the effect at some point",
		"ordnance droppod locator#trigger creation of player\'s ordnance droppod",
		"render in hologram pass#this effect should be lumped in with Cortana and other holograms when rendered",
		"lightprobe only sample airprobes#Only works with \"force use own lightprobe\"; causes effect to never sample lightmap, only placed light probes",
		"play effect even outside bsps (expensive)",
		"draw .parts when stopped{draw lens flares when stopped}",
		"kill particles when stopped#particularly useful for particles that live forever",
		"play even on hidden objects",
		"disable first person parts in blind skull#blind skull hides the first person weapon",
		"hides associated object on effect deletion#when the effect is deleted, it hides the object it is associated with (for hologram in mp)",
		"bypass mp throttle#effect can not ignore generated crates or be non-networked"
	};
	STRING_LIST(effect_flags, effect_flags_strings, _countof(effect_flags_strings));

	TAG_REFERENCE(global_effect_reference, EFFECT_TAG);

	TAG_REFERENCE(globalEffectReferenceNonResourceDependency, EFFECT_TAG, _tag_reference_flag_not_a_resource_dependency);

} // namespace blofeld

