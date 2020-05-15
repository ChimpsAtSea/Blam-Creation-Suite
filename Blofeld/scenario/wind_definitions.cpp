#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(wind, WIND_TAG)
{
	{ _field_explanation, "WIND DIRECTION" },
	{ _field_struct, "direction" },
	{ _field_struct, "speed" },
	{ _field_explanation, "DECORATOR WIND MOTION" },
	{ _field_struct, "bend" },
	{ _field_struct, "oscillation" },
	{ _field_struct, "frequency" },
	{ _field_real, "gust size:world units" },
	{ _field_tag_reference, "gust noise bitmap" },
	{ _field_terminator },
};

} // namespace blofeld

