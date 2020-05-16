#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(render_water_ripple_struct_definition)
{
	FIELD( _field_explanation, "TYPE FLAGS" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "INITIAL SETTINGS" ),
	FIELD( _field_real, "initial radius{radius}" ),
	FIELD( _field_real, "initial amplitude{amplitude}" ),
	FIELD( _field_real, "spread speed" ),
	FIELD( _field_real, "speed bias" ),
	FIELD( _field_real, "position random range" ),
	FIELD( _field_real, "max visibility distance" ),
	FIELD( _field_explanation, "LIFE SETTINGS" ),
	FIELD( _field_real, "duration max" ),
	FIELD( _field_real, "duration min" ),
	FIELD( _field_real, "rise period ratio" ),
	FIELD( _field_enum, "rise function" ),
	FIELD( _field_enum, "descend function" ),
	FIELD( _field_explanation, "PENDULUM SETTINGS" ),
	FIELD( _field_real, "phase revolution speed" ),
	FIELD( _field_real, "phase repeat along radius" ),
	FIELD( _field_explanation, "SHAPE TRANSITION" ),
	FIELD( _field_real, "pattern start idx" ),
	FIELD( _field_real, "pattern end idx" ),
	FIELD( _field_enum, "pattern transition" ),
	FIELD( _field_pad, "SexyPadding1", 2 ),
	FIELD( _field_explanation, "FOAM" ),
	FIELD( _field_real, "foam out radius" ),
	FIELD( _field_real, "foam fade distance" ),
	FIELD( _field_real, "foam duration" ),
	FIELD( _field_enum, "foam fade function" ),
	FIELD( _field_pad, "SexyPadding2", 2 ),
	FIELD( _field_terminator )
};

TAG_GROUP(render_water_ripple_block, RENDER_WATER_RIPPLE_TAG)
{
	FIELD( _field_explanation, "TYPE FLAGS" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "INITIAL SETTINGS" ),
	FIELD( _field_real, "initial radius{radius}" ),
	FIELD( _field_real, "initial amplitude{amplitude}" ),
	FIELD( _field_real, "spread speed" ),
	FIELD( _field_real, "speed bias" ),
	FIELD( _field_real, "position random range" ),
	FIELD( _field_real, "max visibility distance" ),
	FIELD( _field_explanation, "LIFE SETTINGS" ),
	FIELD( _field_real, "duration max" ),
	FIELD( _field_real, "duration min" ),
	FIELD( _field_real, "rise period ratio" ),
	FIELD( _field_enum, "rise function" ),
	FIELD( _field_enum, "descend function" ),
	FIELD( _field_explanation, "PENDULUM SETTINGS" ),
	FIELD( _field_real, "phase revolution speed" ),
	FIELD( _field_real, "phase repeat along radius" ),
	FIELD( _field_explanation, "SHAPE TRANSITION" ),
	FIELD( _field_real, "pattern start idx" ),
	FIELD( _field_real, "pattern end idx" ),
	FIELD( _field_enum, "pattern transition" ),
	FIELD( _field_pad, "SexyPadding1", 2 ),
	FIELD( _field_explanation, "FOAM" ),
	FIELD( _field_real, "foam out radius" ),
	FIELD( _field_real, "foam fade distance" ),
	FIELD( _field_real, "foam duration" ),
	FIELD( _field_enum, "foam fade function" ),
	FIELD( _field_pad, "SexyPadding2", 2 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

