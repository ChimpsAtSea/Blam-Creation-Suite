#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(cheap_light, CHEAP_LIGHT_TAG)
{
	{ _field_explanation, "Cheap Lights" },
	{ _field_char_enum, "function input" },
	{ _field_pad, "clblah", 3 },
	{ _field_explanation, "COLOR" },
	{ _field_struct, "color" },
	{ _field_struct, "intensity" },
	{ _field_explanation, "SIZE" },
	{ _field_struct, "Falloff End{radius}" },
	{ _field_real, "Falloff Begin Ratio:[0-1]#Ratio of falloff start to falloff end" },
	{ _field_real, "near fade distance{closeup fading distance}:world units" },
	{ _field_real, "far fade begin:world units" },
	{ _field_real, "far fade cutoff:world units" },
	{ _field_terminator },
};

} // namespace blofeld

