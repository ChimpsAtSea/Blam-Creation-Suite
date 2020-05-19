#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(render_water_ripple, RENDER_WATER_RIPPLE_TAG, render_water_ripple_block_block );

	TAG_BLOCK_FROM_STRUCT(render_water_ripple_block, 1, render_water_ripple_struct_definition_struct_definition );

	TAG_STRUCT(render_water_ripple_struct_definition)
	{
		{ _field_explanation, "TYPE FLAGS" },
		{ _field_long_flags, "flags", &ripple_behavior_flags },
		{ _field_explanation, "INITIAL SETTINGS" },
		{ _field_real, "initial radius{radius}" },
		{ _field_real, "initial amplitude{amplitude}" },
		{ _field_real, "spread speed" },
		{ _field_real, "speed bias" },
		{ _field_real, "position random range" },
		{ _field_real, "max visibility distance" },
		{ _field_explanation, "LIFE SETTINGS" },
		{ _field_real, "duration max" },
		{ _field_real, "duration min" },
		{ _field_real, "rise period ratio" },
		{ _field_enum, "rise function", &transition_function_enum },
		{ _field_enum, "descend function", &transition_function_enum },
		{ _field_explanation, "PENDULUM SETTINGS" },
		{ _field_real, "phase revolution speed" },
		{ _field_real, "phase repeat along radius" },
		{ _field_explanation, "SHAPE TRANSITION" },
		{ _field_real, "pattern start idx" },
		{ _field_real, "pattern end idx" },
		{ _field_enum, "pattern transition", &transition_function_enum },
		{ _field_pad, "SexyPadding1", 2 },
		{ _field_explanation, "FOAM" },
		{ _field_real, "foam out radius" },
		{ _field_real, "foam fade distance" },
		{ _field_real, "foam duration" },
		{ _field_enum, "foam fade function", &transition_function_enum },
		{ _field_pad, "SexyPadding2", 2 },
		{ _field_terminator }
	};

	STRINGS(ripple_behavior_flags)
	{
		"ripple drifted by flow",
		"amplitude changed by pendulum function",
		"display flash foam",
		"foam size defined in game unit"
	};
	STRING_LIST(ripple_behavior_flags, ripple_behavior_flags_strings, _countof(ripple_behavior_flags_strings));

	STRINGS(transition_function_enum)
	{
		"linear",
		"early",
		"very early",
		"late",
		"very late",
		"cosine",
		"one",
		"zero"
	};
	STRING_LIST(transition_function_enum, transition_function_enum_strings, _countof(transition_function_enum_strings));

} // namespace blofeld

