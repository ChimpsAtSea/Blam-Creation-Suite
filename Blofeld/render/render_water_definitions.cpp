#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(render_water_ripple, RENDER_WATER_RIPPLE_TAG)
{
	{ _field_explanation, "TYPE FLAGS" },
	{ _field_long_flags, "flags" },
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
	{ _field_enum, "rise function" },
	{ _field_enum, "descend function" },
	{ _field_explanation, "PENDULUM SETTINGS" },
	{ _field_real, "phase revolution speed" },
	{ _field_real, "phase repeat along radius" },
	{ _field_explanation, "SHAPE TRANSITION" },
	{ _field_real, "pattern start idx" },
	{ _field_real, "pattern end idx" },
	{ _field_enum, "pattern transition" },
	{ _field_pad, "SexyPadding1", 2 },
	{ _field_explanation, "FOAM" },
	{ _field_real, "foam out radius" },
	{ _field_real, "foam fade distance" },
	{ _field_real, "foam duration" },
	{ _field_enum, "foam fade function" },
	{ _field_pad, "SexyPadding2", 2 },
	{ _field_terminator },
};

} // namespace blofeld

